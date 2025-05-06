#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#include "lynx_ev_timer.h"

static timer_t timer_id;
static pthread_mutex_t mt_timer_service;
static uint32_t lynx_ev_timer_system_tick = 0;
struct lynx_ev_timer_queue_t lynx_ev_timer_queue;
struct lynx_ev_queue_t queue_timer;
static void lynx_ev_timer_handler(sigval_t)
{
	struct lynx_ev_timer_message_t *p_timer_node_temp = lynx_ev_timer_queue.p_tail;
	struct lynx_ev_timer_message_t *p_timer_node_remove = NULL;

	pthread_mutex_lock(&mt_timer_service);

	lynx_ev_timer_system_tick = lynx_ev_timer_system_tick + LYNX_EV_TIMER_UNIT;

	while(NULL != p_timer_node_temp)
	{
		p_timer_node_temp->p_header.counter = p_timer_node_temp->p_header.counter - LYNX_EV_TIMER_UNIT;

		if(p_timer_node_temp->p_header.counter <= 0)
		{
			lynx_ev_task_post_pure_message(LYNX_EV_TASK_TIMER_ID,p_timer_node_temp->p_header.destination_task_id,p_timer_node_temp->p_header.signal);
			if(TIMER_PERIODIC == p_timer_node_temp->p_header.timer_type )
			{
				/* timer periodic */
				p_timer_node_temp->p_header.counter = p_timer_node_temp->p_header.period;
			}
			else if(TIMER_ONE_SHOT == p_timer_node_temp->p_header.timer_type )
			{
				/* timer one-shot */
				p_timer_node_remove = p_timer_node_temp;
			}
		}
		else
		{
			/* do notthing*/
		}
		p_timer_node_temp = p_timer_node_temp->p_next;
		/* remove node */
		if(NULL != p_timer_node_remove)
		{
			lynx_ev_timer_remove(p_timer_node_remove->p_header.destination_task_id,p_timer_node_remove->p_header.signal);
			p_timer_node_remove = NULL;
		}
	}

	pthread_mutex_unlock(&mt_timer_service);
}
void *lynx_ev_timer_init(void*)
{
	/* configure timer queue */
	lynx_ev_timer_queue.p_tail = NULL;
	lynx_ev_timer_queue.p_header = NULL;

	/* configure timer */
	struct sigevent sev;
	struct itimerspec its;

	/* create the timer */
	sev.sigev_notify = SIGEV_THREAD;
	sev.sigev_value.sival_ptr = &timer_id;
	sev.sigev_notify_attributes	= NULL;
	sev.sigev_notify_function = lynx_ev_timer_handler;
	timer_create(CLOCK_REALTIME, &sev, &timer_id);

	/* start the timer */
	its.it_value.tv_sec = 0;
	its.it_value.tv_nsec = LYNX_EV_TIMER_UNIT * 1000000;
	its.it_interval.tv_sec = its.it_value.tv_sec;
	its.it_interval.tv_nsec = its.it_value.tv_nsec;
	timer_settime(timer_id, 0, &its, NULL);

    pthread_mutex_init(&mt_timer_service, NULL);
	LYNX_EV_TIMER_DBG("[TMR] init sucessfull\n");
    lynx_ev_task_wait_all_started();

	return NULL;
}
uint32_t lynx_ev_timer_set(uint32_t destination_task_id,uint32_t signal,lynx_ev_timer_type_t timer_type,uint32_t duty)
{
	if(duty < LYNX_EV_TIMER_UNIT)
	{
		LYNX_EV_TIMER_WRN("[TMR] duty config error");
		/* error setting */
		return LYNX_EV_NG;
	}
	pthread_mutex_lock(&mt_timer_service);
	struct lynx_ev_timer_message_t *p_timer_node_temp = lynx_ev_timer_queue.p_tail;
	struct lynx_ev_timer_message_t *p_timer_new = NULL;
	while(NULL != p_timer_node_temp)
	{
		if(p_timer_node_temp->p_header.destination_task_id == destination_task_id && p_timer_node_temp->p_header.signal == signal)
		{
			/* change duty cycle */
			p_timer_node_temp->p_header.counter = duty;
			pthread_mutex_unlock(&mt_timer_service);
			LYNX_EV_TIMER_WRN("[TMR] change duty cycle\n");
			return LYNX_EV_OK;
		}
		else
		{
			p_timer_node_temp = p_timer_node_temp->p_next;
		}
	}
	p_timer_new = (struct lynx_ev_timer_message_t *)malloc(sizeof(struct lynx_ev_timer_message_t));

	if(NULL == p_timer_new)
	{
		LYNX_EV_TIMER_WRN("[TMR] allocate fail\n");
		/* allocate fail */
		return LYNX_EV_NG;
	}
	p_timer_new->p_header.destination_task_id = destination_task_id;
	p_timer_new->p_header.signal = signal;
	p_timer_new->p_header.counter = duty;
	p_timer_new->p_header.timer_type = timer_type;
	switch(p_timer_new->p_header.timer_type)
	{
		case TIMER_ONE_SHOT:
			p_timer_new->p_header.period = 0;
			break;
		case TIMER_PERIODIC:
			p_timer_new->p_header.period = duty;
			break;
		default:
			/* do notthing */
			break;
	}
	if(NULL != lynx_ev_timer_queue.p_tail)
	{
		p_timer_new->p_next = lynx_ev_timer_queue.p_tail;
		p_timer_new->p_previous = NULL;

		lynx_ev_timer_queue.p_tail->p_previous = p_timer_new;
		lynx_ev_timer_queue.p_tail = p_timer_new;
	}
	else
	{
		/* queue is empty */
		p_timer_new->p_next = NULL;
		p_timer_new->p_previous = NULL;
		lynx_ev_timer_queue.p_tail = lynx_ev_timer_queue.p_header = p_timer_new;
	}
	pthread_mutex_unlock(&mt_timer_service);
	return LYNX_EV_OK;
}
uint32_t lynx_ev_timer_remove(uint32_t destination_task_id,uint32_t signal)
{
	struct lynx_ev_timer_message_t *p_timer_node_temp = lynx_ev_timer_queue.p_tail;

	while(NULL != p_timer_node_temp)
	{
		if(p_timer_node_temp->p_header.destination_task_id == destination_task_id && p_timer_node_temp->p_header.signal == signal)
		{
			/* remove timer node */

			/* last node */
			if(p_timer_node_temp->p_next == NULL && p_timer_node_temp->p_previous == NULL)
			{
				lynx_ev_timer_queue.p_tail = lynx_ev_timer_queue.p_header = NULL;
			}
			/* middle node */
			else if(p_timer_node_temp->p_next != NULL && p_timer_node_temp->p_previous != NULL)
			{
				p_timer_node_temp->p_next->p_previous = p_timer_node_temp->p_previous;
				p_timer_node_temp->p_previous->p_next = p_timer_node_temp->p_next;
			}
			/* tail node */
			else if(p_timer_node_temp->p_previous == NULL)
			{
				lynx_ev_timer_queue.p_tail = p_timer_node_temp->p_next;
				lynx_ev_timer_queue.p_tail->p_previous = NULL;
			}
			/* head node */
			else if(p_timer_node_temp->p_next == NULL)
			{
				lynx_ev_timer_queue.p_header =  p_timer_node_temp->p_previous;
				lynx_ev_timer_queue.p_header->p_next = NULL;
			}
			else
			{
				return LYNX_EV_NG;
			}
			free(p_timer_node_temp);
			return LYNX_EV_OK;
		}
		else
		{
			p_timer_node_temp = p_timer_node_temp->p_next;
		}
	}
	return LYNX_EV_OK;
}
uint32_t lynx_ev_timer_get_system_tick(void)
{
	return lynx_ev_timer_system_tick;
}
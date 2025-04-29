#include "lynx_ev_timer.h"
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/time.h>
#define LYNX_EV_TIMER_UNIT 100 /* 100MS */

static timer_t timer_id;
static pthread_mutex_t mt_timer_service;
static struct lynx_ev_timer_queue_t lynx_ev_timer_queue;

static void timer_handler(void)
{

}
void lynx_ev_timer_init(void)
{
	/* configure timer */
	struct sigevent sev;
	struct itimerspec its;

	/* create the timer */
	sev.sigev_notify = SIGEV_THREAD;
	sev.sigev_value.sival_ptr = &timer_id;
	sev.sigev_notify_attributes	= NULL;
	sev.sigev_notify_function = timer_handler;
	timer_create(CLOCK_REALTIME, &sev, &timer_id);

	/* start the timer */
	its.it_value.tv_sec = 0;
	its.it_value.tv_nsec = LYNX_EV_TIMER_UNIT * 1000000;
	its.it_interval.tv_sec = its.it_value.tv_sec;
	its.it_interval.tv_nsec = its.it_value.tv_nsec;
	timer_settime(timer_id, 0, &its, NULL);

    pthread_mutex_init(&mt_timer_service, NULL);


}

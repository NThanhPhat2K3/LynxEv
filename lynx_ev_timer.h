#ifndef __LYNX_EV_TIMER__
#define __LYNX_EV_TIMER__ 
#include "message.h"

typedef enum {
	TIMER_ONE_SHOT,
	TIMER_PERIODIC
} lynx_ev_timer_type_t;

struct lynx_ev_timer_data_t
{
    uint32_t destination_task_id;
    uint32_t signal;

    lynx_ev_timer_message_t period;
    uint32_t counter;
};

struct lynx_ev_timer_message_t
{
    struct lynx_ev_timer_data_t    *p_header;
    struct lynx_ev_timer_message_t *p_next;
    struct lynx_ev_timer_message_t *p_previous;
};

struct lynx_ev_timer_queue_t
{
    uint32_t length;
    pthread_mutex_t mutex;
    struct lynx_ev_timer_message_t *p_tail;
    struct lynx_ev_timer_message_t *p_header;
};


extern void lynx_ev_timer_init(void);
#endif
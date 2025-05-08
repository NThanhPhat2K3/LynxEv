#ifndef __LYNX_EV_TIMER__
#define __LYNX_EV_TIMER__ 

#include "lynx_ev_message.h"
#include "lynx_ev_app_task_list.h"
#include "lynx_ev_task.h"
#include "lynx_ev_debug.h"

#define LYNX_EV_TIMER_UNIT  (10U) /* 10ms */
#define LYNX_EV_OK          (0x00)
#define LYNX_EV_NG          (0x01)

typedef enum 
{
	TIMER_ONE_SHOT,
	TIMER_PERIODIC
} lynx_ev_timer_type_t;

struct lynx_ev_timer_data_t
{
    lynx_ev_timer_type_t timer_type;
    uint32_t destination_task_id;
    uint32_t signal;
    uint32_t period;
    uint32_t counter;
};

struct lynx_ev_timer_message_t
{
    struct lynx_ev_timer_data_t    p_header;
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


extern void *lynx_ev_timer_init(void*);
extern uint32_t lynx_ev_timer_set(uint32_t destination_task_id,uint32_t signal,lynx_ev_timer_type_t timer_type,uint32_t duty);
extern uint32_t lynx_ev_timer_remove(uint32_t destination_task_id,uint32_t signal);
extern uint32_t lynx_ev_timer_get_system_tick(void);

extern struct lynx_ev_queue_t queue_timer;
#endif
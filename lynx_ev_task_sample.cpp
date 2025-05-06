#include "lynx_ev_task_sample.h"
struct lynx_ev_queue_t queue_task_sample;
void *task_sample(void*)
{
    lynx_ev_task_wait_all_started();
    struct lynx_ev_message_t *message = NULL;
    lynx_ev_timer_set(LYNX_EV_TASK_TIMER_ID,1,TIMER_PERIODIC,1000);
    while(1)
    {
        message = lynx_ev_task_receive_message(LYNX_EV_TASK_TIMER_ID);

        if(message != NULL )
        {
            printf("hello world\n");
        }

    }
    return NULL;
}
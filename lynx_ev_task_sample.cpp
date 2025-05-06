#include "lynx_ev_task_sample.h"

struct lynx_ev_queue_t queue_task_sample;
void *task_sample(void*)
{
    lynx_ev_task_wait_all_started();
    struct lynx_ev_message_t *message = NULL;
    lynx_ev_timer_set(LYNX_EV_TASK_SAMPLE_ID,SIGNAL_TIMER_1000_MS,TIMER_PERIODIC,LYNX_APP_TASK_SAMPLE_DEFINE_TIMER_1000_MS);
    lynx_ev_timer_set(LYNX_EV_TASK_SAMPLE_ID,SIGNAL_TIMER_150_MS,TIMER_PERIODIC,LYNX_APP_TASK_SAMPLE_DEFINE_TIMER_150_MS);
    while(1)
    {
        /* get message*/
        message = lynx_ev_task_receive_message(LYNX_EV_TASK_SAMPLE_ID);
        switch(message->p_header->signal)
        {
            case SIGNAL_TIMER_1000_MS:
                APP_PRINT("This is 1000 ms cyclic\n");
                break;
            case SIGNAL_TIMER_150_MS:
                APP_PRINT("This is 150 ms cyclic\n");
                break;
            case SIGNAL_MESSAGE_COMMING:
                APP_PRINT("Message comming\n");
                break;
            default:
                /* do notthing */
                break;
        }
        lynx_ev_task_message_free(message);


    }
    return NULL;
}
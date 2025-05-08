#include "lynx_ev_app_task_sample.h"

struct lynx_ev_queue_t queue_task_sample;
void *task_sample(void*)
{
    lynx_ev_task_wait_all_started();
    struct lynx_ev_message_t *message = NULL;
    lynx_ev_timer_set(LYNX_EV_TASK_SAMPLE_ID,APP_TASK_SAMPLE_SIG_TIMER_1000_MS,TIMER_PERIODIC,APP_TASK_SAMPLE_TIMER_1000_MS);
    while(1)
    {
        /* get message*/
        message = lynx_ev_task_receive_message(LYNX_EV_TASK_SAMPLE_ID);
        switch(message->p_header->signal)
        {
            case APP_TASK_SAMPLE_SIG_TIMER_1000_MS:
                APP_PRINT("This is 1000 ms cyclic\n");
                break;
            case APP_TASK_SAMPLE_SIG_TIMER_150_MS:
                APP_PRINT("This is 150 ms cyclic\n");
                break;
            case APP_TASK_SAMPLE_SIG_MESSAGE_COMING:
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
#include "lynx_ev_app_task_send_sample.h"
struct lynx_ev_queue_t queue_task_send_sample;


void *task_send_sample(void*)
{
    lynx_ev_task_wait_all_started();

    lynx_ev_task_post_pure_message(LYNX_EV_TASK_SEND_SAMPLE_ID,LYNX_EV_TASK_SAMPLE_ID,APP_TASK_SAMPLE_SIG_MESSAGE_COMING);
    while(1)
    {

    }
    return NULL;
}
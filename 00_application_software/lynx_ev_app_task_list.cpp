#include "lynx_ev_app_task_list.h"

struct lynx_task_t lynx_task_list[] = 
{
    /* ------------------------------- task list configuration ------------------------------- */
    
    /* ---------------------------------|-----------------------|----------------------------|---------------------------*/
    /* task id                          | task function         | mailbox                    | task name                 */
    /* ---------------------------------|-----------------------|----------------------------|---------------------------*/
    { LYNX_EV_TASK_TIMER_ID,            lynx_ev_timer_init,     &queue_timer,               "lynx_ev_task_timer"        },
    { LYNX_EV_TASK_SAMPLE_ID,           task_sample,            &queue_task_sample,         "lynx_ev_task_sample"       },
    { LYNX_EV_TASK_SEND_SAMPLE_ID,      task_send_sample,       &queue_task_send_sample,    "lynx_ev_task_send_sample"  },
    { LYNX_EV_END_OF_TASK_ID,           NULL,                   NULL,                       NULL                        }
};

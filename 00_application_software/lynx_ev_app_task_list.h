#ifndef __LYNX_EV_TASK_LIST_H__
#define __LYNX_EV_TASK_LIST_H__

#include <stdint.h>
#include "lynx_ev_message.h"
#include "lynx_ev_timer.h"
#include "lynx_ev_task.h"

#include "lynx_ev_app_task_sample.h"
#include "lynx_ev_app_task_send_sample.h"

enum lynx_ev_task_list 
{
    /* timer service */
    LYNX_EV_TASK_TIMER_ID,
    
    /* app task */
    LYNX_EV_TASK_SAMPLE_ID,
    LYNX_EV_TASK_SEND_SAMPLE_ID,

    /* end of task list */
    LYNX_EV_END_OF_TASK_ID
};


extern struct lynx_task_t lynx_task_list[];

#endif
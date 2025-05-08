#ifndef __LYNX_EV_APP_H__
#define __LYNX_EV_APP_H__

#include <stdint.h>

#define LYNX_USER_DEFINE_SIG				(10U)

/******************************************************************************
 *  task: app_task_sample
 *  description: timers and signals for app_task_sample
 ******************************************************************************/

/* timer definitions */
#define APP_TASK_SAMPLE_TIMER_1000_MS          (1000U)
#define APP_TASK_SAMPLE_TIMER_150_MS           (150U)

/* signal definitions */
enum {
    APP_TASK_SAMPLE_SIG_TIMER_1000_MS = LYNX_USER_DEFINE_SIG,
    APP_TASK_SAMPLE_SIG_TIMER_150_MS,
    APP_TASK_SAMPLE_SIG_MESSAGE_COMING
};



#endif
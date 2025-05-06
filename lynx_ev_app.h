#ifndef __LYNX_EV_APP_H__
#define __LYNX_EV_APP_H__

#include <stdint.h>

#define LYNX_USER_DEFINE_SIG				(10U)

/*****************************************************************************/
/*  task task_sample define.
 */
/*****************************************************************************/
/* define timer */
#define LYNX_APP_TASK_SAMPLE_DEFINE_TIMER_1000_MS		(1000U)
#define LYNX_APP_TASK_SAMPLE_DEFINE_TIMER_150_MS		(150U)


/* define signal */
enum {
	SIGNAL_TIMER_1000_MS = LYNX_USER_DEFINE_SIG,
    SIGNAL_TIMER_150_MS,
    SIGNAL_MESSAGE_COMMING
};

/*****************************************************************************/
/*  task task_send_sample define.
 */
/*****************************************************************************/
// /* define timer */
// #define LYNX_APP_TASK_SAMPLE_DEFINE_TIMER_1000_MS		(1000U)

// /* define signal */
// enum {
// 	SIGNAL_TIMER_1000_MS = LYNX_USER_DEFINE_SIG,
//     SIGNAL_TIMER_150_MS
// };


#endif
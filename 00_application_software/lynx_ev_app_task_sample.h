#ifndef __LYNX_EV_TASK_SAMPLE_H__
#define __LYNX_EV_TASK_SAMPLE_H__
#include <stdio.h>
#include <stdint.h>

#include "lynx_ev_message.h"
#include "lynx_ev_timer.h"
#include "lynx_ev_task.h"
#include "lynx_ev_app.h"
#include "lynx_ev_app_debug.h"

extern void *task_sample(void*);
extern struct lynx_ev_queue_t queue_task_sample;

#endif
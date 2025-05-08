#ifndef __AK_DBG_H__
#define __AK_DBG_H__

#include <stdio.h>
#include "system_debug.h"

#define LYNX_EV_MSG_DBG(fmt, ...)		__LOG__(fmt, "MSG", ##__VA_ARGS__)
#define LYNX_EV_MSG_WRN(fmt, ...)		__LOG__(fmt, "MSG_WRN", ##__VA_ARGS__)
#define LYNX_EV_TIMER_DBG(fmt, ...)		__LOG__(fmt, "TIMER", ##__VA_ARGS__)
#define LYNX_EV_TIMER_WRN(fmt, ...)		__LOG__(fmt, "TIMER_WRN", ##__VA_ARGS__)
#define LYNX_EV_PRINT(fmt, ...)		    __LOG__(fmt, "LYNX_EV_PRINT", ##__VA_ARGS__)

#endif //__AK_DBG_H__

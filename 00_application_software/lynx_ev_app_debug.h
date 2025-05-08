#ifndef __APP_DBG_H__
#define __APP_DBG_H__

#include <stdio.h>
#include "system_debug.h"

#define APP_PRINT(fmt, ...)		__LOG__(fmt,"",##__VA_ARGS__)
#define APP_DBG(fmt, ...)		__LOG__(fmt, "APP_DBG", ##__VA_ARGS__)
#define APP_DBG_SIG(fmt, ...)	__LOG__(fmt, "SIG -> ", ##__VA_ARGS__)


#endif //__APP_DBG_H__

#ifndef __AK_SYS_DBG_H__
#define __AK_SYS_DBG_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define __SHORT_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define __LOG__(fmt, loglevel, ...) \
    printf("%s%s %s%s %s%s:%d %s" fmt, KBLU, sys_dbg_get_time(), KYEL, loglevel, KGRN, __SHORT_FILE__, __LINE__, KNRM, ## __VA_ARGS__)
#define SYS_PRINT(fmt, ...)		__LOG__(fmt, "SYS_PRINT", ##__VA_ARGS__)
#define SYS_DBG(fmt, ...)		__LOG__(fmt, "SYS_DBG", ##__VA_ARGS__)
#define RAW_DBG(fmt, ...)		printf(fmt, ##__VA_ARGS__)
#define FATAL(s, c) sys_dbg_fatal((const char*)s, (uint8_t)c)

extern void sys_dbg_fatal(const char* s, uint8_t c);
extern char* sys_dbg_get_time(void);

#endif //__AK_SYS_DBG_H__

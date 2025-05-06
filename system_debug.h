#ifndef __SYSTEM_DEBUG_H__
#define __SYSTEM_DEBUG_H__

#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Enable file logging */
// #define EN_LOG_FILE 

/* Color definitions for terminal output */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

/* Extract short file name from full path */
#define __SHORT_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

/* Log macro with both console and file logging */
#define __LOG__(fmt, loglevel, ...) \
    do { \
        printf("%s%s %s%s %s%s:%d %s" fmt, KBLU, sys_dbg_get_time(), KYEL, loglevel, KGRN, __SHORT_FILE__, __LINE__, KNRM, ##__VA_ARGS__); \
        /* Write to log file if enabled */ \
        /* Pass file name and line number */ \
        /* Using macro arguments, not inside log_to_file */ \
        /* So it reflects the caller’s location */ \
        /* Not the log_to_file’s own location */ \
        /* This ensures meaningful file:line in logs */ \
        #ifdef EN_LOG_FILE \
        log_to_file(__SHORT_FILE__, __LINE__, fmt, loglevel, ##__VA_ARGS__); \
        #endif \
    } while(0)

/* Public macros for logging */
#define SYS_PRINT(fmt, ...)     __LOG__(fmt, "SYS_PRINT", ##__VA_ARGS__)
#define SYS_DBG(fmt, ...)       __LOG__(fmt, "SYS_DBG", ##__VA_ARGS__)
#define RAW_DBG(fmt, ...)       printf(fmt, ##__VA_ARGS__)
#define FATAL(s, c)             sys_dbg_fatal((const char*)s, (uint8_t)c)

/* Function declarations */
extern void sys_dbg_fatal(const char* s, uint8_t c);
extern char* sys_dbg_get_time(void);
extern void log_to_file(const char *file, int line, const char *fmt, const char *loglevel, ...);

#endif // __SYSTEM_DEBUG_H__

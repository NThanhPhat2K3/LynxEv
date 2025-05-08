#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "system_debug.h"

/* Ensure the log/ directory exists, create if not */
void ensure_log_directory_exists(void) {
    struct stat st = {0};
    if (stat("./99_log", &st) == -1) {
        mkdir("./99_log", 0700);  
    }
}

/* Write log message to file with timestamp, loglevel, file and line */
void log_to_file(const char *file, int line, const char *fmt, const char *loglevel, ...) {
    ensure_log_directory_exists();

    char filename[128];
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    /* Generate filename like ./log/log_dd_mm_yyyy.txt */
    strftime(filename, sizeof(filename), "./99_log/log_%d_%m_%Y.txt", timeinfo);
    FILE *logfile = fopen(filename, "a");
    if (logfile == NULL) {
        perror("Error opening log file");
        return;
    }

    /* Format current timestamp */
    char time_str[64];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo);

    /* Write timestamp, loglevel, file, line number */
    fprintf(logfile, "%s %s %s:%d ", time_str, loglevel, file, line);

    /* Handle formatted log message */
    va_list args;
    va_start(args, loglevel);
    vfprintf(logfile, fmt, args);
    va_end(args);

    fprintf(logfile, "\n");
    fclose(logfile); 
}

/* Fatal error handler: print and exit */
void sys_dbg_fatal(const char* s, uint8_t c) {
    printf("[SYS_UNIX] FATAL: %s \t 0x%02X\n", s, c);
    exit(EXIT_FAILURE);
}

/* Get current time as string */
char* sys_dbg_get_time(void) {
    time_t rawtime;
    struct tm* timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    static char return_val[64];
    strftime(return_val, sizeof(return_val), "%Y-%m-%d %H:%M:%S", timeinfo);

    return return_val;
}

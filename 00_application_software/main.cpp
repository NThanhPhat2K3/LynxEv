#include "stdio.h"
#include "string.h"
#include <stdlib.h>      
#include <cstdlib>
#include "lynx_ev_message.h"
#include "system_debug.h"
#include "lynx_ev_debug.h"
#include "lynx_ev_app_debug.h"
#include "lynx_ev_task.h"
#include "lynx_ev_timer.h"

int main()
{
    /* init task */
    lynx_ev_task_init();
    return 0;
}
#include <stdint.h>
#include "lynx_ev_message.h"



typedef void* (*lynx_task)(void*);
struct lynx_task_t
{
    uint32_t id;

    lynx_task task;

    lynx_ev_queue_t *mailbox;
    const char* info_task;

    /* private attribute */
	pthread_t		pthread;
	pthread_cond_t	mailbox_cond;
	uint32_t		mailbox_len;
}

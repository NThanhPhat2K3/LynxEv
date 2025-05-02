#include <stdint.h>
#include <pthread.h>
#include "lynx_ev_message.h"
#include "lynx_ev_task.h"



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
    pthread_mutex_t	mt_mailbox_cond;

}

extern void lynx_ev_set_message_signal(struct lynx_ev_message_t *p_message, uint32_t signal);
extern void lynx_ev_set_message_source_task_id(struct lynx_ev_message_t *p_message, uint32_t source_task_id);

extern void lynx_ev_set_message_data_common(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght);
extern void lynx_ev_get_message_data_common(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght);

extern void lynx_ev_set_message_data_dynamic(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght);
extern void lynx_ev_get_message_data_dynamic(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght);


extern struct lynx_ev_message_t *lynx_ev_get_pure_message(void);
extern struct lynx_ev_message_t *lynx_ev_get_common_message(void);
extern struct lynx_ev_message_t *lynx_ev_get_dynamic_message(void);


extern uint32_t lynx_ev_get_message_type(struct lynx_ev_message_t *p_message);
    
extern void lynx_ev_task_post_message(uint32_t destination_task_id,struct lynx_ev_message_t *p_message);

extern void lynx_ev_task_post_pure_message(uint32_t source_task_id,uint32_t destination_task_id,uint32_t signal);
extern void lynx_ev_task_post_common_message(uint32_t source_task_id,uint32_t destination_task_id,uint32_t signal,uint8_t *p_data, uint32_t lenght);
extern void lynx_ev_task_post_dynamic_message(uint32_t source_task_id,uint32_t destination_task_id,uint32_t signal,uint8_t *p_data, uint32_t lenght);

extern struct lynx_ev_message_t *lynx_ev_memcpy_message(struct lynx_ev_message_t *p_source_message);

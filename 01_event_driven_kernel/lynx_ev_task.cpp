#include "lynx_ev_task.h"

static pthread_mutex_t lynx_ev_mutex_started;
static uint32_t lynx_ev_task_started = 0;


uint32_t lynx_ev_get_message_type(struct lynx_ev_message_t *p_message)
{
    uint32_t ret = 0;
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header)
        {
            ret = p_message->p_header->message_type;
            return ret;
        }
        else
        {
            ret = -1;
            /* do notthing */
        }
    }
    else
    {
        ret = -1;
        /* do notthing */
    }
    return ret;
}
struct lynx_ev_message_t *lynx_ev_get_pure_message(void)
{
    struct lynx_ev_message_t *p_ret_pure_message = NULL;
    p_ret_pure_message = (struct lynx_ev_message_t*)malloc(sizeof(struct lynx_ev_message_t));
    if(NULL == p_ret_pure_message)
    {
        /* cannot allocate pure message */
        return NULL;
    }
    p_ret_pure_message->p_header = (struct lynx_ev_header_t*)malloc(sizeof(struct lynx_ev_header_t));
    if(NULL == p_ret_pure_message->p_header)
    {
        free(p_ret_pure_message);
        /* cannot allocate header */
        return NULL;
    }
    p_ret_pure_message->p_header->message_type = PURE_MSG_TYPE;
    p_ret_pure_message->p_header->length = LYNX_EV_EMPTY_LEN;
    p_ret_pure_message->p_header->p_payload = NULL;

    return p_ret_pure_message;
}

struct lynx_ev_message_t *lynx_ev_get_common_message(void)
{
    struct lynx_ev_message_t *p_ret_common_message = NULL;
    p_ret_common_message = (struct lynx_ev_message_t*)malloc(sizeof(struct lynx_ev_message_t));
    if(NULL == p_ret_common_message)
    {
        /* cannot allocate common message */
        return NULL;
    }
    p_ret_common_message->p_header = (struct lynx_ev_header_t*)malloc(sizeof(struct lynx_ev_header_t));
    if(NULL == p_ret_common_message->p_header)
    {
        /* cannot allocate common message */
        return NULL;
    }
    p_ret_common_message->p_header->message_type = COMMON_MSG_TYPE;
    p_ret_common_message->p_header->length = LYNX_EV_EMPTY_LEN;
    p_ret_common_message->p_header->p_payload = NULL;

    return p_ret_common_message;

}

extern struct lynx_ev_message_t *lynx_ev_get_dynamic_message(void)
{
    struct lynx_ev_message_t *p_ret_dynamic_message = NULL;
    p_ret_dynamic_message = (struct lynx_ev_message_t*)malloc(sizeof(struct lynx_ev_message_t));
    if(NULL == p_ret_dynamic_message)
    {
        /* cannot allocate dynamic message */
        return NULL;
    }
    p_ret_dynamic_message->p_header = (struct lynx_ev_header_t*)malloc(sizeof(struct lynx_ev_header_t));
    if(NULL == p_ret_dynamic_message->p_header)
    {
        /* cannot allocate dynamic message */
        return NULL;
    }
    p_ret_dynamic_message->p_header->message_type = DYNAMIC_MSG_TYPE;
    p_ret_dynamic_message->p_header->length = LYNX_EV_EMPTY_LEN;
    p_ret_dynamic_message->p_header->p_payload = NULL;

    return p_ret_dynamic_message;
}

void lynx_ev_set_message_signal(struct lynx_ev_message_t *p_message, uint32_t signal)
{
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header)
        {
            p_message->p_header->signal = signal;
        }
        else
        {
            /* do nothing */
            return;
        }

    }
    else
    {
        /* do nothing */
    }
    return;
}
extern void lynx_ev_set_message_source_task_id(struct lynx_ev_message_t *p_message, uint32_t source_task_id)
{
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header)
        {
            p_message->p_header->source_task_id = source_task_id;
        }
        else
        {
            /* do nothing */
            return;
        }
    }
    else
    {
        /* do nothing */
        return;
    }
}

void lynx_ev_set_message_data_common(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght)
{
    if(NULL == p_data)
    {
        /* do notthing */
        return;
    }
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header && COMMON_MSG_TYPE == p_message->p_header->message_type)
        {
            if(lenght > LYNX_EV_COMMON_MSG_DATA_SIZE)
            {
                /* lenght over size for common message */
                return;
            }
            else if(lenght == 0)
            {
                /* No allocate */
                return;
            }
            else
            {
                p_message->p_header->length = lenght;
                if(NULL != p_message->p_header->p_payload)
                {
                    free(p_message->p_header->p_payload);
                    p_message->p_header->p_payload = NULL;
                }
                p_message->p_header->p_payload = (uint8_t*)malloc(sizeof(uint8_t) * p_message->p_header->length);
                if(NULL == p_message->p_header->p_payload)
                {
                    return;
                }
                memcpy((uint8_t*)p_message->p_header->p_payload,p_data,lenght);
            }
        }
        else
        {
            /* do nothing */
            return;
        }
    }
    else
    {
        /* do nothing */
        return;
    }
}
void lynx_ev_set_message_data_dynamic(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght)
{
    if(NULL == p_data)
    {
        /* do notthing */
        return;
    }
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header && DYNAMIC_MSG_TYPE == p_message->p_header->message_type)
        {
            if(lenght == 0)
            {
                /* No allocate */
                return;
            }
            else
            {
                p_message->p_header->length = lenght;
                if(NULL != p_message->p_header->p_payload)
                {
                    free(p_message->p_header->p_payload);
                    p_message->p_header->p_payload = NULL;
                }
                p_message->p_header->p_payload = (uint8_t*)malloc(sizeof(uint8_t) * p_message->p_header->length);
                if(NULL == p_message->p_header->p_payload)
                {
                    return;
                }
                memcpy((uint8_t*)p_message->p_header->p_payload,p_data,lenght);
            }
        }
        else
        {
            /* do nothing */
            return;
        }
    }
    else
    {
        /* do nothing */
        return;
    }
}
void lynx_ev_get_message_data_common(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght)
{
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header && COMMON_MSG_TYPE == p_message->p_header->message_type)
        {
            if(NULL != p_message->p_header->p_payload)
            {
                memcpy(p_data,(uint8_t*)p_message->p_header->p_payload, p_message->p_header->length);
            }
            else
            {
                /* empty data */
                return;
            }
        }
        else
        {
            /* empty header */
            return;
        }
    }
    else
    {
        /* empty message*/
        return;
    }
}
void lynx_ev_get_message_data_dynamic(struct lynx_ev_message_t *p_message,uint8_t *p_data, uint32_t lenght)
{
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header && DYNAMIC_MSG_TYPE == p_message->p_header->message_type)
        {
            if(NULL != p_message->p_header->p_payload)
            {
                memcpy(p_data,(uint8_t*)p_message->p_header->p_payload, p_message->p_header->length);
            }
            else
            {
                /* empty data */
                return;
            }
        }
        else
        {
            /* empty header */
            return;
        }
    }
    else
    {
        /* empty message*/
        return;
    }
}
void lynx_ev_task_post_message(uint32_t destination_task_id,struct lynx_ev_message_t *p_message)
{
    if(destination_task_id >= LYNX_EV_END_OF_TASK_ID)
    {
        return;
    }
    
    if(p_message != NULL)
    {
        pthread_mutex_lock(&lynx_task_list[destination_task_id].mt_mailbox_cond);

        struct lynx_ev_queue_t *p_queue_message = lynx_task_list[destination_task_id].mailbox;
        lynx_ev_queue_put(p_queue_message,p_message);

        pthread_cond_signal(&(lynx_task_list[destination_task_id].mailbox_cond));

        pthread_mutex_unlock(&lynx_task_list[destination_task_id].mt_mailbox_cond);

    }
    else
    {
        /* do nothing*/
    }
    
}

void lynx_ev_task_post_pure_message(uint32_t source_task_id,uint32_t destination_task_id,uint32_t signal)
{
    struct lynx_ev_message_t *p_message = NULL;
    p_message = lynx_ev_get_pure_message();
    if(NULL == p_message)
    {
        /* allocate pure message fail */
        return;
    }
    lynx_ev_set_message_signal(p_message,signal);
    lynx_ev_set_message_source_task_id(p_message,source_task_id);
    lynx_ev_task_post_message(destination_task_id,p_message);
}
void lynx_ev_task_post_common_message(uint32_t source_task_id,uint32_t destination_task_id,uint32_t signal,uint8_t *p_data, uint32_t lenght)
{
    struct lynx_ev_message_t *p_message = NULL;
    p_message = lynx_ev_get_common_message();
    if(NULL == p_message)
    {
        /* allocate common message fail */
        return;
    }
    lynx_ev_set_message_signal(p_message,signal);
    lynx_ev_set_message_source_task_id(p_message,source_task_id);
    if(p_data == NULL || lenght == 0)
    {
        return;
    }
    lynx_ev_set_message_data_common(p_message,p_data,lenght);
    lynx_ev_task_post_message(destination_task_id,p_message);
}
void lynx_ev_task_post_dynamic_message(uint32_t source_task_id,uint32_t destination_task_id,uint32_t signal,uint8_t *p_data, uint32_t lenght)
{
    struct lynx_ev_message_t *p_message = NULL;
    p_message = lynx_ev_get_dynamic_message();
    if(NULL == p_message)
    {
        /* allocate dynamic message fail */
        return;
    }
    lynx_ev_set_message_signal(p_message,signal);
    lynx_ev_set_message_source_task_id(p_message,source_task_id);
    if(p_data == NULL || lenght == 0)
    {
        return;
    }
    lynx_ev_set_message_data_dynamic(p_message,p_data,lenght);
    lynx_ev_task_post_message(destination_task_id,p_message); 
}

struct lynx_ev_message_t *lynx_ev_memcpy_message(struct lynx_ev_message_t *p_source_message)
{
    struct lynx_ev_message_t *p_ret_message = NULL;
    uint32_t message_type = 0;
    message_type = lynx_ev_get_message_type(p_source_message);

    switch(message_type)
    {
        case PURE_MSG_TYPE:
            p_ret_message = lynx_ev_get_pure_message();
            memcpy(p_ret_message->p_header,p_source_message->p_header,sizeof(struct lynx_ev_header_t));
            break;
        case COMMON_MSG_TYPE:
            p_ret_message = lynx_ev_get_common_message();
            memcpy(p_ret_message->p_header,p_source_message->p_header,sizeof(struct lynx_ev_header_t));
            lynx_ev_set_message_data_common(p_ret_message,(uint8_t *)p_source_message->p_header->p_payload,p_source_message->p_header->length);
            break;
        case DYNAMIC_MSG_TYPE:
            p_ret_message = lynx_ev_get_dynamic_message();
            memcpy(p_ret_message,p_source_message->p_header,sizeof(struct lynx_ev_header_t));
            lynx_ev_set_message_data_dynamic(p_ret_message,(uint8_t *) p_source_message->p_header->p_payload,p_source_message->p_header->length);
            break;
        default:
            /* do notthing */
            break;

    }
    return p_ret_message;
}
void lynx_ev_task_message_free(struct lynx_ev_message_t *p_message)
{
    if(p_message != NULL)
    {
        lynx_ev_message_free(p_message);
    }
    else
    {
        /* do notthing */
        return;
    }
}
struct lynx_ev_message_t *lynx_ev_task_receive_message(uint32_t destination_task_id)
{
    struct lynx_ev_message_t *p_return_message = NULL;

    if(destination_task_id >= LYNX_EV_END_OF_TASK_ID)
    {
        /* do notthing */
        return NULL;
    }
    pthread_mutex_lock(&(lynx_task_list[destination_task_id].mt_mailbox_cond));

    struct lynx_ev_queue_t *p_queue_message = lynx_task_list[destination_task_id].mailbox;

    if(LYNX_EV_EMPTY_LEN == lynx_ev_queue_is_empty(p_queue_message))
    {
        pthread_cond_wait(&(lynx_task_list[destination_task_id].mailbox_cond), &(lynx_task_list[destination_task_id].mt_mailbox_cond));
    }

    if(LYNX_EV_AVAILABLE_LEN == lynx_ev_queue_available(p_queue_message))
    {
        p_return_message = lynx_ev_queue_get(p_queue_message);
    }
    pthread_mutex_unlock(&(lynx_task_list[destination_task_id].mt_mailbox_cond));
    return p_return_message;
}
void lynx_ev_task_init(void)
{
    uint32_t index = 0;
    pthread_mutex_init(&lynx_ev_mutex_started, NULL);
    /* create mailbox, mutex, condition variable */
    for (index = 0; index < LYNX_EV_END_OF_TASK_ID; index++) 
    {
        lynx_ev_queue_init(lynx_task_list[index].mailbox);
        pthread_mutex_init(&lynx_task_list[index].mt_mailbox_cond, NULL);
        pthread_cond_init(&lynx_task_list[index].mailbox_cond, NULL);
    }
    /* create task */
    for (index = 0; index < LYNX_EV_END_OF_TASK_ID; index++) 
    {
        pthread_create(&lynx_task_list[index].pthread, NULL, lynx_task_list[index].task, NULL);
    }
    for (index = 0; index < LYNX_EV_END_OF_TASK_ID; index++) 
    {
        pthread_join(lynx_task_list[index].pthread, NULL);
    }
}
void lynx_ev_task_wait_all_started(void)
{
    uint8_t check_return = 1;
	pthread_mutex_lock(&lynx_ev_mutex_started);
    lynx_ev_task_started = lynx_ev_task_started + 1;
    pthread_mutex_unlock(&lynx_ev_mutex_started);

    while(check_return)
    {
        pthread_mutex_lock(&lynx_ev_mutex_started);
        if(lynx_ev_task_started < LYNX_EV_END_OF_TASK_ID)
        {
            check_return = 1;
        }
        else
        {
            check_return = 0;
        }
        pthread_mutex_unlock(&lynx_ev_mutex_started);
        usleep(100);
    }
}
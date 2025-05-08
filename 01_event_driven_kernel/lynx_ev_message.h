/**
 ******************************************************************************
 * @file      lynx_ev_message.h
 * @author    GhostZilla
 * @version   1.0
 * @date      2025-04-21
 * @brief     event message queue system
 *
 * @details
 * This file declares the data structures and functions for a thread-safe
 * event message queue system. The system enables enqueueing and dequeueing
 * of messages using a double-linked list, and is suitable for inter-thread
 * communication in embedded or multitasking environments.
 *
 ******************************************************************************
 */

#ifndef __LYNX_EV_MESSAGE_H__
#define __LYNX_EV_MESSAGE_H__

#include <cstdlib>  // để dùng free
#include <stdint.h>
#include <pthread.h>

#include "lynx_ev_debug.h"

#define LYNX_EV_EMPTY_LEN       (0U)
#define LYNX_EV_AVAILABLE_LEN   (1U)

#define DYNAMIC_MSG_TYPE        (0x40)
#define PURE_MSG_TYPE           (0x80)
#define COMMON_MSG_TYPE         (0xC0)

#define LYNX_EV_COMMON_MSG_DATA_SIZE (64U)

/* event message header structure */
struct lynx_ev_header_t
{
    /* message type */
    uint32_t    message_type;

    /* information */
    uint32_t    signal;
    uint32_t    source_task_id;
    uint32_t    destination_task_id;

    /* data */
    uint32_t    length;
    void        *p_payload;
};

/* message node */
struct lynx_ev_message_t 
{
    struct lynx_ev_message_t    *p_next;
    struct lynx_ev_header_t     *p_header;
    struct lynx_ev_message_t    *p_previous;
};

/* queue for managing messages */
struct lynx_ev_queue_t
{
    uint32_t length;
    pthread_mutex_t mutex;
    struct lynx_ev_message_t *p_head;
    struct lynx_ev_message_t *p_tail;
};

/* function declarations */
extern void                       lynx_ev_queue_init(struct lynx_ev_queue_t *p_queue);

extern struct lynx_ev_message_t*  lynx_ev_queue_get(struct lynx_ev_queue_t *p_queue);
extern uint32_t                   lynx_ev_queue_length(struct lynx_ev_queue_t *p_queue);
extern uint32_t                   lynx_ev_queue_available(struct lynx_ev_queue_t *p_queue);
extern void                       lynx_ev_queue_put(struct lynx_ev_queue_t *p_queue, struct lynx_ev_message_t *p_message);
extern uint32_t                   lynx_ev_queue_is_empty(struct lynx_ev_queue_t *p_queue);


extern void                       lynx_ev_message_free(struct lynx_ev_message_t *p_message);

#endif  /* __LYNX_EV_MESSAGE_H__ */
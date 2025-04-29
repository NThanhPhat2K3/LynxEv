/**
 ******************************************************************************
 * @file      lynx_ev_message.cpp
 * @author    GhostZilla
 * @version   1.0
 * @date      2025-04-21
 * @brief     Implementation of Event Message Queue System
 *
 * @details
 * This file contains the function implementations for the event message queue.
 * It uses a double-linked list with thread-safe operations to manage
 * message buffers, designed for use in multi-threaded or embedded environments.
 *
 ******************************************************************************
 */
#include "lynx_ev_message.h"

/**
 * @brief initialize the event queue structure.
 *
 * @param p_queue pointer to the event queue structure to initialize.
 */
void lynx_ev_queue_init(struct lynx_ev_queue_t *p_queue)
{
    p_queue->p_head = NULL;
    p_queue->p_tail = NULL;
    p_queue->length = LYNX_EV_EMPTY_LEN;
    pthread_mutex_init(&p_queue->mutex, NULL);
}

/**
 * @brief add a message to the event queue.
 *
 * @param p_queue   pointer to the event queue.
 * @param p_message pointer to the message to be added.
 */
void lynx_ev_queue_put(struct lynx_ev_queue_t *p_queue, struct lynx_ev_message_t *p_message)
{
    pthread_mutex_lock(&p_queue->mutex);
    if(NULL != p_queue->p_tail)
    {
        p_message->p_previous   = NULL;
        p_message->p_next       = p_queue->p_tail;

        p_queue->p_tail->p_previous = p_message;
        p_queue->p_tail             = p_message;
    }
    else
    {
        p_message->p_next       = NULL;
        p_message->p_previous   = NULL;
        p_queue->p_head = p_queue->p_tail   = p_message;
    }
    p_queue->length = p_queue->length + 1;
    pthread_mutex_unlock(&p_queue->mutex);
}

/**
 * @brief retrieve and remove the message from the head of the queue.
 *
 * @param p_queue pointer to the event queue.
 * @return pointer to the message retrieved, or NULL if queue is empty.
 */
struct lynx_ev_message_t *lynx_ev_queue_get(struct lynx_ev_queue_t *p_queue)
{
    struct lynx_ev_message_t *p_return_message  = NULL;
    struct lynx_ev_message_t *p_temp_message    = NULL;

    pthread_mutex_lock(&p_queue->mutex);
    if(NULL != p_queue->p_head)
    {
        p_return_message    = p_queue->p_head; 
        if(p_queue->p_head  == p_queue->p_tail)
        {
            p_queue->p_head = p_queue->p_tail   = NULL;
        }
        else
        {
            p_temp_message  =  p_queue->p_head->p_previous;
            p_queue->p_head->p_previous->p_next = NULL;
            p_queue->p_head->p_previous         = NULL;
            p_queue->p_head = p_temp_message;
        }
    }
    if(p_queue->length > LYNX_EV_EMPTY_LEN)
    {
        p_queue->length = p_queue->length - 1;
    }
    pthread_mutex_unlock(&p_queue->mutex);
    return p_return_message;
}

/**
 * @brief count the number of messages currently in the queue.
 *
 * @param p_queue pointer to the event queue.
 * @return number of messages in the queue.
 */
uint32_t lynx_ev_queue_length(struct lynx_ev_queue_t *p_queue)
{
    uint32_t counter    = LYNX_EV_EMPTY_LEN;
    struct lynx_ev_message_t *p_temp_queue  = p_queue->p_tail;
    pthread_mutex_lock(&p_queue->mutex);
    while(NULL != p_temp_queue)
    {
        counter = counter + 1;
        p_temp_queue    = p_temp_queue->p_next;
    }
    pthread_mutex_unlock(&p_queue->mutex);
    return counter;
}

/**
 * @brief check if messages are available in the queue.
 *
 * @param p_queue Pointer to the event queue.
 * @return LYNX_EV_AVAILABLE_LEN if messages exist, else LYNX_EV_EMPTY_LEN.
 */
uint32_t lynx_ev_queue_available(struct lynx_ev_queue_t *p_queue)
{
    uint32_t ret    = LYNX_EV_EMPTY_LEN;
    pthread_mutex_lock(&p_queue->mutex);
    if(NULL != p_queue->p_head)
    {
        ret = LYNX_EV_AVAILABLE_LEN;
    }
    else 
    {
        ret    = LYNX_EV_EMPTY_LEN;
    }
    pthread_mutex_unlock(&p_queue->mutex);
    return ret;
}

/**
 * @brief Free a message and its associated memory.
 *
 * @param p_message Pointer to the message to free.
 */
void lynx_ev_message_free(struct lynx_ev_message_t  *p_message)
{
    if(NULL != p_message)
    {
        if(NULL != p_message->p_header)
        {
            if(NULL != p_message->p_header->p_payload)
            {
                free(p_message->p_header->p_payload);
            }
            free(p_message->p_header);
        }
        free(p_message);

    }
}
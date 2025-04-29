#include "stdio.h"
#include "string.h"
#include <stdlib.h>      // thêm dòng này để dùng malloc, free
#include <cstdlib>
#include "lynx_ev_message.h"
struct lynx_ev_queue_t queue;
int main()
{
    lynx_ev_queue_init(&queue);
    struct lynx_ev_message_t *p_message = NULL;
    struct lynx_ev_message_t *p_message_rcv = NULL;
    p_message = (struct lynx_ev_message_t*)malloc(sizeof(struct lynx_ev_message_t));
    p_message->p_header = (struct lynx_ev_header_t*)malloc(sizeof(struct lynx_ev_header_t));
    p_message->p_header->message_type = 0x01;
    p_message->p_header->signal = 0x02;
    p_message->p_header->source_task_id = 0x03;
    p_message->p_header->destination_task_id = 0x04;
    char *data = "Hello Lynx_Ev!!! \n";
    p_message->p_header->p_payload = (char*)malloc(sizeof(char)*strlen(data) + 1);
    strcpy((char*)p_message->p_header->p_payload, data);
    p_message->p_header->length = strlen((char*)p_message->p_header->p_payload);
    lynx_ev_queue_put(&queue,p_message);
    
    if(lynx_ev_queue_available(&queue))
    {
        p_message_rcv = lynx_ev_queue_get(&queue);
        printf("message type: %d \n",p_message_rcv->p_header->message_type);
        printf("signal: %d \n",p_message_rcv->p_header->signal);
        printf("source_task_id: %d \n",p_message_rcv->p_header->source_task_id);
        printf("destination_task_id: %d \n",p_message_rcv->p_header->destination_task_id);
        printf("destination_task_id: %s \n",(char*)p_message_rcv->p_header->p_payload);
        lynx_ev_message_free(p_message_rcv);
    }
    return 0;
}
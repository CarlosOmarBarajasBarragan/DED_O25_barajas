#ifndef QUEUE_H
#define QUEUE_H
#include "../bool.h"


typedef struct queue_str * queue;


queue queue_create();
int queue_size(queue);
Bool queue_isEmpty(queue);
void queue_enqueue(queue,void*);
void* queue_dequeue(queue);
void* queue_peek(queue);
void queue_destroy(queue);

#endif
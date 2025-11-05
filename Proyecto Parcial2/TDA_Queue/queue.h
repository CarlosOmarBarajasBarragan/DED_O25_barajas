#ifndef QUEUE_H
#define QUEHUE_H

#include <stdbool.h>

typedef bool boolean;
#define TRUE 1
#define FALSE 0

typedef struct queue_str * queue;



queue queue_create();

int queue_size(queue);

boolean queue_isEmpty(queue);

void queue_enqueue(queue,void*);

void * queue_dequeue(queue);

void * queue_peek(queue);

void queue_destroy(queue);

#endif
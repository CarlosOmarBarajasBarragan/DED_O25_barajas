#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "../bool.h"


struct strNode{
    void * data;
    struct strNode * next;
};

typedef struct strNode node;

struct queue_str{
    struct strNode *head, *tail;
    int size;
};


queue queue_create(){
    queue newQ = malloc(sizeof(struct queue_str));

    newQ->head = NULL;
    newQ->tail = NULL;
    newQ->size =0;

    return newQ;
};

int queue_size(queue Q){
    return Q->size;
};

Bool queue_isEmpty(queue Q){
    return Q->size == 0;
}

void queue_enqueue(queue Q , void * D){
    node * n= (node*)malloc(sizeof(struct strNode));
    n->data = D;
    n->next=NULL;


    if(queue_isEmpty(Q)){
        Q->head= n;
        Q->tail= n;
    }

    else{
        Q->tail->next = n;
        Q->tail=n;
    }
    Q->size++;

};

void *queue_dequeue(queue Q) 
{
    if(Q == NULL || Q->head == NULL) 
    {
        printf("Queue vacía\n");
        return NULL;
    }

    node *temp = Q->head;
    void *data = temp->data;

    Q->head = temp->next;
    if(Q->head == NULL) 
    {
        Q->tail = NULL;
    }

    free(temp);
    Q->size--;
    return data;
}


void *queue_peek(queue Q) 
{
    if (queue_isEmpty(Q)) 
    {
        printf("Queue vacía\n");
        return NULL;
    }
    
    return Q->head->data;
}

void queue_destroy(queue q) 
{
    if(!q) 
    {
        return;
    }

    node *current = q->head;
    while(current) 
    {
        node *next_node = current->next;
        free(current);
        current = next_node;
    }

    free(q);
}

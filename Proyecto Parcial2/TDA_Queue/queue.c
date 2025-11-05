#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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

boolean queue_isEmpty(queue Q){
    if (Q->size == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
};

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

void * queue_dequeue(queue Q) {
    if (Q == NULL || Q->head == NULL) {
        printf("Queue vacio\n");
        return NULL;
    }
        node * temp = Q->head;
        node * newHead = Q->head->next;
        void * data = temp->data;
 
    if (Q->head == Q->tail) {
        Q->head = NULL;
        Q->tail = NULL;
    }
    else {

 
        Q->head = newHead;
        }

    free(temp);
    Q->size--;
    return data;
} 

void * queue_peek(queue Q){
    if(queue_isEmpty(Q)){
        printf("Queue vacio\n");
        return NULL;
    }
    void * data = Q->head->data;
    return data;

};
void queue_destroy(queue Q) {
    if (Q == NULL) {
        return;
    }
    node * current = Q->head;
    

    node * next_node;

    while (current != NULL) {
        free(current);
        current = next_node;
    }
    Q->size = 0;
    free(Q);
};
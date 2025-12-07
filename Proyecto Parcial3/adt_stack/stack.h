#ifndef STACK_H
#define STACK_H

typedef int boolean;
#define TRUE 1
#define FALSE 0

typedef struct stack_str stack;

stack * stack_create();

void stack_push(stack * st, void * data);

void * stack_pop(stack * st);

void stack_destroy(stack * st);

void * stack_top(stack * st);

int stack_size();

int stack_is_empty(stack * s);


#endif
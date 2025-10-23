#include <stdio.h>
#include <stdlib.h>

/* NOTE: This entire stack only works with integers since the stack node stores
   an integer value. In the next exam, we will see how to improve this and
   generalize it using an ADT (Abstract Data Type) later. */

// Structure to create a stack_node
typedef struct stack_node {
    int info;
    struct stack_node *prev;
}stack_node;

/* GLOBAL STACK */
stack_node *stack_top = NULL;
int count = 0;

// Push() operation to insert elements into the stack 
void push(int data) 
{

  stack_node * newNode = malloc(sizeof(stack_node));
  newNode->info = data;
  newNode->prev = NULL; 

  if (stack_top == NULL){
    stack_top = newNode;
  }
  else{
    stack_node * temp = stack_top;
    stack_top = newNode;
    newNode->prev = temp;
  

  printf("\tnode inserted\n");
  }
  count++;
}

// For this version of the integer stack, it returns -1 if there is nothing to pop
int pop() 
{
  if (stack_top == NULL){
    return -1;
  }
  else{
    stack_node * temp = stack_top;
    stack_top = stack_top->prev;
    int val = temp->info;
    free(temp);
    return val;
  
  count--;
  }
}

// Displays the current elements in the stack
void display() 
{
  stack_node * nptr = stack_top;
  
  if (nptr == NULL)
  {
      printf("\nStack Underflow\n");
      return;
  }
  
  printf("The stack is \n");
  while (nptr != NULL)
  {
      printf("%d--->", nptr->info);
      nptr = nptr->prev;
  }
  printf("NULL\n\n");
}

void isEmpty() 
{
  
  if (count == 0)
  {
      printf("\nStack is empty\n");
      return;
  } else  {
      printf("\nSize is %d\n", count);
      return;
  }
  

}

void Destroy() 
{
  
  stack_node * nptr = stack_top;
  
  if (nptr == NULL)
  {
      printf("\nStack is empty\n");
      return;
  }
  
  while (nptr != NULL)
  {
    stack_node * temp;
    temp = nptr->prev;
    free(nptr);
    nptr = temp;
    count--;

  }
  printf("\nDestroyed\n");
  stack_top = NULL;

}

int main() 
{
  int choice, value, ret;
  printf("\nSTACK:\n");
  while (1) 
  {
    printf("\n1. Push\n2. Pop\n3. Display\n4. IsEmpty\n5. Destroy\n6. Exit\n");
    printf("\n\tChoice : ");
    ret = scanf("%d", &choice);
    switch (choice) 
    {
      case 1:
        printf("\tEnter the value to insert: ");
        ret = scanf("%d", &value);
        push(value);
        break;
      case 2:
        printf("Popped element is :%d\n", pop());
        break;
      case 3:
        display();
        break;
      case 4:
        isEmpty();
        break;
      case 5:
        Destroy();
        break;
      case 6:
        exit(0);
        break;

      default:
        printf("\nWrong Choice\n");
    }
  }
}

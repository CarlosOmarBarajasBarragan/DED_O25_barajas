#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "../adt_stack/stack.h"

struct set_str {
	struct node * root;
	int size;
	compare_func compare;
	print_func printme;
};

typedef struct node
{
  void * data;
  struct node * left;
  struct node * right;
} node;

set * set_create (compare_func cf, print_func pf){
    set * newSet;
    newSet = malloc(sizeof(set));

    if (newSet == NULL) {
        return NULL; 
    }

    newSet->root = NULL;
    newSet->size = 0;
    newSet->compare = cf;
    newSet->printme = pf;

    return newSet;
};

node * create_node(void * data)
{
  node * n = malloc (sizeof(node));

  if (n == NULL) {
    return NULL; 
    }

  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

int set_size(set * s){
    return s->size;
};

boolean set_add(set * s, void * data){

    if(s->root==NULL){
        s->root = create_node(data);
        s->size++;
        return TRUE;
    }

    node * current = s->root;
    
    while(1){

    int comp = s->compare(data,current->data);

    if(comp == 0){
        printf("No se permiten datos duplicados\n");
        return FALSE;
    }
    else if(comp < 0){
        if (current->left == NULL){
        node * newNode = create_node(data);
        current->left = newNode;
        s->size++;
        return TRUE;
        }
        current = current->left;
    }
    else{
        if (current->right == NULL){
        node * newNode = create_node(data);
        current->right = newNode;
        s->size++;
        return TRUE;
        }
        current = current->right;
    }
    }
  return FALSE;
};

boolean set_contains (set * s, void * data){
  node * curr = s->root;

  while (curr != NULL){
  if(s->compare(data,curr->data) == 0){
    return TRUE;
    }
    else if (s->compare(data,curr->data) < 0){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }
    return FALSE;
};


boolean set_remove (set * s, void * data){

    node * prev = NULL;
    node * curr = s->root;

    while (curr != NULL){
    if(s->compare(data,curr->data) == 0){
        
        return TRUE;
        }
        else if (s->compare(data,curr->data) < 0){
        curr = curr->left;
        }
        else{
        curr = curr->right;
        }
    }

    return FALSE;


};

void set_print (set *s){

    node * curr = s->root;

    stack * node_stack = stack_create();

    while(curr!=NULL || (stack_size(node_stack) != 0)){

    while(curr != NULL){

    stack_push(node_stack,curr);
    curr = curr->left;
    }
    
    curr = stack_pop(node_stack);

    s->printme(curr->data); //P 

    curr = curr->right;
    }
    stack_destroy(node_stack);

};

void set_destroy (set * s){

    node * curr = s->root;

    stack * node_stack = stack_create();

    while(curr!=NULL || (stack_size(node_stack) != 0)){

    while(curr != NULL){

    stack_push(node_stack,curr);
    curr = curr->left;
    }
    
    curr = stack_pop(node_stack);

    node * temp = curr->right;

    free(curr);

    curr = temp;
    }
    stack_destroy(node_stack);
    free(s);

};


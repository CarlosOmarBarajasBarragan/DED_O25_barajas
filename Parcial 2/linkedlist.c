#include <stdio.h>
#include <stdlib.h>
#define CLEAR printf("\033[0;0H\033[2J");

/* USE THE CODE SEEN IN THE CLASS SLIDES TO COMPLETE THE FOLLOWING EXERCISE 
   TIP, code everything in the following order:
   1) printlist. As this function only traverses the list without modifying
   2) add      . adds to the end, follow the printlist logic to get to the end
                 and just attach the new node to the last node

   all the other functions
   
   */

/* The node */
typedef struct node {
  int value;
  struct node *next;
} node;

node *header = NULL;  //<--- this is our first linked list! :) 

/* Our header is called "header" and is a GLOBAL variable  initialized to NULL
   All functions in this exercise will consider "header" as the head of the 
   only list that exists here.  
   In reality, there should be many lists, and functions should receive the 
   list to apply operations to, but we will see that later. */

//Pending:
node *newNode(int n) 
{
  node * Node = (node*) malloc(sizeof(node));
  Node ->value = n;
  Node ->next = NULL;  

  return Node;
}

//Pending:
void printlist(node *list) 
{

  if (header == NULL){
      printf("La lista está vacia, crea un nodo");
      return 0;
    }

node * n_ptr = list;  
while(n_ptr != NULL){
  printf("[%d] -> ",n_ptr->value);
  n_ptr = n_ptr->next;
}
 printf("NULL\n");
}

//Pending:
/* Function that receives a number to add, then adds this node to the END
   of the linked list. Be careful with corner cases, what happens if the list
   is NULL (empty list?)
   node does not exist, we should create the node  */
void add(int num) 
{
  node * current = header;
  if (header == NULL){
    header = newNode(num);
  }
  else{
    while (current->next != NULL) {
    current = current->next;
    } 
    current->next = newNode(num);
        
  }

}

//Pending:
/* Function that inserts a node N after X
   Finds the first node with value X and inserts N immediately after..

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertafter(int new_num, int n_search)
{
  node * n_ptr = header;
  node * next = NULL;

    if (header == NULL){
      add(new_num);
      return 1;
    }

  while (n_ptr != NULL){
    if(n_ptr->value == n_search){

      next = n_ptr->next;
      n_ptr->next = newNode(new_num);
      n_ptr->next->next = next;
      return 1;
    }
    n_ptr = n_ptr->next;

  }

  return 0;
}

//Pending:
/* Function that inserts a node N before X
   Finds the first node with value X and inserts
   N immediately before...

   Returns 1 if it was inserted, or 0 if not 
   The return code is used by the caller to determine if the created node
   needs to be freed or not (the one this function failed to insert )*/

int insertbefore(int new_num, int n_search)
{
    node * n_ptr = header;
    node * prev = NULL;
    node * newnode = NULL;

    if (header == NULL){
      add(new_num);
      return 1;
    }

  while (n_ptr != NULL){
    if(header->value == n_search){

        newnode = newNode(new_num);

        newnode->next = n_ptr;

        header = newnode;
        return 1;

    }else if(n_ptr->value == n_search){

        newnode = newNode(new_num);

        newnode->next = n_ptr;

        prev->next = newnode;
        
        return 1;
    
    }
    prev = n_ptr;
    n_ptr = n_ptr->next;
  }
  return 0;
}

//Pending
/* Function to delete the node that contains number N */
void delete(int n)
{

  if (header == NULL){
      printf("La lista está vacia, crea un nodo");
      return 0;
    }

  node * n_ptr = header;
  node * prev = NULL;

  while (n_ptr != NULL){
    if(n_ptr->value == n){
      
      if (prev == NULL){
        header = n_ptr->next;
      }
     else{
        prev->next = n_ptr->next;
      }
        free(n_ptr);
        break;
    }
    prev = n_ptr;
    n_ptr = n_ptr->next;
  }
}

//Pending
/* Function to search for a node containing number N. If found,
   it should print the memory address where it resides; 
   if not found, it should print "NULL" */

void search(int to_search)
{
  node * n_ptr = header;
  int found = 0;

  while (n_ptr != NULL){
    if(n_ptr->value == to_search){
      found = 1;
      break;
    }
    n_ptr = n_ptr->next;
  }
  if(found == 1){
    printf("El valor %d fue encontrado en el nodo con la direccion: %p\n",to_search,n_ptr);
  }
  else{
    printf("NULL");
  }

}

int main() 
{
  /* #1 :
  Create a function newNode(n) that creates a new node with value n
  and returns a pointer to the newly created node */

  /* #2:
  Using this function, create a new node to act as the first
  element "header" of our list */

  node *n = newNode(50);
  header = n;

  /* #3:
  Create 5 additional nodes, so that we have a total list of 5 nodes
  properly linked together. Write a function
  add() that receives a node (created with newNode()) and
  adds this node to the end of the list.

  Use a FOR loop to fill the 5 nodes */
  for (int x = 1; x <= 6; x++) 
  {
    add(x+1);
  }

  /* #4:
  Create a print function to print the entire linked list.
  It should look like this:
    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> NULL
  */


  /* #5:
  Create a menu (inside an infinite while loop), with the following functionalities:
    1) Delete a node
    2) Insert after a given node
    3) Insert before a given node
    4) Search for a node
    6) Insert at the end of the list
  */
 int entrada = -1;

  int numero_en, numero_search;
while(entrada != 0){
    printlist(header);
    printf("0)Cerrar 1) Delete a node\n2) Insert after a given node\n3) Insert before a given node\n4) Search for a node\n5) Insert at the end of the list\n");

    printf("Opcion: "); 
    scanf("%d",&entrada);

    switch (entrada){
        case 0: 
        break;

        case 1:
       
        printf("Ingresa el valor de parametro a eliminar: ");
        scanf("%d",&numero_en);
        delete(numero_en);
        break;

        case 2:
       
        printf("Ingresa el valor de parametro a crear: ");
        scanf("%d",&numero_en);
       
        printf("Ingresa el valor de parametro de busqueda: ");
        scanf("%d",&numero_search);
        insertafter(numero_en,numero_search);
        break;

        case 3:
       
        printf("Ingresa el valor de parametro a crear: ");
        scanf("%d",&numero_en);
        
        printf("Ingresa el valor de parametro de busqueda: ");
        scanf("%d",&numero_search);
        insertbefore(numero_en,numero_search);
        break;
        
        case 4:
        
        printf("Ingresa el valor de parametro de busqueda: ");
        scanf("%d",&numero_search);
        search(numero_search);
        break;
        
        case 5:
        
        printf("Ingresa el valor de parametro a crear: ");
        scanf("%d",&numero_en);
        add(numero_en);
        break;

        default:
        printf("Ingresa un valor valido");
        break;
    }

}


}

/* #6 Once everything is working, make a copy of this file and  
   name it: doublelinkedlist.c. Add the element "back" to the structure  
   and create a doubly linked list. All functionality must persist.

   The print function should print the list "forward" using `next` and  
   "backward" using `back`, and it should look like this:

     1 -> 2 -> 3 -> 4 -> ... 10 -> 9 -> 8 -> 7 -> ..... 1 -> NULL
*/
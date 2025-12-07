#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    void * data;
    struct Node * next;
} Node;

struct list_str {
    Node * head;    // Puntero al inicio
    Node * tail;    // Puntero al final (para insertar rápido)
    Node * current; // Puntero para iterar (recorrer)
    int size;
};

List * list_create() {
    List * L = (List *) malloc(sizeof(List));
    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;
    L->size = 0;
    return L;
}

void list_add(List * L, void * data) {
    Node * new_node = (Node *) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (L->head == NULL) {
        // Caso: Lista vacía
        L->head = new_node;
        L->tail = new_node;
    } else {
        // Caso: Lista con elementos, agregamos al final
        L->tail->next = new_node;
        L->tail = new_node;
    }
    L->size++;
}

void * list_first(List * L) {
    if (L->head == NULL) return NULL;
    
    L->current = L->head; // Reiniciamos el iterador al principio
    return L->current->data;
}

void * list_next(List * L) {
    if (L->current == NULL || L->current->next == NULL) {
        return NULL; // No hay más elementos
    }
    
    L->current = L->current->next; // Avanzamos
    return L->current->data;
}

int list_size(List * L) {
    return L->size;
}

void list_clean(List * L) {
    Node * aux = L->head;
    while (aux != NULL) {
        Node * temp = aux;
        aux = aux->next;
        free(temp); // Liberamos el nodo, no el dato (el dato es responsabilidad del usuario)
    }
    free(L);
}
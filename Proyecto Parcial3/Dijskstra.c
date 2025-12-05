#include <stdio.h>
#include <stdlib.h>

#include "adt_set/set.h"


typedef struct Arista {
    int vertice_destino;
    struct Arista *siguiente;
} Arista;


typedef struct Node {
    int dato;
    Arista *arista;
} Node;



boolean compareNode(void * t1, void * t2) {
  char *c1 = (char *)t1;
  char *c2 = (char *)t2;
  printf("comparing %s with %s\n", c1, c2);
  return strcmp(c1, c2) == 0;
}

void printNode(void * node){

}

Node* crear_node(int dato) {
    Node *nuevo_nodo = (Node*)malloc(sizeof(Node));
    if (nuevo_nodo != NULL) {
        nuevo_nodo->dato = dato;
        nuevo_nodo->arista = NULL;
    }
    return nuevo_nodo;
}

void agregar_arista(Node **grafo, int origen, int destino) {
    if (grafo[origen] == NULL) return;

    Arista *nueva_arista = (Arista*)malloc(sizeof(Arista));
    if (nueva_arista != NULL) {
        nueva_arista->vertice_destino = destino;
        nueva_arista->siguiente = grafo[origen]->arista;
        grafo[origen]->arista = nueva_arista;
    }
}

void imprimir_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        printf("Nodo %d (Dato %d): ", i, grafo[i]->dato);
        Arista *actual = grafo[i]->arista;
        while (actual != NULL) {
            printf(" -> %d", actual->vertice_destino);
            actual = actual->siguiente;
        }
        printf(" -> NULL\n");
    }
}

void shortest(set * way, Node * source, Node * destino){
    way = set_create();



}

void liberar_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        Arista *actual = grafo[i]->arista;
        while (actual != NULL) {
            Arista *temp = actual;
            actual = actual->siguiente;
            free(temp); 
        }
        free(grafo[i]); 
    }
    free(grafo); 
}

int main() {
    int num_nodes = 4; 

    Node **grafo = (Node**)malloc(num_nodes * sizeof(Node*));
    if (grafo == NULL) return 1; 

    for (int i = 0; i < num_nodes; i++) {
        grafo[i] = crear_node(i);
    }

    agregar_arista(grafo, 0, 1);
    agregar_arista(grafo, 0, 2);
    agregar_arista(grafo, 0, 3);


    agregar_arista(grafo, 1, 0);
    agregar_arista(grafo, 1, 3);


    agregar_arista(grafo, 2, 0);
    agregar_arista(grafo, 2, 3);


    agregar_arista(grafo, 3, 0);
    agregar_arista(grafo, 3, 1);
    agregar_arista(grafo, 3, 2);


    imprimir_grafo(grafo, num_nodes);

     
    

    
    liberar_grafo(grafo, num_nodes);
    
    return 0;
}
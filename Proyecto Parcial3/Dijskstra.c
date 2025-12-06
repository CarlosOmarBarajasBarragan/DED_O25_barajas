#include <stdio.h>
#include <stdlib.h>

#include "adt_set/set.h"


typedef struct Conexion {
    int nodo_destino;
    int costo;
    struct Conexion *siguiente;
} Conexion;


typedef struct Node {
    int dato;
    int distancia_minima;
    Node *predecesor;
    Conexion *arista;
} Node;



int compareNode(void * v1, void * v2) {
  Node *N1 = (Node*)v1;
  Node *N2 = (Node*)v2;
  return N1->distancia_minima - N2->distancia_minima;
}

void printNode(void * v){
    Node * node = (Node*)v;

    printf("%d",node->dato);

}

Node* crear_node(int dato) {
    Node *nuevo_nodo = (Node*)malloc(sizeof(Node));
    if (nuevo_nodo != NULL) {
        nuevo_nodo->dato = dato;
        nuevo_nodo->arista = NULL;

        nuevo_nodo->distancia_minima=999;
        nuevo_nodo->predecesor=NULL;
    }
    return nuevo_nodo;
}

void agregar_conexion(Node **grafo, int origen, int destino, int costo) {
    if (grafo[origen] == NULL) return;

    Conexion *nueva_conexion = (Conexion*)malloc(sizeof(Conexion));
    if (nueva_conexion != NULL) {
        nueva_conexion->nodo_destino = destino;
        nueva_conexion->costo = costo;
        nueva_conexion->siguiente = grafo[origen]->arista;
        grafo[origen]->arista = nueva_conexion;
    }
}

void imprimir_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        printf("Nodo %d (Dato %d): ", i, grafo[i]->dato);
        Conexion *actual = grafo[i]->arista;
        while (actual != NULL) {
            printf(" -> %d", actual->nodo_destino);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

void shortest(Node * source, Node * destino){

    source->distancia_minima=0;
    source->predecesor=NULL;

    set * way = set_create(compareNode,printNode);

    set_add(way,source);
    


}

void liberar_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        Conexion *actual = grafo[i]->arista;
        while (actual != NULL) {
            Conexion *temp = actual;
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

    agregar_conexion(grafo, 0, 1,10);
    agregar_conexion(grafo, 0, 2,10);
    agregar_conexion(grafo, 0, 3,10);


    agregar_conexion(grafo, 1, 0,10);
    agregar_conexion(grafo, 1, 3,10);


    agregar_conexion(grafo, 2, 0,10);
    agregar_conexion(grafo, 2, 3,10);


    agregar_conexion(grafo, 3, 0,10);
    agregar_conexion(grafo, 3, 1,10);
    agregar_conexion(grafo, 3, 2,10);


    imprimir_grafo(grafo, num_nodes);

     
    

    
    liberar_grafo(grafo, num_nodes);
    
    return 0;
}
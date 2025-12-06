#include <stdio.h>
#include <stdlib.h>

#include "adt_pq/pq.h"


typedef struct Conexion {
    int nodo_destino;
    int costo;
    struct Conexion *siguiente;
} Conexion;


typedef struct Node {
    int dato;
    int distancia_minima;
    int visitado;
    struct Node *predecesor;
    Conexion * conexiones;
} Node;



int compareNode(void * v1, void * v2) {
  Node *N1 = (Node*)v1;
  Node *N2 = (Node*)v2;
  return N1->distancia_minima - N2->distancia_minima;
}


Node* crear_node(int dato) {
    Node *nuevo_nodo = (Node*)malloc(sizeof(Node));
    if (nuevo_nodo != NULL) {
        nuevo_nodo->dato = dato;
        nuevo_nodo->conexiones = NULL;
        nuevo_nodo->visitado=0;

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
        nueva_conexion->siguiente = grafo[origen]->conexiones;
        grafo[origen]->conexiones = nueva_conexion;
    }
}

void imprimir_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        printf("Nodo %d (Dato %d): ", i, grafo[i]->dato);
        Conexion *actual = grafo[i]->conexiones;
        while (actual != NULL) {
            printf("{%d,%d}", actual->nodo_destino,actual->costo);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

void shortest(Node * source, Node * destino, int num_nodes){

    source->distancia_minima=0;
    source->predecesor=NULL;

    pq * finder = pq_create(num_nodes,compareNode);

    pq_offer(finder,source);

    while(!pq_size(finder) == 0){
        Node * curr = pq_poll(finder);
        if(compareNode(curr,destino) == 0){
            printf("No nos movimos, nuestro destino era igual al origen\n");
        }

        if(curr->visitado==1){
            continue;
        }
        else{
            curr->visitado=1;
        }

        Conexion * way = curr->conexiones;

        while(way != NULL){
            Node * Vecino = way->nodo_destino;

            if(curr->distancia_minima != 999){
                int nueva_distancia = curr->distancia_minima + way->costo;

                if(nueva_distancia < Vecino->distancia_minima){
                    Vecino->distancia_minima=nueva_distancia;
                    Vecino->predecesor=curr;
                    pq_offer(finder,Vecino);
                }
            }
            way=way->siguiente

        }
    }
    


}

void liberar_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        Conexion *actual = grafo[i]->conexiones;
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
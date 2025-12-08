#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adt_pq/pq.h"
#include "adt_stack/stack.h"

typedef struct Node Node;

typedef struct Conexion {
    Node * nodo_destino;
    int costo;
    struct Conexion *siguiente; //Siguiente conexion, siguiente eslabon
} Conexion;


typedef struct Node {
    char * dato;
    int distancia_minima; 
    int visitado;
    struct Node *predecesor; //Crear el camino de nodos
    Conexion * conexiones; // Arreglo de conexiones
} Node;



int compareNode(void * v1, void * v2) {
  Node *N1 = (Node*)v1;
  Node *N2 = (Node*)v2;
  return N1->distancia_minima - N2->distancia_minima;
}


Node* crear_node(char * dato) {
    Node *nuevo_nodo = (Node*)malloc(sizeof(Node));
    if (nuevo_nodo != NULL) {
        nuevo_nodo->dato = strdup(dato);
        nuevo_nodo->conexiones = NULL;
        nuevo_nodo->visitado=0;

        nuevo_nodo->distancia_minima=999;
        nuevo_nodo->predecesor=NULL;
    }
    return nuevo_nodo;
}

void agregar_conexion(Node * origen, Node * destino, int costo) {
    if (origen == NULL) return;


    Conexion *nueva_conexion = (Conexion*)malloc(sizeof(Conexion));
    if (nueva_conexion != NULL) {
        nueva_conexion->nodo_destino = destino;
        nueva_conexion->costo = costo;
        nueva_conexion->siguiente = origen->conexiones;
        origen->conexiones = nueva_conexion;
    }
}

void limpiar_nodo(Node *nodo) {
    if (nodo == NULL) return;
    
    nodo->distancia_minima = 999; 
    nodo->visitado = 0;
    nodo->predecesor = NULL;
}

void eliminar_conexiones(Node *nodo) {
    if (nodo == NULL) return;

    Conexion *actual = nodo->conexiones;
    Conexion *aux;

    while (actual != NULL) {
        aux = actual;             
        actual = actual->siguiente; 
        free(aux);
    }

    nodo->conexiones = NULL;
}

void imprimir_grafo(Node **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        printf("Nodo %d (Dato %s): ", i, grafo[i]->dato);
        Conexion *actual = grafo[i]->conexiones;
        while (actual != NULL) {
            printf("{%s,%d} ", actual->nodo_destino->dato,actual->costo);
            actual = actual->siguiente;
        }
        printf("\n");
    }
}

void shortest(Node * source, Node * destino, int num_nodes){

    source->distancia_minima=0;
    source->predecesor=NULL;
    stack * display = stack_create();


    pq * finder = pq_create(num_nodes,compareNode);

    pq_offer(finder,source);

    while(!pq_size(finder) == 0){
        Node * curr = pq_poll(finder);
        if(compareNode(curr,destino) == 0){
                break;
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
            way=way->siguiente;

        }
    }

    Node * final = destino;

    if(final->distancia_minima == 999){
        printf("No hay manera de llegar de %s a %s",source->dato,final->dato);
    }
    else{

    printf("Con un tiempo de: %d \n",final->distancia_minima);
    printf("Se llego de la sala %s a la sala %s por la ruta: \n",source->dato,final->dato);

    while(final != NULL){
        stack_push(display,final->dato);
        final = final->predecesor;
        }
    while(stack_size(display) != 0){
        char * room = stack_pop(display);
        printf("%s ->",room);
    }
        printf(" NULL\n");

    }

    stack_destroy(display);
    if (finder != NULL) {
        while (!pq_is_empty(finder)) {
            pq_poll(finder);
        }
        
        free(finder); 
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
        free(grafo[i]->dato);
        free(grafo[i]); 
    }
    free(grafo); 
}
/*
int main() {
    int num_nodes = 4; 

    Node **grafo = (Node**)malloc(num_nodes * sizeof(Node*));
    if (grafo == NULL) return 1; 

    char * name1 = "Sala 0";
    char * name2 = "Sala 1";
    char * name3 = "Sala 2";
    char * name4 = "Sala 3";

    
    grafo[0] = crear_node(name1);
    grafo[1] = crear_node(name2);
    grafo[2] = crear_node(name3);
    grafo[3] = crear_node(name4);
    

    agregar_conexion(grafo[0], grafo[1],10);
    agregar_conexion(grafo[0], grafo[2],10);
    agregar_conexion(grafo[0], grafo[3],10);


    agregar_conexion(grafo[1], grafo[0],10);
    agregar_conexion(grafo[1], grafo[3],10);


    agregar_conexion(grafo[2], grafo[0],10);
    agregar_conexion(grafo[2], grafo[3],10);


    agregar_conexion(grafo[3], grafo[0],10);
    agregar_conexion(grafo[3], grafo[1],10);
    agregar_conexion(grafo[3], grafo[2],10);


    imprimir_grafo(grafo, num_nodes);

    shortest(grafo[1],grafo[0],4);

    
    liberar_grafo(grafo, num_nodes);
    
    return 0;
}
*/
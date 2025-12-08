#ifndef DIJKSTRA_H
#define DIJKSTRA_H

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



int compareNode(void * v1, void * v2);

Node* crear_node(char * dato);

void agregar_conexion(Node * origen, Node * destino, int costo);

void limpiar_nodo(Node *nodo);

void eliminar_conexiones(Node *nodo);

void imprimir_grafo(Node **grafo, int num_nodos);

void shortest(Node * source, Node * destino, int num_nodes);

void liberar_grafo(Node **grafo, int num_nodos);

#endif
#include <stdio.h>
#include <stdlib.h>

typedef struct Arista {
    int vertice_destino;
    struct Arista *siguiente;
} Arista;

typedef struct Node {
    int dato;
    Arista *arista;
} Node;

Node* crear_vertice(int dato) {
    Node *nuevo_nodo = (Node*)malloc(sizeof(Vertice));
    if (nuevo_nodo != NULL) {
        nuevo_nodo->dato = dato;
        nuevo_nodo->arista = NULL;
    }
    return nuevo_nodo;
}


void agregar_arista(Vertice **grafo, int origen, int destino) {
    Arista *nueva_arista = (Arista*)malloc(sizeof(Arista));
    if (nueva_arista != NULL) {
        nueva_arista->vertice_destino = destino;
        nueva_arista->siguiente = grafo[origen]->arista;
        grafo[origen]->arista = nueva_arista;
    }
}

void imprimir_grafo(Nodo **grafo, int num_nodos) {
    for (int i = 0; i < num_nodos; i++) {
        printf("Nodo %d: ", i);
        Arista *actual = grafo[i]->arista;
        while (actual != NULL) {
            printf("%d -> ", actual->vertice_destino);
            actual = actual->siguiente;
        }
        printf("NULL\n");
    }
}

int main() {
    int num_vertices = 4;

    
    Vertice **grafo = (Vertice**)malloc(num_vertices * sizeof(Vertice*));
    for (int i = 0; i < num_vertices; i++) {
        grafo[i] = crear_vertice(i);
    }

    
    agregar_arista(grafo, 1, 2);
    agregar_arista(grafo, 1, 3);
    agregar_arista(grafo, 1, 4);
    agregar_arista(grafo, 2, 1);
    agregar_arista(grafo, 2, 4);
    agregar_arista(grafo, 3, 1);
    agregar_arista(grafo, 3, 4);
    agregar_arista(grafo, 4, 1);
    agregar_arista(grafo, 4, 2);
    agregar_arista(grafo, 4, 3);

    // Imprimir el grafo
    imprimir_grafo(grafo, num_vertices);

    // Liberar memoria (no mostrado en este ejemplo para brevedad)
    
    return 0;
}

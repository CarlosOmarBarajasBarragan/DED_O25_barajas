#ifndef LIST_H
#define LIST_H

/* Definición opaca de la lista (para encapsulamiento) */
typedef struct list_str List;

/* Crea una nueva lista vacía */
List * list_create();

/* Agrega un elemento al final de la lista (O(1)) */
void list_add(List * L, void * data);

/* Funciones para iterar (Recorrer la lista) */
/* Coloca el iterador al inicio y retorna el primer dato */
void * list_first(List * L);

/* Avanza el iterador y retorna el siguiente dato (NULL si se acabó) */
void * list_next(List * L);

/* Retorna el tamaño de la lista */
int list_size(List * L);

/* Limpia la memoria de la estructura de la lista (no de los datos) */
void list_clean(List * L);

#endif
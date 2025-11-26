#ifndef HOSPITAL_H
#define HOSPITAL_H

typedef int boolean; 
#define TRUE 1   
#define FALSE 0

#include "adt_stack/stack.h"
#include "adt_map/map.h"
#include "adt_queue/queue.h"


// Definicion de los struct
struct paciente_str {
    int id;
    char name[40];
    char padecimiento[40];
    int urgencia;
    stack * historial_medico;
};

typedef struct paciente_str paciente;

struct doctor_str
{
    int id;
    char name[40];
    char especialidad[40];
    queue * fila_pacientes;
};
typedef struct doctor_str doctor;


struct Hospital_Manager_str
{
    map * lista_doctores;
    // Falta el grafo y el priority queue
    

    
};
typedef struct Hospital_Manager_str hospital_manager;

// Simplifica funciones de hash y compare
typedef int (*HashFunc)(void *t);
typedef boolean (*CompareFunc)(void * t1, void * t2);


#endif
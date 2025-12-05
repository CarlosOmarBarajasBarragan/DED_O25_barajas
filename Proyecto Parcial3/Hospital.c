#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// .h
#include "Hospital.h"
#include "adt_stack/stack.h"
#include "adt_map/map.h"
#include "adt_queue/queue.h"


struct paciente_str
{
    int id;
    char name[40];
    int urgencia;
    stack * historial_medico;
};
struct doctor_str
{
    int id;
    char name[40];
    char especialidad[40];
    queue * fila_pacientes;
};

struct Hospital_Manager_str
{
    map * lista_doctores;
    // Falta el grafo y el priority queue
    

    
};


// Creacion de nodos
paciente * create_paciente(int id,char nombre[],int urgencia){
    paciente * nuevo_paciente = (paciente*) malloc(sizeof(paciente));

    nuevo_paciente->id = id;
    strcpy(nuevo_paciente-> name, nombre);
    nuevo_paciente->urgencia = urgencia;

    nuevo_paciente->historial_medico = stack_create();
    return nuevo_paciente;
}


doctor * create_doctor(int id, char name[], char especialidad[]){
    doctor * nuevo_doctor = (doctor*) malloc(sizeof(struct doctor_str));

    nuevo_doctor->id = id;
    strcpy(nuevo_doctor->name, name);
    strcpy(nuevo_doctor->especialidad, especialidad);

    nuevo_doctor->fila_pacientes = queue_create();
    return nuevo_doctor;
}

void registrar_doctor(hospital_manager * manager, doctor * D) {
    char * esp = D->especialidad;
    queue * q = (queue *) map_get(manager->lista_doctores, esp);

    if (q == NULL) {
        printf("\nNo existe %s, creando la lista\n", esp);
        queue * nuevaQ = queue_create();
        queue_enqueue(nuevaQ, D);
        map_put(manager->lista_doctores, esp, nuevaQ);
    } else {
        printf("\nYa existe %s, guardando doctor\n", esp);
        queue_enqueue(q, D);
    }
}

hospital_manager * create_hospital_manager(int m, hash_func hash, CompareFunc compare){
   hospital_manager * nuevo_hospital_manager = (hospital_manager*) malloc(sizeof(hospital_manager));

   nuevo_hospital_manager->lista_doctores = map_create(m, hash, compare);
   // Falta el grafo y el priority queue
}


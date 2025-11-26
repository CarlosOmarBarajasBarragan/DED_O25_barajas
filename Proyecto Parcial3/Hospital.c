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

    nuevo_paciente->id=id;
    strcpy(nuevo_paciente->name,nombre);
    nuevo_paciente->urgencia=urgencia;

    nuevo_paciente->historial_medico=stack_create();
    return nuevo_paciente;
}


doctor * create_doctor(int id,char name[]){
    doctor * nuevo_doctor = (doctor*) malloc(sizeof(doctor));

    nuevo_doctor->id=id;
    strcpy(nuevo_doctor->name,name);

    nuevo_doctor->fila_pacientes=queue_create();
    return nuevo_doctor;

}

hospital_manager * create_hospital_manager(int m,hash_func hash,CompareFunc compare){
   hospital_manager * nuevo_hospital_manager = (hospital_manager*) malloc(sizeof(hospital_manager));

   nuevo_hospital_manager->lista_doctores=map_create(m,hash,compare);
   // Falta el grafo y el priority queue
}


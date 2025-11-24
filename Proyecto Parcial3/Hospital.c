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
    // falta la cola
};

struct Hospital_Manager
{

    
};


// Creacion de nodos
paciente * create_paciente(int id,char[] nombre,int urgencia){
    paciente * nuevo_paciente = (paciente*) malloc(sizeof(paciente));

    nuevo_paciente->id=id;
    strcpy(nuevo_paciente->name,nombre);
    nuevo_paciente->urgencia=urgencia;

    nuevo_paciente->historial_medico=stack_create();

    return paciente;
    
   
}


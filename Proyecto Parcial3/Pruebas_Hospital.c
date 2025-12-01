#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// .h
#include "Hospital.h"

#include "adt_stack/stack.h"
#include "adt_map/map.h"
#include "adt_queue/queue.h"
#include "adt_pq/pq.h"

struct paciente_str {
    int id;
    char name[40];
    char padecimiento[40];
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
    strcpy(nuevo_paciente->name,nombre);

    nuevo_paciente->urgencia=urgencia;

    nuevo_paciente->historial_medico = stack_create();
    return nuevo_paciente;
}

doctor * create_doctor(int id,char name[]){
    doctor * nuevo_doctor = (doctor*) malloc(sizeof(doctor));

    nuevo_doctor->id=id;
    strcpy(nuevo_doctor->name,name);

    nuevo_doctor->fila_pacientes = queue_create();
    return nuevo_doctor;

}


hospital_manager * create_hospital_manager(int m,HashFunc hash,CompareFunc compare){
   hospital_manager * nuevo_hospital_manager = (hospital_manager*) malloc(sizeof(hospital_manager));

   nuevo_hospital_manager->lista_doctores=map_create(m,hash,compare);
   // Falta el grafo y el priority queue
}



/* En lugar de fila_especialista puede recibir puntero a su doctor */


void solicitar_consulta(paciente * P, char padecimiento[], doctor * D) { // hospital_manager HM

    if (P->urgencia <= 5)
    {// Atender consulta normal, no ocupa urgencia
        
        strcpy(P->padecimiento, padecimiento);

        queue_enqueue(D->fila_pacientes, P);

        printf("El paciente: %s con padecimiento: %s, sera atendido con: %s \n", 
            P->name, P->padecimiento, D->name); // aqui se cambia con el manager
        atender_consulta(D);
        
    }else{
        // Logica de urgencias
    }
    


    // Aqui va evaluar si es una urgencia

    
}

void solicitar_urgencia(paciente * P){

   // pq_enqueue(H->Urgencias,P);

     // printf("El paciente: %S con padecimiento: %S, de urgencia: %S
    // ha llegado a sala de urgencias \n", P->name, P->padecimiento,P->Urgencia);
    
}


void atender_consulta(doctor * D) {
    paciente * atendiendo = (paciente *) queue_dequeue(D->fila_pacientes);

    if (atendiendo == NULL) return; 

    char ultima_visita[40];
    void * dato = NULL;

    if (atendiendo->historial_medico != NULL) {
        //Dato recibe si tiene una ultima consulta
        dato = stack_top(atendiendo->historial_medico);
        
    }


    if (dato != NULL) {
        strcpy(ultima_visita, (char*)dato);
        printf("La ultima visita de %s tenia: %s\n", atendiendo->name, ultima_visita);
        
    } else {
        printf("Sin historial medico\n");
    }
    //char * visita_actual = strdup(atendiendo->padecimiento);
    stack_push(atendiendo->historial_medico, atendiendo->padecimiento);
    printf("%s ha sido atendido\n", atendiendo->name);
}

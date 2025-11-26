#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// .h
#include "Hospital.h"



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



/* En lugar de fila_especialista puede recibir puntero a su doctor */

void solicitar_consulta(paciente * P,char padecimiento[],doctor * D){

    strcpy(P->padecimiento,padecimiento);

    queue_enqueue(D->fila_pacientes,P);

    printf("El paciente: %S con padecimiento: %S, ha agendado cita con: %S \n", P->name, P->padecimiento,D->name);
    
}

void solicitar_urgencia(paciente * P){

   // pq_enqueue(H->Urgencias,P);

     // printf("El paciente: %S con padecimiento: %S, de urgencia: %S
    // ha llegado a sala de urgencias \n", P->name, P->padecimiento,P->Urgencia);
    
}



void atender_consulta(doctor * D){
    paciente * atendiendo = queue_dequeue(D->fila_pacientes);

    char ultima_visita [100];
    strcpy(ultima_visita,stack_pop(atendiendo->historial_medico));

    printf("La ultima visita de %S fue: %S",
    atendiendo->name,ultima_visita);
    
    
}

int main(){

    paciente * p1 = create_paciente(01,"Jorge",10);
    doctor * d1 = create_doctor(9,"Alberto");

    solicitar_consulta(p1,"Gripa",d1);

    atender_consulta(d1);


}
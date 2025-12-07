#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// .h
#include "Hospital.h"

#include "adt_list/list.h"
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
    pq * lista_urgencias;
    // Falta el grafo 
    

    
};
//------------------------------------------------------------------------------
// Declaraciones de las funciones
void agendar_consulta(paciente * P,char padecimiento[],hospital_manager * HM);
doctor * Doc_menos_ocupado(hospital_manager * HM, char * especialidad);
doctor * Doc_mas_ocupado(hospital_manager * HM,char * especialidad);
//------------------------------------------------------------------------------

// Funciones extras
void limpiar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
//-------------------------------------------------------------------
// Funciones de crear y registrar
//-------------------------------------------------------------------
// Creacion de nodos
paciente * create_paciente(int id,char nombre[],int urgencia){
    paciente * nuevo_paciente = (paciente*) malloc(sizeof(paciente));

    nuevo_paciente->id = id;
    strcpy(nuevo_paciente->name,nombre);

    nuevo_paciente->urgencia=urgencia;

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


void registrar_doctor(hospital_manager * HM, doctor * D) {
    char * esp = D->especialidad;
    
    // Obtenemos la lista del mapa
    List * lista = (List *) map_get(HM->lista_doctores, esp);

    if (lista == NULL) {
        printf("\nNo existe %s, creando la lista...\n", esp);
        List * nuevaLista = list_create();
        list_add(nuevaLista, D);
        map_put(HM->lista_doctores, esp, nuevaLista);
    } else {
        printf("\nYa existe %s, guardando doctor...\n", esp);
        list_add(lista, D);
    }
}


hospital_manager * create_hospital_manager(int m,HashFunc hash,CompareFunc compare){
   hospital_manager * nuevo_hospital_manager = (hospital_manager*) malloc(sizeof(hospital_manager));

   nuevo_hospital_manager->lista_doctores=map_create(m,hash,compare);
   nuevo_hospital_manager->lista_urgencias=pq_create(m,compare);
   // Falta el grafo 
   return nuevo_hospital_manager;
}



/* En lugar de fila_especialista puede recibir puntero a su doctor */

//-------------------------------------------------------------
// Funcion de solicitiar las consultas y atenderlas
//-------------------------------------------------------------

void solicitar_consulta(paciente * P, char padecimiento[], hospital_manager * HM) { // hospital_manager HM

    if (P->urgencia <= 5)
    {// Atender consulta normal, no ocupa urgencia
        
        agendar_consulta(P,padecimiento,HM);
        return;
        
    }else{
        // Logica de urgencias
    }
    
}

void agendar_consulta(paciente * P,char padecimiento[],hospital_manager * HM){
    strcpy(P->padecimiento, padecimiento);

     
    doctor * doc = Doc_menos_ocupado(HM,P->padecimiento);
    
    if (doc == NULL)
    {
        //printf("No hay doctores registrados\n");
        return;
    }
    
    queue_enqueue(doc->fila_pacientes, P);

   printf("El paciente: %s con padecimiento: %s, sera atendido por: %s \n", 
            P->name, P->padecimiento,doc->name); 
    return;

}

void atender_urgencia(hospital_manager * h) {

    // Sacamos al paciente más urgente
    paciente * p = (paciente*) pq_poll(h->lista_urgencias);

    if (p == NULL) {
        printf("No hay pacientes en urgencias\n");
        return;
    }

    // Checar si tiene historial
    void * dato = NULL;
    if (p->historial_medico != NULL) {
        dato = stack_top(p->historial_medico);
    }

    if (dato != NULL) {
        printf("Ultima visita de %s: %s\n", p->name, (char*)dato);
    } else {
        printf("No tiene historial medico\n");
    }

    // Guardar visita actual
    stack_push(p->historial_medico, p->padecimiento);

    printf("El paciente %s fue atendido en urgencias de nivel nivel %d\n",p->name, p->urgencia);
}


void atender_consulta(hospital_manager * HM,char * especialidad) {

    doctor * D = Doc_mas_ocupado(HM,especialidad);
    
    paciente * atendiendo = (paciente *) queue_dequeue(D->fila_pacientes);

    if (atendiendo == NULL){
        printf("El doctor %s no tiene pacientes\n",D->name);

        return;
    }  

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
        printf("Nuevo paciente. Sin historial medico\n");
    }
    char * visita_actual = strdup(atendiendo->padecimiento);
    stack_push(atendiendo->historial_medico, visita_actual);
    printf("%s ha sido atendido de su enfermedad\n", atendiendo->name);
    printf("Todo gracias al doctor: %s",D->name);
}

// Funcion aux
doctor * Doc_menos_ocupado(hospital_manager * HM, char * especialidad) {
    
    List * lista = (List *) map_get(HM->lista_doctores, especialidad);

    if (lista == NULL) {
        printf("No hay doctores registrados en la especialidad: %s.\n", especialidad);
        return NULL;
    }

    doctor * doctor_menos_ocupado = NULL;
    int min_pacientes = -1; 

    doctor * doc = (doctor *) list_first(lista);
    
    while (doc != NULL) {
        // tamaño de la cola de pacientes del doctor actual
        int pacientes_en_cola = queue_size(doc->fila_pacientes); 

        // Entra el primer caso y compara con el minimo
        if (doctor_menos_ocupado == NULL || pacientes_en_cola < min_pacientes) {
            min_pacientes = pacientes_en_cola;
            doctor_menos_ocupado = doc;
        }

        // Mueve la lista
        doc = (doctor *) list_next(lista);
    }
    
    return doctor_menos_ocupado;
}

doctor * Doc_mas_ocupado(hospital_manager * HM,char * especialidad){

    List * lista = (List *) map_get(HM->lista_doctores, especialidad);

    if (lista == NULL) {
        printf("No hay doctores registrados en la especialidad: %s.\n", especialidad);
        return NULL;
    }

    doctor * doctor_mas_ocupado = NULL;
    int max_pacientes = -1; 

    doctor * doc = (doctor *) list_first(lista);
    
    while (doc != NULL) {
        // tamaño de la cola de pacientes del doctor actual
        int pacientes_en_cola = queue_size(doc->fila_pacientes); 

        // Entra el primer caso y compara con el maximo
        if (doctor_mas_ocupado == NULL || pacientes_en_cola > max_pacientes) {
            max_pacientes = pacientes_en_cola;
            doctor_mas_ocupado = doc;
        }

        // Mueve la lista
        doc = (doctor *) list_next(lista);
    }
    
    return doctor_mas_ocupado;

}



//-------------------------------------------------------------------
// Funciones para imprimir
//-------------------------------------------------------------------

void mostrar_doctores_por_especialidad(hospital_manager * HM, char * especialidad) {
    
    List * lista = (List *) map_get(HM->lista_doctores, especialidad);

    if (lista == NULL) {
        printf("No hay doctores registrados en %s.\n", especialidad);
        return;
    }

    printf("--- Doctores de %s ---\n", especialidad);
    
    
    doctor * doc = (doctor *) list_first(lista);
    
    while (doc != NULL) {
        printf("Nombre: %s, ID: %d\n", doc->name,doc->id); // Ajusta a tus campos
        
        doc = (doctor *) list_next(lista); // Pide el siguiente
    }
}
//-------------------------------------
// Funciones de destroy
//-------------------------------------


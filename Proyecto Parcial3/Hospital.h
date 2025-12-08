#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "adt_list/list.h"
#include "adt_stack/stack.h"
#include "adt_map/map.h"
#include "adt_queue/queue.h"
#include "adt_pq/pq.h"

// Definicion de los struct

typedef struct paciente_str paciente;


typedef struct doctor_str doctor;



typedef struct Hospital_Manager_str hospital_manager;

// Simplifica funciones de hash y compare
typedef int (*HashFunc)(void *t);
typedef boolean (*CompareFunc)(void * t1, void * t2);

// Funciones del archivo c
void limpiar();

void pausa();

paciente * create_paciente(int id,char nombre[],int urgencia);

doctor * create_doctor(int id, char name[], char especialidad[]);

void registrar_doctor(hospital_manager * HM, doctor * D);

hospital_manager * create_hospital_manager(int m,HashFunc hash,CompareFunc compare);

void solicitar_consulta(paciente * P, char padecimiento[], hospital_manager * HM);

void agendar_consulta(paciente * P,char padecimiento[],hospital_manager * HM);

void atender_consulta(hospital_manager * HM,char * especialidad);

void atender_urgencia(hospital_manager * h);

doctor * Doc_menos_ocupado(hospital_manager * HM, char * especialidad);

doctor * Doc_mas_ocupado(hospital_manager * HM,char * especialidad);

void contar_pacientes_wrapper(void * value); 

int get_saturacion_consultorios(hospital_manager * HM);

int get_saturacion_urgencias(hospital_manager * HM);

void mostrar_doctores_por_especialidad(hospital_manager * HM, char * especialidad);

void destroy_paciente(paciente * p);

void destroy_doctor(doctor * d);

void limpiar_lista_doctores_wrapper(void * value);

void destroy_hospital_manager(hospital_manager * hm);


#endif
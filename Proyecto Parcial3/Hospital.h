#ifndef HOSPITAL_H
#define HOSPITAL_H

typedef int boolean; 
#define TRUE 1   
#define FALSE 0

// Definicion de los struct

typedef struct paciente_str paciente;


typedef struct doctor_str doctor;



typedef struct Hospital_Manager_str hospital_manager;

// Simplifica funciones de hash y compare
typedef int (*HashFunc)(void *t);
typedef boolean (*CompareFunc)(void * t1, void * t2);

// Funciones del archivo c
void limpiar();

paciente * create_paciente(int id,char nombre[],int urgencia);

doctor * create_doctor(int id, char name[], char especialidad[]);

hospital_manager * create_hospital_manager(int m,HashFunc hash,CompareFunc compare);

void solicitar_consulta(paciente * P, char padecimiento[], hospital_manager * HM);

void atender_consulta(hospital_manager * HM,char * especialidad);

void registrar_doctor(hospital_manager * HM, doctor * D);

void mostrar_doctores_por_especialidad(hospital_manager * HM, char * especialidad);

//void destroy_hospital_manager(hospital_manager * hm);


#endif
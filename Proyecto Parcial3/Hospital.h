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


#endif
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// -h
#include "Hospital.h"

int wordHash(void *t) {
  char *key = (char *)t;
  int i, hash = 0;
  for (i = 0; i < strlen(key); i++) {
    
    hash += key[i]; 
  }
  return hash;
}

boolean wordEquals(void * t1, void * t2) {
  char *c1 = (char *)t1;
  char *c2 = (char *)t2;
  printf("comparing %s with %s\n", c1, c2);
  return strcmp(c1, c2) == 0;
}




int main(){

  hospital_manager * IMSS = create_hospital_manager(17, wordHash, wordEquals);

    doctor * d1 = create_doctor(1, "Dr. Simi", "General");
    doctor * d2 = create_doctor(2, "Dr. House", "neurologia");
    doctor * d3 = create_doctor(3, "Dr. Strange", "Cirujano");
    doctor * d4 = create_doctor(4, "Dra. Polo", "Psiquiatria"); 
    doctor * d5 = create_doctor(5, "Dr. Oogway", "General");
  

    

    registrar_doctor(IMSS, d1);
    registrar_doctor(IMSS, d2);
    registrar_doctor(IMSS, d3);
    registrar_doctor(IMSS, d4);
    registrar_doctor(IMSS, d5);

    printf("\n");
    /* Pruebas--------------------

    mostrar_doctores_por_especialidad(IMSS,"General");

    printf("\n");
    paciente * p1 = create_paciente(01,"Jorge",3);

    solicitar_consulta(p1,"General",IMSS);

    printf("\n");
    atender_consulta(IMSS,"General");
    */
    pausa();
    limpiar();

  // Declaracion variables
//-----------------------------
  int opcion=-1;
  int id_counter=100;
  int urgencia;
  char name[40];
  char padecimiento[40]; // Usado como especialidad
  char buffer[40];
  int new_doc_id = 10;
  char doc_name[40];
  char doc_esp[40];
  //-------------------------------

  while (opcion != 6)
  {
    printf("Bienvenido al IMMS\n En que te puedo ayudar?\n");
    printf("[0]- Agendar consulta\n");
    printf("[1]- Atender consulta\n");
    printf("[2]- Atender urgencia\n");
    printf("[3]- Lista de doctores disponibles por area \n"); // Por categoria
    printf("[4]- Saturacion hospital \n"); 
    printf("[5]- Dar de alta doctor \n"); 
    printf("[6]- Salir \n"); 
    scanf("%d",&opcion);

    switch (opcion)
    {
    case 0:
        printf("\n--- REGISTRO DE PACIENTE ---\n");
        printf("Nombre del Paciente: ");
        scanf("%s", name);
        printf("Nivel de Urgencia (1-10): ");
        scanf("%d", &urgencia);
        printf("Padecimiento/Especialidad (ej. General, Neurologia): ");
        scanf("%s", padecimiento);

        paciente * p = create_paciente(id_counter++, name, urgencia);
        
        // El manager decide si va a fila de espera o a urgencias
        solicitar_consulta(p, padecimiento, IMSS);
        
        pausa();
        limpiar();
      break;
    case 1:
        printf("\n--- ATENDER CONSULTA (Doctor mas ocupado) ---\n");
        printf("Ingrese la especialidad a atender: ");
        scanf("%s", buffer);

        atender_consulta(IMSS, buffer);

        pausa();
        limpiar();
      
      break;
    case 2:
        printf("\n--- ATENDER URGENCIA ---\n");
        atender_urgencia(IMSS);
        
        pausa();
        limpiar();
      
      break;
    case 3:
        printf("\n--- DIRECTORIO MEDICO ---\n");
        printf("Ingrese especialidad a consultar: ");
        scanf("%s", buffer);
        
        mostrar_doctores_por_especialidad(IMSS, buffer);

        pausa();
        limpiar();
      
      break;
    case 4:
    printf("Caso 4\n");
      
      break;
    case 5:
        printf("\n--- CONTRATACION DE DOCTOR ---\n");
        printf("Nombre del Doctor: ");
        scanf("%s", doc_name);
        printf("Especialidad: ");
        scanf("%s", doc_esp);
        
        doctor * nuevo_doc = create_doctor(new_doc_id++, doc_name, doc_esp);
        registrar_doctor(IMSS, nuevo_doc);
        
        printf("Doctor %s registrado exitosamente en %s.\n", doc_name, doc_esp);
        pausa();
        limpiar();
      
      break;
    case 6:
      printf("\nPresione enter para demoler el hospital");
      getchar(); 
      getchar(); 
      limpiar();
      destroy_hospital_manager(IMSS);  
      break;
    
    
    default:
      break;
    }
  }
  
}
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// -h
#include "Hospital.h"

int wordHash(void *t) {
  char *key = (char *)t;
  int i, hash = 0;
  for (i = 0; i < strlen(key); i++) 
  {
    hash += (key[i] - 'a');
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
  paciente * p1 = create_paciente(01,"Jorge",10);
  doctor * d1 = create_doctor(9,"Alberto");

  solicitar_consulta(p1,"Anemia",d1);

  //atender_consulta(d1);
  getchar();

  solicitar_consulta(p1,"SIda",d1);

 // atender_consulta(d1);

}
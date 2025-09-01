/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01();
void ex02();
void upper_to_lower(char*);
void ex03();
//void ex04();

int main()
{

  ex01();
  printf("-----------------------------------------------------------------------------------------------\n");
  ex02();
  printf("-----------------------------------------------------------------------------------------------\n");
  ex03();

  return 0;
}


void ex01()
{

  int array [10] = {10,3,8,9,8,9,10,6,5,8};

  int * ptr_array = array;

  for (int i = 0; i<10; i++ ){

    printf("num de elemento = %d | valor = %d | direccion = %p, \n",(i+1), *(ptr_array+i), (ptr_array+i));

  }

}

void ex02()
{

  char name[400];

  strcpy(name,"Prueba01");

  char *nameptr = name;

  int i  = 0;

  for (i ; i<(sizeof(name)); i++){
    
    if ((*(nameptr+i)) =='\0'){
      break;
    }
    i++;
  }

  int ret = i;
  printf("Tamano del string = %d", ret);
  
}

void ex03()
{

  char array [] = {'H','o','l','a',' ','M','u','n','d','o',};

  char * ptr_array = array;

  printf("tamano array: %d\n",(sizeof(array)/sizeof(array[10])));

  for (int i = 0; i<((sizeof(array)/sizeof(array[0]))-1); i++ ){
      if(65<(*(ptr_array)) && (*(ptr_array))<90){
        *ptr_array += 32; 
      }
      printf("%c",*ptr_array);
  }

}
/* Exercise 04

  Implement an isBinary function that receives a string and determines
  if its a binary number (must be formed of only 1s and 0s).
*/
  

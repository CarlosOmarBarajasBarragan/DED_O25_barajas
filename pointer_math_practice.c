/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01();
void ex02();
void upper_to_lower(char*);
void ex03();
void ex04();

int main()
{

  ex01();
  printf("-----------------------------------------------------------------------------------------------\n");
  ex02();
  printf("-----------------------------------------------------------------------------------------------\n");
  ex03();
  printf("-----------------------------------------------------------------------------------------------\n");
  ex04();

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
  printf("Tamano del string = %d\n", ret);
  
}

void ex03()
{

  char array [] = {'H','o','l','a',' ','M','u','n','d','o',};

  char * ptr_array = array;

  int len = (sizeof(array)/sizeof(array[0]));

  for (int i = 0; i<len; i++ ){
      if(('A'<(*ptr_array)) && ((*ptr_array)<'Z')){
        *ptr_array += 32; 
      }

      printf("%c",*ptr_array);
      ptr_array++;
  }
  printf("\n");
}
/* Exercise 04

  Implement an isBinary function that receives a string and determines
  if its a binary number (must be formed of only 1s and 0s).
*/
  
void ex04()
{

  char array [] = "01a10";

  char * ptr_array = array;

  int len = sizeof(array);


  for (int i = 0; i<(len-1); i++ ){
      if(*ptr_array=='\0'){
        continue;
      }
      if(((*ptr_array) != '1') && ((*ptr_array) != '0')){
             printf("no es binario, %c no es 0 ni 1\n",*ptr_array);
      }
      
 
      ptr_array++;
  }
 printf("%s si es binario\n", array);
}
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR printf("\033[0;0H\033[2J");

void ex01();
void ex02();
void upper_to_lower(char*);
//void ex03();
//void ex04();

int main()
{

  ex01();
 
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

  /* Excercise 02:
  Implement a function mylenght() that returns the size of the passed 
  string (char array). DO NOT USE strlen(), use only pointer arithmetic.

  DO NOT USE BRACKETS [ ]

  TIP: all strings are array of chars, terminated by '\0' character.
*/

void ex02()
{

  char name[400];
  int ret;
  
  //TRY ME HERE:

}

/* More practice excerises (similar to Ex02)

  NOTA :  DO NOT USE [BRACKETS] in any function
  
  Excercise 03
  Implement a function that receives an array, traverses the array
  chaging all letters in CAPs to Lowercase.
  The array must be printed in the main loop to verify the results.
  TIP: See ASCII table
  
*/

/* Exercise 04
  Implement an isBinary function that receives a string and determines
  if its a binary number (must be formed of only 1s and 0s).
*/
  

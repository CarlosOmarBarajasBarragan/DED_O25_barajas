#include <stdio.h>

/* 
  Excercise 1 : swap
  Create a function that "swaps" the contents of two variables.
  It should receive two intengers, return nothing and after it execution
  whatever what inside one variable should be inside the other and viceversa 
*/

/* Excercise 2 : blackjack

Create a blackjack function that:
  -receives 2 numbers and a FLAG (char)
  -returns 1 if the sum of the numbers is positive (greater than 0).
  -returns 0 if the sum of the numbers is negative.
  -Stores the sum of the two numbers in number2.
  -If the sum is 21, set the FLAG to = 'W' (winner)
*/

void swap(int * n1,int * n2){

int temp;

temp = *n1;
*n1 = *n2;
*n2 = temp;

}

void blackjack(int * n1,int * n2, char * game){

  *n2 = *n1 + *n2;

    if (*n2 > 0){

      *game = '1';

      if (*n2 == 21){
        *game = 'W';

      }
    }
    else {
    
      *game = '0';

    }

}

int main()
{

  /* Exercise 1:  swap num1 and num2 value */
  int num1 = 1;
  int num2 = 24;

  int * ptr1 = &num1;
  int * ptr2 = &num2;

  swap ( ptr1 , ptr2);  

  //Validate that the numbers were swaped:
  printf("num1 = %d num2 = %d\n", num1, num2);

  /* Exercise 2:  Blackjack 
    Call and test your program here */
  char flag = '0';  //init value

  char * ptrflag = &flag;

  blackjack(ptr1,ptr2, ptrflag);

  printf("Valor final = %d Resultado = %c", num2,flag);

  int result; 
  
  
  return 0;
}
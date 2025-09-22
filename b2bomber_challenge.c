#include <stdio.h>
#include <string.h>
/* 
  Mini challenge, so we can test how hackerrank work
  to solve this you need to understand:
  arrays, void pointers and pointers
  
*/

void excercise01();
void excercise02();
void plane_to_car();

int main()
{
  char student[40] = "Carlos Omar Barajas Barragán";
  char short_name[20] = "Barajas";
  printf("Hellow world, my name is %s and this is my exam\n", student);
  printf("The professor just calls me: %s\n", short_name);

  printf("-------ex 01 ----------\n");
  excercise01();
  printf("\n-------ex 02 ----------\n");
  excercise02();
}



void excercise01()
{
  //Convert the following FOR loop, so it DOES NOT use brackets [ ].
  //if done correctly the screen should still print:
  /* 
  -------ex 01 ----------
  10 9 8 7 6 5 4 3 2 1

  */
  int numbers[10] = {10,9,8,7,6,5,4,3,2,1};
  
  int * i_ptr = numbers;

  for(int i = 0; i<10; i++)
  {
    printf("%d ", *(i_ptr+i));
  }
  return;
}

void plane_to_car(void ** v_array){

  char * c = v_array[0];

  *c = 'F';
  *(char*) v_array[1] = 1;
  strcpy(v_array[2],"Car");


};

void excercise02()
{
  char letter = 'B';
  int num2 = 2;
  char name[20] = "Bomber";

  char * c_ptr = &letter;
  int * i_ptr = &num2;
  char * s_ptr = name;

  // a B2 Bomber from US ARMY!! Love that plane

  /* Create an array that contains all 3 components above:
    [0] the Letter
    [1] the Number
    [2] the name 

    Notice how each element is of different type! how do we make arrays of
    different types? is it even possible?

  Create a function plane_to_car() that returns nothing (void) and receives
  only this misterious new array. T
  
  he function should Convert our "B2 Bomber" into
  an "F1 Car" */

  // Create you array and CALL YOUR FUNCTION HERE:
  // START :
void * v_ptr = plane_to_car;

void *v_array[3] = {c_ptr,i_ptr,s_ptr}; 

plane_to_car(v_array);

  
  // END :
  
  // IF done right, the following should print "F1 Car"
  // DO NOT MODIFY this print, notice how are printing the original variables?
  // there must be away our array store its references, and not its values.
  
  printf("%c%d %s\n", letter, num2, name);
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lets create a 2D INT matrix of 5 columns and 3 rows 
    [1, 2, 3, 4,  5]
    [6, 7, 8, 9, 10]
    [11,12,13,14,15] 

    Don't forget to free it!
   */   

int main()
{
  // step # 1. create the double pointer that will be used to reference to
  // the 2D matrix
  
  int ** imtx_ptr;

  // step #2 . allocate enough memory for the rows (what is the data type?)
  
  imtx_ptr = (int **) malloc(sizeof(int*)*3);

  // step #3 . for each one of the rows, allocate enough memory for the columns

  for (int i = 0; i<3; i++){
    imtx_ptr[i] = (int *)malloc(sizeof(int)*5);
  }

  // step #4 . verify that the 2D matrix works as usual, just as you saw in the
  // previous semesters, you can use brackets [ ] fill matrix and print to test 
  
  //fill it

  int value = 1;

  for (int x = 0; x<3;x++){
    for (int y = 0; y<5;y++){
      imtx_ptr[x][y] = value++;
    }
  }

  //print
  for (int x = 0; x<3;x++){
    for (int y = 0; y<5;y++){
      printf("%d ",imtx_ptr[x][y]);
    }
    printf("\n");
  }

  for (int i= 0; i<3;i++){
    free(imtx_ptr[i]);
  }
    free(imtx_ptr);


  /* Can you do the same to store the following :

  ["WELCOME"]                len = 8
  ["TO"]                     len = 3 
  ["DATA STRUCTURE CLASS"]   len = 21

  */

  char ** cmtx_ptr;
  cmtx_ptr = (char**)malloc(sizeof(char*)*3);

  
  cmtx_ptr[0] = (char*)malloc(sizeof(char)*8);
  cmtx_ptr[1] = (char*)malloc(sizeof(char)*3);
  cmtx_ptr[2] = (char*)malloc(sizeof(char)*21);
  


  strcpy(cmtx_ptr[0],"WELCOME");
  strcpy(cmtx_ptr[1],"TO");
  strcpy(cmtx_ptr[2],"DATA STRUCTURE CLASS");


  /* can you print it using pointer math :) ? */

for (int i = 0; i<3;i++){

  char *current_string = *(cmtx_ptr + i);
      
  char *char_ptr = current_string;
  while (*char_ptr != '\0') {
  printf("%c",*char_ptr);
    char_ptr++;
  }
}

  /* can you print it with brackers [] ? */

  

  /* FREE everything we just created */

  free(cmtx_ptr[0]);
  free(cmtx_ptr[1]);
  free(cmtx_ptr[2]);
  
  free(cmtx_ptr);

}
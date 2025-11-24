#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Malloc / Free 

  Use only dynamic memory for this excercise.
  Remember, for EVERY malloc, there must exist a free */

int main()
{
  /* 1) create an int, and assign the value 10 to it. Print it to be sure */
 // this is static, not this

  int * i_ptr = NULL;
  i_ptr = (int*) malloc (sizeof(int));
  *i_ptr = 19;
  
  printf("Valor de i_ptr = %d direccion de i_ptr = %p\n", *i_ptr, &i_ptr);

  getchar();

  /* 2) create an array of 10 integers  */
  // this is static, not this

  int * iarr_ptr = NULL;
  iarr_ptr = (int*) malloc (sizeof(int)*10);


  /* 2.1) fill every space with random numbers  */
  //verify with a print
 
  for (int i = 0; i<10; i++){
    iarr_ptr[i] = (0+i);
  }

  for (int j = 0; j<10; j++){
      printf("Valor de iarr_ptr = %d direccion de iarr_ptr = %p\n", *(iarr_ptr+j), (iarr_ptr+j));
  }

  getchar();

  /* 3) Create an array with 20 chars, and put your name in it, (request it to the user)
        and print it  */
  char name_s[20] = {"Ramiro"};   // this is static, not this


  char * c_ptr = NULL;

  c_ptr = (char*)malloc(sizeof(char)*20);

  char * carr_ptr = c_ptr;

  printf("Ingresa tu nombre: ");
  scanf("%s",c_ptr);

  printf("Contenido del array = %s direccion de carr_ptr = %p\n", c_ptr, (carr_ptr));
  } 



  //malloc


  /* 3.1 print it */

  /* before this simple program complete. What do we need to do? 
    Remember the golden rule! */
  
  // destroy the memory for the integer create at 1)

  // destory the memory for the array of integers created at 2)

  // destroy the memory for the array that contained your name.


  /* and who will release the memory for the pointers? We don't! because all
  of our pointers, were created with STATIC memory and the program will free that
  memory for us as soon as the scope of the variable ends. */

  #include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *ptr_malloc;
    int *ptr_calloc;

    // --- 1. Usando malloc ---
    // Pedimos 5 * sizeof(int) bytes
    ptr_malloc = (int*)malloc(n * sizeof(int));
    
    if (ptr_malloc == NULL) {
        printf("Fallo malloc\n");
        return 1;
    }

    printf("Contenido de ptr_malloc (basura):\n");
    for (int i = 0; i < n; i++) {
        // Esto imprimirá valores impredecibles (basura)
        printf("ptr_malloc[%d] = %d\n", i, ptr_malloc[i]);
    }

    printf("\n----------------------------------\n\n");

    // --- 2. Usando calloc ---
    // Pedimos 5 elementos, cada uno de sizeof(int)
    ptr_calloc = (int*)calloc(n, sizeof(int));
    
    if (ptr_calloc == NULL) {
        printf("Fallo calloc\n");
        free(ptr_malloc); // No olvides liberar la memoria anterior
        return 1;
    }

    printf("Contenido de ptr_calloc (ceros):\n");
    for (int i = 0; i < n; i++) {
        // Esto imprimirá 0 en todos los casos
        printf("ptr_calloc[%d] = %d\n", i, ptr_calloc[i]);
    }

    // --- 3. Liberar memoria ---
    free(ptr_malloc);
    free(ptr_calloc);

    return 0;
}
  /* ==================================================================== */

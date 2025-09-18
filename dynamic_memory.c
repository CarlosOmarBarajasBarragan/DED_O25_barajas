#include <stdio.h>
#include <stdlib.h>

void prueba (){

    printf("Hola mundo\n");
}



int main(){

    int n = 20;
    int n2;

    char L = 'a';

    char * c_ptr;

    c_ptr = (char*)malloc(20 * sizeof(char));

    printf("Direccion de n= %p\n", &n);
    printf("Direccion de n2= %p\n", &n2);
  

    printf("Direccion de L= %p\n", &L);
    printf("Direccion de c_ptr= %p\n", &c_ptr);
    printf("Contenido de c_ptr= %p\n", c_ptr);

    printf("Direccion de c_ptr[0]= %p\n", &c_ptr[0]);
    printf("Direccion de c_ptr[1]= %p\n", &c_ptr[1]);
    printf("Direccion de c_ptr[2]= %p\n", &c_ptr[2]);
    
    printf("Direccion de main= %p\n", &main);
    printf("Direccion de prueba= %p\n", &prueba);


    printf("---------------------------------------------------------------------\n");

    int * i_ptr = NULL;

    for (int i = 0; i <10; i++){
    i_ptr = (int*)malloc(64*sizeof(int));
    i_ptr[10] = 5000;

    printf("Direccion de i_ptr= %p\n", &i_ptr);
    printf("Direccion de i_ptr[10]= %p\n", &i_ptr[10]);
    printf("Contenido de i_ptr[10]= %d\n", i_ptr[10]);




    
    }




    return 0;
}
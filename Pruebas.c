#include <stdio.h>

void main() {
    int array[] = {4, 9, 1, 9, 2, 9};
    
    int n = sizeof(array) / sizeof(array[0]);


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Arreglo ordenado: ");
    for (int k = 0; k < n; k++) {
        printf("%d", array[k]);
    }
    printf("\n");
}

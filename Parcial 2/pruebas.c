#include <stdio.h>

/**
 * @brief Resuelve el problema de las Torres de Hanói de forma recursiva.
 * * @param n El número de discos a mover.
 * @param varilla_origen El carácter que representa la varilla de inicio (ej. 'A').
 * @param varilla_destino El carácter que representa la varilla de destino (ej. 'C').
 * @param varilla_auxiliar El carácter que representa la varilla auxiliar (ej. 'B').
 */
void torresDeHanoi(int n, char varilla_origen, char varilla_destino, char varilla_auxiliar) {
    // Mostrar los parámetros de la llamada actual
    printf("[Llamada] torresDeHanoi(n=%d, origen=%c, destino=%c, auxiliar=%c)\n",
           n, varilla_origen, varilla_destino, varilla_auxiliar);

    // Caso base: si solo hay un disco, se mueve directamente al destino.
    if (n == 1) {
        printf("Mover disco 1 de la varilla %c a la varilla %c\n",
               varilla_origen, varilla_destino);
        return;
    }
    
    // Paso 1: mover n-1 discos a la auxiliar
    torresDeHanoi(n - 1, varilla_origen, varilla_auxiliar, varilla_destino);
    
    // Paso 2: mover el disco grande
    printf("Mover disco %d de la varilla %c a la varilla %c\n",
           n, varilla_origen, varilla_destino);
    
    // Paso 3: mover los n-1 discos al destino
    torresDeHanoi(n - 1, varilla_auxiliar, varilla_destino, varilla_origen);
}


int main() {
    // Número de discos para el juego. Puedes cambiar este valor.
    int numero_de_discos = 10; 
    
    // Se llama a la función principal con las varillas A (Origen), C (Destino) y B (Auxiliar).
    printf("Solucion para las Torres de Hanoi con %d discos:\n", numero_de_discos);
    torresDeHanoi(numero_de_discos, 'A', 'C', 'B'); 
    
    return 0;
}
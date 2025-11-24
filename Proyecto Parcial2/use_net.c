#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDA_Queue/queue.h"
#include "net.h"

//compile:
/*
gcc use_net.c net.c TDA_Queue/queue.c -o use_net  
*/


void menu() 
{
    printf("\n====== SOCIAL NETWORK MENU ======\n");
    printf("1. Agregar usuario\n");
    printf("2. Eliminar usuario\n");
    printf("3. Seguir a otro usuario\n");
    printf("4. Mostrar red completa\n");
    printf("5. Mostrar solo hombres\n");
    printf("6. Mostrar solo mujeres\n");
    printf("7. Guardar red en archivo CSV\n");
    printf("8. Agregar publicación pendiente\n");
    printf("9. Procesar publicación pendiente\n");
    printf("0. Salir\n");
    printf("=================================\n");
    printf("Opción: ");
}

int main()
{

    net feis = net_create();
    if(!net_readFromFile(feis, "red.txt", "friends.txt"))
    {
        fprintf(stderr, "ERROR: Could not read from file\n");
    }

    //ejemplo del profe
    // net_addUser(feis, "Juan", 22, 'H');
    // net_addUser(feis, "Maria", 18, 'M');
    // net_addUser(feis, "Ana", 23, 'M');
    // net_addUser(feis, "Jose", 21, 'H');
    // net_follow(feis, "Juan", "Maria");
    // net_follow(feis, "Juan", "Jose");
    // net_follow(feis, "Juan", "Ana");
    // net_follow(feis, "Ana", "Maria");
    // net_follow(feis, "Jose", "Ana");
    // net_follow(feis, "Jose", "Maria");


    printf("Network read from file:\n");
    net_print(feis, FULL);

    printf("\n\n");
    net_print(feis, BOYS);

    printf("\n\n");
    net_print(feis, GIRLS);

    net_toTextFile(feis, "facebook.csv");


    int opcion;
    char username[30];
    char username2[30];
    int edad;
    char genero;
    char filename[50];


    queue cola_publicaciones = queue_create(); //cola para manejar las solicitudes de publicacion

    do 
    {
        menu();
        scanf("%d", &opcion);
        getchar(); //limpiar salto de linea del buffer de entrada

        switch (opcion) 
        {
            case 1:
                printf("Nombre de usuario: ");
                scanf("%s", username);
                printf("Edad: ");
                scanf("%d", &edad);
                printf("Género (H/M): ");
                scanf(" %c", &genero);

                if (net_addUser(feis, username, edad, genero))
                    printf("Usuario agregado correctamente.\n");
                else
                    printf("Error: no se pudo agregar el usuario.\n");
                break;

            case 2:
                printf("Nombre de usuario a eliminar: ");
                scanf("%s", username);
                if (net_delUser(feis, username))
                    printf("Usuario eliminado correctamente.\n");
                else
                    printf("Error: usuario no encontrado.\n");
                break;

            case 3:
                printf("Usuario que sigue: ");
                scanf("%s", username);
                printf("Usuario a seguir: ");
                scanf("%s", username2);

                if (net_follow(feis, username, username2))
                    printf("%s ahora sigue a %s.\n", username, username2);
                else
                    printf("No se pudo realizar la acción.\n");
                break;

            case 4:
                net_print(feis, FULL);
                break;

            case 5:
                net_print(feis, BOYS);
                break;

            case 6:
                net_print(feis, GIRLS);
                break;

            case 7:
                printf("Nombre del archivo CSV: ");
                scanf("%s", filename);
                net_toTextFile(feis, filename);
                printf("Archivo guardado exitosamente.\n");
                break;

            //agregar publicacion pendiente   
            case 8: {
                printf("Usuario que realiza la publicación: ");
                scanf("%s", username);
                user u = findUser(feis, username);
                if (u == NULL) 
                {
                    printf("Error: usuario no encontrado.\n");
                } 
                else 
                {
                    char* copy = strdup(username);
                    queue_enqueue(cola_publicaciones, copy);
                    printf("Publicación pendiente agregada por %s.\n", copy);
                }
                break;
            }

            // procesar publicación pendiente
            case 9: 
            {
                if (queue_isEmpty(cola_publicaciones)) 
                {
                    printf("No hay publicaciones pendientes.\n");
                } 
                else 
                {
                    char* username = (char*)queue_dequeue(cola_publicaciones);
                    printf("Procesando publicación de %s...\n", username);
                    printf("Publicación aprobada y publicada.\n");
                    free(username);
                }
                break;
            }

            case 0:
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción no válida.\n");
                break;
        }

    } while (opcion != 0);

    while (!queue_isEmpty(cola_publicaciones)) 
    {
        char* pending = (char*) queue_dequeue(cola_publicaciones);
        free(pending);
    }
    queue_destroy(cola_publicaciones);


    net_destroy(feis);


    return 0;
}
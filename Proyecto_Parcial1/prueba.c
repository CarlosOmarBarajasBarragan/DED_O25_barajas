
void magia_set(pokemon * battle_ptr, void (magia_array)(void*, void*), char **magia_names, int contador) {

    if ((battle_ptr+contador)->id == 0){
        for (int j = 2 ; j<4; j++){
            while(*((battle_ptr+contador)->action + j) ==NULL)
                printf("--- Escoge una Magia ---\n");

                for (int i = 0; i < 5; i++) {

                    printf("%d. %s\n", i, *(magia_names + i));

                }

                int magia_escogida;
                int magia_anterior = -1;

                printf("Jugador, escoge tu magia: ");

                scanf("%d", &magia_escogida);

                if (magia_escogida == magia_anterior){
                    printf("La opción %d ya fue seleccionada", magia_anterior);
                }
                else{
                    *((battle_ptr+contador)->action + j) = *(magia_array + magia_escogida);
                    magia_anterior = magia_escogida;
                }
    }

    else{
    // Bot elige magia


    for (j = 2 ; j<4; j++){
    while(*((battle_ptr+contador)->action + j) ==NULL)

    printf("--- Escoge una Magia ---\n");

    for (int i = 0; i < 5; i++) {

    printf("%d. %s\n", i, *(magia_names

    + i));

    }

    int magia_escogida;
    int magia_anterior = -1;

    magia_escogida = rand()%1;// %3

    if (magia_escogida == magia_anterior){
        printf("La opción %d ya fue seleccionada", magia_anterior);
    } 
    else{
        *((battle_ptr+contador)->action + j) = *(magia_array + magia_escogida);
         magia_anterior = magia_escogida;
    }
    }
    
    }

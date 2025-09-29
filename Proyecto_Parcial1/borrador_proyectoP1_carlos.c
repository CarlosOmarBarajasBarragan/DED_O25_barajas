#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


/*------- Version 28/09/2025 4:31 pm-------*/


typedef struct pokemon{
    char name[20];
    int hp;
    int id;
    int dormir;
    int conta_dormir;
    int defensa;
    int conta_defensa;
    int veneno; 
    int conta_veneno;
    int regeneracion;
    int conta_regeneracion;
    int furia;
    int conta_furia;
    void (*action[4])(void * pokemon_jugador, void * pokemon_enemigo);
}pokemon;

char* mostrar_turno(int turno){
    if (turno %2 == 0){
        return "Rival";
    }
    else{
        return "Jugador";
    }
}

int diferenciador (int definir_turno){
    if (definir_turno == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void attack(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    if (enemigo->defensa == 1)
    {
        enemigo->hp-=5;
    } else if (jugador->furia ==1)
    {
        enemigo->hp-=15;
        printf("%s (%s) esta furioso y hara mas danio \n", jugador->name, mostrar_turno(diferenciador(jugador->id)));
        printf("\n");
    }else{
        enemigo->hp-=10;
    } 
    printf("%s (%s) ataco a %s (%s)\n", jugador->name, mostrar_turno(diferenciador(jugador->id)), enemigo->name, mostrar_turno(diferenciador(enemigo->id)));
    printf("%s (%s) tiene ahora %d HP\n", enemigo->name, mostrar_turno(diferenciador(enemigo->id)), enemigo->hp);
}

void block(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso defensa ferrea, %s aumento su defensa \n", jugador->name, mostrar_turno(diferenciador(jugador->id)), jugador->name);
    jugador->defensa=1;
    jugador->conta_defensa=2;

}

void veneno(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso polvo veneno en %s (%s), ha sido envenenado \n", jugador->name, mostrar_turno(diferenciador(jugador->id)), enemigo->name,mostrar_turno(diferenciador(enemigo->id)));
    enemigo->veneno=1;
    enemigo->conta_veneno=3; // Dura 3 turnos el veneno
    
}

void dormir(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso bostezo en %s (%s), ha caido dormido \n", jugador->name, mostrar_turno(diferenciador(jugador->id)), enemigo->name,mostrar_turno(diferenciador(enemigo->id)));
    enemigo->dormir=1;
    enemigo->conta_dormir=2;// Duerme 2 turnos

}

void regen(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso arraigo,%s (%s) empezara a recuperar hp \n", jugador->name, mostrar_turno(diferenciador(jugador->id)), jugador->name,mostrar_turno(diferenciador(jugador->id)));
    jugador->regeneracion =1;
    jugador->conta_regeneracion=3;
}

void furia(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso furia, %s esta enojado , su ataque se ve incrementado \n", jugador->name, mostrar_turno(diferenciador(jugador->id)), jugador->name);
    jugador->furia=1;
    jugador->conta_furia=4; // Dura 3 turnos la furia
    
}

void suerte(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;
    int num_random= rand()%11;
    int num_escogido=-1;
    if (jugador->id == 0)
    {
        printf("%s (%s) Quiere probar su suerte \n", jugador->name, mostrar_turno(diferenciador(jugador->id)));
        printf("Elige un numero entre el 0 y 10 , si lo adivinas pasara algo bueno\n");
        scanf("%d",&num_escogido);
        if (num_escogido == num_random)
        {
            printf("Estas de suerte, tu pokemon se recupero al maximo\n");
            jugador->hp=100;
        }else
        {
            printf("Mala suerte el numero era %d, suerte a la proxima\n",num_random);
        }
    }else{
        printf("%s (%s) Quiere probar su suerte \n", jugador->name, mostrar_turno(diferenciador(jugador->id)));
        printf("Elige un numero entre el 0 y 10 , si lo adivinas pasara algo bueno\n");
        num_escogido = rand()%11;
        if (num_escogido == num_random)
        {
            printf("Estas de suerte, tu pokemon se recupero al maximo\n");
            jugador->hp=100;
        }else
        {
            printf("Mala suerte el numero era %d, suerte a la proxima\n",num_random);
        }
        getchar();

    }

}

void magia_set(pokemon* battle_ptr, void (**magia_array)(void*, void*), char** magia_names, int contador) {
    
    
    int magia_anterior = -1;
    int magia_escogida;

    if ((battle_ptr + contador)->id == 0) { // jugador
        // LLena las magias
        for (int j = 2; j < 4; j++) {
            // Bucle para pedir una opción hasta que sea válida.
            do {
                printf("\n--- Escoge la Magia para el espacio %d ---\n", j);
                for (int i = 0; i < 5; i++) {
                    printf("%d. %s\n", i, *(magia_names + i));
                }

                printf("Jugador, escoge tu magia: ");
                scanf("%d", &magia_escogida);
                fflush(stdout); 

                if (magia_escogida == magia_anterior) {
                    printf("Ya has escogido esa magia. Elige otra.\n");
                    while (getchar() != '\n'); // Se limpia el buffer
                }
            } while (magia_escogida == magia_anterior); 

            (battle_ptr + contador)->action[j] = magia_array[magia_escogida];
            
            magia_anterior = magia_escogida;
            printf("\n");
            printf("Magia '%s' asignada con exito.\n", *(magia_names + magia_escogida));
        }
    }
    else{
    // Bot elige magia
    printf("---Magia escogida por el bot---\n");
    printf("\n");

       for (int j = 2; j < 4; j++) {

            do {
               magia_escogida = rand()%5;
            } while (magia_escogida == magia_anterior); 
            
            (battle_ptr + contador)->action[j] = magia_array[magia_escogida];
            
            magia_anterior = magia_escogida;
            printf("Magia '%s' asignada con exito.\n", *(magia_names + magia_escogida));
        }
    }
}


void pokemon_set(pokemon * battle_ptr,pokemon * pokedex_pointer, void (**magia_array)(void*, void*), char **magia_names){

    int pokemon_escogido=-1;
    pokemon * pokemon_nombres = pokedex_pointer;
    
    for (int i = 0; i < 5; i++,pokemon_nombres++)
    {
        printf("[%d]-- %s \n",i,(pokemon_nombres->name));
    }
    

    while (pokemon_escogido <0 || pokemon_escogido >= 5)
    {
        printf("Jugador escoge tu pokemon\n");
        scanf("%d", &pokemon_escogido);
        fflush(stdout);
    }
    

    for (int i= 0; i<2; i++){//3
    
        *(battle_ptr+i) = *(pokedex_pointer+pokemon_escogido);
        (battle_ptr+i)->id = i;
        
        magia_set(battle_ptr,magia_array,magia_names,i); 
        printf("\n");

        pokemon_escogido = rand()%5;// Siempre pikachu para prueba
    }

}

void pokemon_preview(pokemon * battle_ptr){
    printf("Preview pokemons:\n");

    printf("Pokemon Aliado: %s\n",(battle_ptr)->name);
    printf("Salud propia: %d\n",(battle_ptr)->hp);


    printf("Pokemon enemigo: %s\n",(battle_ptr+1)->name);
    printf("Salud enemigo: %d\n",(battle_ptr+1)->hp);
  

   printf("--------------------------------\n");
   printf("\n");
}

void limpiar_pantalla(){
    system("cls");
}

void presentacion(){
    printf("-----PokeBattle-----\n");
    printf("Presiona enter para continuar y empezar a pelear\n");
    getchar();
}

void final(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    if (jugador->hp <= 0)
    {
        printf("%s (%s) se ha debilidato, %s (%s) gana la batalla \n", jugador->name, mostrar_turno(diferenciador(jugador->id)), enemigo->name,mostrar_turno(diferenciador(enemigo->id)));
        printf("---Perdiste---\n");
        getchar();
    }else{
        printf("%s (%s) se ha debilidato, %s (%s) gana la batalla \n", enemigo->name, mostrar_turno(diferenciador(enemigo->id)), jugador->name,mostrar_turno(diferenciador(jugador->id)));
        printf("---Ganaste---\n");
        getchar();
    }

    
    
    
    
}
char * nombre_magia(pokemon * battle_ptr,int lugar) {
    void (*magia_actual)(void*, void*) = battle_ptr->action[lugar];

    // Comparamos ese puntero con las funciones de magia que conocemos
    if (magia_actual == veneno) {
        return "Veneno"; // Si es la función 'veneno', devolvemos el texto "Veneno"
    }
    else if (magia_actual == dormir) {
        return "Dormir";
    }
    else if(magia_actual == regen){
        return "Regeneracion";
    }else if (magia_actual == furia)
    {
        return "Furia";
    }else if (magia_actual == suerte)
    {
        return "Suerte";
    }
    return NULL;
}

int main(){
    
    srand(time(NULL));

    

   pokemon Pikachu = {
        .name = "Pikachu",
        .defensa = 0,
        .conta_defensa = 0,
        .dormir = 0,
        .conta_dormir =0,
        .veneno = 0,
        .conta_veneno =0,
        .regeneracion =0,
        .conta_regeneracion=0,
        .furia=0,
        .conta_furia=0,
        .hp = 100,
        .action = { attack, block,NULL,NULL}
    };

    pokemon Charmander = {
        .name = "Charmander",
        .defensa = 0,
        .conta_defensa = 0,
        .dormir = 0,
        .conta_dormir =0,
        .veneno = 0,
        .conta_veneno =0,
        .regeneracion =0,
        .conta_regeneracion=0,
        .furia=0,
        .conta_furia=0,
        .hp = 100,
        .action = { attack, block,NULL,NULL}
    };

    pokemon Squirtle = {
        .name = "Squirtle",
        .defensa = 0,
        .conta_defensa = 0,
        .dormir = 0,
        .conta_dormir =0,
        .veneno = 0,
        .conta_veneno =0,
        .regeneracion =0,
        .conta_regeneracion=0,
        .furia=0,
        .conta_furia=0,
        .hp = 100,
        .action = { attack, block,NULL,NULL}
    };

    pokemon Bulbasur = {
        .name = "Bulbasur",
        .defensa = 0,
        .conta_defensa = 0,
        .dormir = 0,
        .conta_dormir =0,
        .veneno = 0,
        .conta_veneno =0,
        .regeneracion =0,
        .conta_regeneracion=0,
        .furia=0,
        .conta_furia=0,
        .hp = 100,
        .action = { attack, block,NULL,NULL}
    };

    pokemon Mewtwo = {
        .name = "Mewtwo",
        .defensa = 0,
        .conta_defensa = 0,
        .dormir = 0,
        .conta_dormir =0,
        .veneno = 0,
        .conta_veneno =0,
        .regeneracion =0,
        .conta_regeneracion=0,
        .furia=0,
        .conta_furia=0,
        .hp = 100,
        .action = { attack, block,NULL,NULL}
    };


    pokemon battle [2];
    pokemon * battle_ptr = battle;


    
    void (*magia_array[5])(void*, void*) = {veneno, dormir, regen, furia, suerte};
    char magia_1[30] ="Veneno";
    char magia_2[30] = "Dormir";
    char magia_3[30] = "Regeneracion";
    char magia_4[30] = "Furia";
    char magia_5[30] = "Suerte";
    char *nombres_magia[]={magia_1,magia_2,magia_3,magia_4,magia_5};
    char **ptr_magia=nombres_magia;

   pokemon pokedex [5]={Pikachu,Charmander,Squirtle,Bulbasur,Mewtwo};
   pokemon * pokedex_ptr = pokedex;

   // Presentacion

    presentacion();
       
   // Establece los pokemones
    pokemon_set(battle_ptr,pokedex_ptr, magia_array,ptr_magia);

       // Declara nombres ataques
    char atq1[30] ="Ataque";
    char atq2[30] = "Defensa";
    char atq3[30] = ".";
    char atq4[30] = ".";
    char *nombres_ataques[]={atq1,atq2,atq3,atq4};
    char **ptr_nombres=nombres_ataques;
    int constante =1, turno = 1, opcion_atque =-1;



    // Solo muestra los pokemones
   pokemon_preview(battle_ptr);
   printf("Presiona enter para continuar\n");
   getchar();
   getchar();
   limpiar_pantalla();

   // Declaración de contadores
   // Jugador
  



    while (battle[0].hp>0 && battle[1].hp>0){ 

        // Hacer que se limpie la terminal, que se vea bonito
       limpiar_pantalla();

        int definir_turno = (turno%2);

        printf("Detalles de la partida: \n");

        printf("(Jugador) %s Salud : %d\n",(battle)->name, (battle)->hp);
        
        printf("(Enemigo) %s Salud : %d\n",(battle+1)->name, (battle+1)->hp);

        ptr_nombres=nombres_ataques;

         
        
        if (definir_turno == 1){
             
            printf("\n");
            printf("Turno (%s)\n",mostrar_turno(definir_turno));

            // Revisamos dormir
            if (battle->dormir ==1){
                battle->conta_dormir--;
                printf("%s (%s) esta profundaente dormido, %s pierde el turno \n",battle->name,mostrar_turno(definir_turno),battle->name);
                getchar();
                if (battle->conta_dormir<= 0){
                    printf("%s (%s) se ha despertado, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno));
                    battle->dormir =0;
                    getchar();
                }
            } else{

                printf("(%s) elige el ataque de tu %s:\n",mostrar_turno(definir_turno),(battle_ptr)->name);
                strcpy(atq3, nombre_magia(battle_ptr,2));
                strcpy(atq4, nombre_magia(battle_ptr,3));
                for (int i = 0; i < 4; i++,ptr_nombres++)
                {
                    printf("%d. %s\n",i,*ptr_nombres);
                }
                scanf("%d",&opcion_atque);
                printf("\n");
                battle[diferenciador(definir_turno)].action[opcion_atque]((battle_ptr+diferenciador(definir_turno)),(battle_ptr+definir_turno));

                printf("Presiona enter para continuar\n");
                getchar();
                getchar();
                printf("Estados activos: \n");
                // Evaluamos defensa
                if (battle->defensa ==1) 
                {
                    battle->conta_defensa--;
                    if (battle->conta_defensa <= 0)
                    {
                        printf("La defensa de %s (%s) a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno));
                        battle->defensa=0;
                        getchar();
                    }
                }
                // Evaluamos veneno
                if (battle->veneno ==1)
                {
                    battle->conta_veneno--;
                    printf("%s (%s) se resiste al veneno, %s pierde 5hp \n",battle->name,mostrar_turno(definir_turno),battle->name);
                    getchar();
                    battle->hp-=5;
                    if (battle->conta_veneno <= 0)
                    {
                        printf("%s (%s) se ha curado del veneno, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno));
                        battle->veneno =0;
                    }
                }
                // Evaluamos regeneracion
                if (battle->regeneracion ==1)
                {
                    battle->conta_regeneracion--;
                    printf("%s (%s) recupera 5hp \n",battle->name,mostrar_turno(definir_turno));
                    getchar();
                    battle->hp+=5;
                    if (battle->conta_regeneracion <= 0)
                    {
                        printf("%s (%s) ha perdido la regeneracion, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno));
                        battle->regeneracion =0;
                        getchar();
                    }
                }
                // Evaluamos furia
                if (battle->furia ==1)
                {
                    battle->conta_furia--;
                    printf("%s (%s) Sigue enojado \n",battle->name,mostrar_turno(definir_turno));
                    getchar();
                    if (battle->conta_furia <= 0)
                    {
                        printf("%s (%s) ha calmado, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno));
                        battle->furia =0;
                        getchar();
                    }
                }
            }

        }
        else if (definir_turno == 0){
            
            printf("\n");
            printf("Turno (%s)\n",mostrar_turno(definir_turno));

            // Revisamos si duerme
            if ((battle+1)->dormir ==1){
                (battle+1)->conta_dormir--;
                printf("%s (%s) esta profundaente dormido, %s pierde el turno \n",(battle+1)->name,mostrar_turno(definir_turno),(battle+1)->name);
                getchar();
                if ((battle+1)->conta_dormir<= 0){
                    printf("%s (%s) se ha despertado, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno));
                    (battle+1)->dormir =0;
                    getchar();
                }
            }else{
                printf("(%s) eligiendo el ataque de su %s\n",mostrar_turno(definir_turno),(battle_ptr+1)->name);
                printf("Enemigo pensando\n");
                printf("Presiona enter para continuar\n");
                
                //opcion_atque= 2; //Hace solo la magia
                opcion_atque = rand()%4;// elige del 0 al 3
                
                getchar();
                

                battle[diferenciador(definir_turno)].action[opcion_atque]((battle_ptr+diferenciador(definir_turno)),(battle_ptr+definir_turno));

                printf("Presiona enter para continuar\n");
                getchar();
                printf("Estados activos: \n");

                // Revisamos defensa
                if ((battle+1)->defensa ==1) 
                {
                    (battle+1)->conta_defensa--;
                    if ((battle+1)->conta_defensa <= 0)
                    {
                        printf("La defensa de %s (%s) a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno));
                        (battle+1)->defensa=0;
                        getchar();
                    }
                }
                // Revisamos veneno
                if ((battle+1)->veneno ==1)
                {
                    (battle+1)->conta_veneno--;
                    printf("%s (%s) se resiste al veneno, %s pierde 5hp \n",(battle+1)->name,mostrar_turno(definir_turno),(battle+1)->name);
                    getchar();
                    (battle+1)->hp-=5;
                    if ((battle+1)->conta_veneno <= 0)
                    {
                        printf("%s (%s) se ha curado del veneno, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno));
                        (battle+1)->veneno =0;
                        getchar();
                    }  
                }

                // Evaluamos regeneracion
                if ((battle+1)->regeneracion ==1)
                {
                    (battle+1)->conta_regeneracion--;
                    printf("%s (%s) recupera 5hp \n",(battle+1)->name,mostrar_turno(definir_turno));
                    getchar();
                    (battle+1)->hp+=5;
                    if ((battle+1)->conta_regeneracion <= 0)
                    {
                        printf("%s (%s) ha perdido la regeneracion, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno));
                        (battle+1)->regeneracion =0;
                        getchar();
                    }
                }
                // Evaluamos furia
                if ((battle+1)->furia ==1)
                {
                    (battle+1)->conta_furia--;
                    printf("%s (%s) Sigue enojado \n",(battle+1)->name,mostrar_turno(definir_turno));
                    getchar();
                    if ((battle+1)->conta_furia <= 0)
                    {
                        printf("%s (%s) ha calmado, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno));
                        (battle+1)->furia =0;
                        getchar();
                    }
                }

            }

        }
        turno+=1;
        printf("\n");
    }
    final(battle_ptr,battle_ptr+1);
}
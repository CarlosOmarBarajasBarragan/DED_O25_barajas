#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*------- Version 27/09/2025 9:21 pm-------*/


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
    int suerte;
    int conta_suerte;
    void (*action[3])(void * pokemon_jugador, void * pokemon_enemigo);
}pokemon;

char param[12];
char * param_ptr = param;

char* mostrar_turno(int turno, char * param){
    if (turno %2 == 0){
        param = "Rival";
        return param;
    }
    else{
        param = "Jugador";
        return param;
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
    }if (jugador->furia ==1)
    {
        enemigo->hp-=15;
        printf("%s (%s) esta furioso y hara mas danio \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr));
        printf("\n");
    }else{
        enemigo->hp-=10;
    }
    
    
    
    printf("%s (%s) ataco a %s (%s)\n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), enemigo->name, mostrar_turno(diferenciador(enemigo->id), param_ptr));
    printf("%s (%s) tiene ahora %d HP\n", enemigo->name, mostrar_turno(diferenciador(enemigo->id), param_ptr), enemigo->hp);
}

void block(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso defensa ferrea, %s aumento su defensa \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), jugador->name);
    jugador->defensa=1;
    jugador->conta_defensa=2;

}

void veneno(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso polvo veneno en %s (%s), ha sido envenenado \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), enemigo->name,mostrar_turno(diferenciador(enemigo->id), param_ptr));
    enemigo->veneno=1;
    enemigo->conta_veneno=3; // Dura 3 turnos el veneno
    
}

void dormir(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso bostezo en %s (%s), ha caido dormido \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), enemigo->name,mostrar_turno(diferenciador(enemigo->id), param_ptr));
    enemigo->dormir=1;
    enemigo->conta_dormir=2;// Duerme 2 turnos

}

void regen(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso arraigo,%s (%s) empezara a recuperar hp \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), jugador->name,mostrar_turno(diferenciador(jugador->id), param_ptr));
    jugador->regeneracion =1;
    jugador->conta_regeneracion=3;
}

void furia(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso furia, %s esta enojado , su ataque se ve incrementado \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), jugador->name);
    jugador->furia=1;
    jugador->conta_furia=4; // Dura 3 turnos la furia
    
}

void suerte(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("%s (%s) uso polvo veneno en %s (%s), ha sido envenenado \n", jugador->name, mostrar_turno(diferenciador(jugador->id), param_ptr), enemigo->name,mostrar_turno(diferenciador(enemigo->id), param_ptr));
    enemigo->veneno=1;
    enemigo->conta_veneno=3; // Dura 3 turnos el veneno
    
}



void magia_set(pokemon * battle_ptr, void (**magia_array)(void*, void*), char **magia_names, int contador) {

    if ((battle_ptr+contador)->id == 0){

    printf("--- Escoge una Magia ---\n");

        for (int i = 0; i < 5; i++) {
            
            printf("%d. %s\n", i, *(magia_names + i));
        }

        int magia_escogida;

        printf("Jugador, escoge tu magia: ");
        scanf("%d", &magia_escogida);


        *((battle_ptr+contador)->action + 2) = *(magia_array + magia_escogida);
    }

    else{
        int magia_escogida;
        // Bot elige magia
        magia_escogida = rand()%1;// %3
        *((battle_ptr+contador)->action + 2) = *(magia_array + magia_escogida);
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
    

    for (int i= 0; i<2; i++){
    
        *(battle_ptr+i) = *(pokedex_pointer+pokemon_escogido);
        (battle_ptr+i)->id = i;
        
        magia_set(battle_ptr,magia_array,magia_names,i); 
        printf("\n");

        pokemon_escogido = rand()%1;// Siempre pikachu para prueba
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

char * nombre_magia(pokemon * battle_ptr) {
    void (*magia_actual)(void*, void*) = *(battle_ptr->action + 2);

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
        .suerte=0,
        .conta_suerte=0,
        .hp = 100,//110
        .action = { attack, block,NULL}
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
        .suerte=0,
        .conta_suerte=0,
        .hp = 100,
        .action = { attack, block,NULL}
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
        .suerte=0,
        .conta_suerte=0,
        .hp = 100,
        .action = { attack, block,NULL}
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
        .suerte=0,
        .conta_suerte=0,
        .hp = 100,
        .action = { attack, block,NULL}
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
        .suerte=0,
        .conta_suerte=0,
        .hp = 100,
        .action = { attack, block,NULL}
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

       
   // Establece los pokemones
    pokemon_set(battle_ptr,pokedex_ptr, magia_array,ptr_magia);

       // Declara nombres ataques
    char atq1[30] ="Ataque";
    char atq2[30] = "Defensa";
    char atq3[20] = ".";
    char *nombres_ataques[]={atq1,atq2,atq3};
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
            printf("Turno (%s)\n",mostrar_turno(definir_turno,param_ptr));

            // Revisamos dormir
            if (battle->dormir ==1){
                battle->conta_dormir--;
                printf("%s (%s) esta profundaente dormido, %s pierde el turno \n",battle->name,mostrar_turno(definir_turno,param_ptr),battle->name);
                getchar();
                if (battle->conta_dormir<= 0){
                    printf("%s (%s) se ha despertado, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno,param_ptr));
                    battle->dormir =0;
                    getchar();
                }
            } else{
                printf("(%s) elige el ataque de tu %s:\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr)->name);
                strcpy(atq3, nombre_magia(battle_ptr));
                for (int i = 0; i < 3; i++,ptr_nombres++)
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
                        printf("La defensa de %s (%s) a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno,param_ptr));
                        battle->defensa=0;
                        getchar();
                    }
                }
                // Evaluamos veneno
                if (battle->veneno ==1)
                {
                    battle->conta_veneno--;
                    printf("%s (%s) se resiste al veneno, %s pierde 5hp \n",battle->name,mostrar_turno(definir_turno,param_ptr),battle->name);
                    getchar();
                    battle->hp-=5;
                    if (battle->conta_veneno <= 0)
                    {
                        printf("%s (%s) se ha curado del veneno, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno,param_ptr));
                        battle->veneno =0;
                    }
                }
                // Evaluamos regeneracion
                if (battle->regeneracion ==1)
                {
                    battle->conta_regeneracion--;
                    printf("%s (%s) recupera 5hp \n",battle->name,mostrar_turno(definir_turno,param_ptr));
                    getchar();
                    battle->hp+=5;
                    if (battle->conta_regeneracion <= 0)
                    {
                        printf("%s (%s) ha perdido la regeneracion, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno,param_ptr));
                        battle->regeneracion =0;
                        getchar();
                    }
                }
                // Evaluamos furia
                if (battle->furia ==1)
                {
                    battle->conta_furia--;
                    printf("%s (%s) Sigue enojado \n",battle->name,mostrar_turno(definir_turno,param_ptr));
                    getchar();
                    if (battle->conta_furia <= 0)
                    {
                        printf("%s (%s) ha calmado, a vuelto a la normalidad\n",battle->name,mostrar_turno(definir_turno,param_ptr));
                        battle->furia =0;
                        getchar();
                    }
                }
            }

        }
        else if (definir_turno == 0){
            
            printf("\n");
            printf("Turno (%s)\n",mostrar_turno(definir_turno,param_ptr));

            // Revisamos si duerme
            if ((battle+1)->dormir ==1){
                (battle+1)->conta_dormir--;
                printf("%s (%s) esta profundaente dormido, %s pierde el turno \n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr),(battle+1)->name);
                getchar();
                if ((battle+1)->conta_dormir<= 0){
                    printf("%s (%s) se ha despertado, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                    (battle+1)->dormir =0;
                    getchar();
                }
            }else{
                printf("(%s) eligiendo el ataque de su %s\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr+1)->name);
                printf("Enemigo pensando\n");
                printf("Presiona enter para continuar\n");
                
                //opcion_atque= 2; Hace solo la magia
                opcion_atque = rand()%1;// Solo elige ataque
                // Sleep(4000);
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
                        printf("La defensa de %s (%s) a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                        (battle+1)->defensa=0;
                        getchar();
                    }
                }
                // Revisamos veneno
                if ((battle+1)->veneno ==1)
                {
                    (battle+1)->conta_veneno--;
                    printf("%s (%s) se resiste al veneno, %s pierde 5hp \n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr),(battle+1)->name);
                    getchar();
                    (battle+1)->hp-=5;
                    if ((battle+1)->conta_veneno <= 0)
                    {
                        printf("%s (%s) se ha curado del veneno, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                        (battle+1)->veneno =0;
                        getchar();
                    }  
                }

                // Evaluamos regeneracion
                if ((battle+1)->regeneracion ==1)
                {
                    (battle+1)->conta_regeneracion--;
                    printf("%s (%s) recupera 5hp \n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                    getchar();
                    (battle+1)->hp+=5;
                    if ((battle+1)->conta_regeneracion <= 0)
                    {
                        printf("%s (%s) ha perdido la regeneracion, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                        (battle+1)->regeneracion =0;
                        getchar();
                    }
                }
                // Evaluamos furia
                if ((battle+1)->furia ==1)
                {
                    (battle+1)->conta_furia--;
                    printf("%s (%s) Sigue enojado \n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                    getchar();
                    if ((battle+1)->conta_furia <= 0)
                    {
                        printf("%s (%s) ha calmado, a vuelto a la normalidad\n",(battle+1)->name,mostrar_turno(definir_turno,param_ptr));
                        (battle+1)->furia =0;
                        getchar();
                    }
                }

            }

        }
        turno+=1;
        printf("\n");
    }
}
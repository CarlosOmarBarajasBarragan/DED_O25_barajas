#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h> 


typedef struct pokemon{
    char name[20];
    // poner de estados y resetear en el while
    int hp;
    int dormir;
    int defensa;
    int veneno; 
    void (*action[5])(struct pokemon* pokemon_jugador, struct pokemon* pokemon_enemigo, int id_a, int id_d);
    /*void (*action[5]) (void*) */
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

void attack(pokemon * pokemon_jugador,pokemon * pokemon_enemigo,int id_a, int id_d){
    if (pokemon_enemigo->defensa == 1)
    {
        pokemon_enemigo->hp-=5;
    }else{
        pokemon_enemigo->hp-=10;
    }
     // LÍNEA 50 CORREGIDA: Usa mostrar_turno con el ID del atacante (id_a) y del defensor (id_d)
    printf("%s (%s) ataco a %s (%s)\n", pokemon_jugador->name, mostrar_turno(id_a, param_ptr), pokemon_enemigo->name, mostrar_turno(id_d, param_ptr));
    
    printf("%s (%s) tiene ahora %d HP\n", pokemon_enemigo->name, mostrar_turno(id_d, param_ptr), pokemon_enemigo->hp);
}

void block(pokemon * pokemon_jugador,pokemon * pokemon_enemigo,int id_a, int id_d){
    printf("Aqui el enemigo se pone mas defensa es prueba nomas\n");
    pokemon_enemigo->defensa=1;
    //pokemon_jugador->defensa=1; // Cambia a pokemon_jugador
}

void veneno(pokemon * pokemon_jugador,pokemon * pokemon_enemigo){
    
}

void dormir(int id){

}

void pokemon_set(pokemon * battle_ptr,pokemon * pokedex_pointer){

     int pokemon_escogido=-1;
    /* 
    for (int i = 0; i < 5; i++)
    {
        printf("[%d]-- %s \n",i,(*pokedex_pointer->name));//es un pointer
    }
    */

    while (pokemon_escogido <0 || pokemon_escogido >= 5)
    {
        printf("Jugador escoge tu pokemon\n");
        scanf("%d", &pokemon_escogido);
        fflush(stdout);
    }
    

    for (int i= 0; i<2; i++){
    
    switch (pokemon_escogido)
    {
    case 0:
        *(battle_ptr+i) = *(pokedex_pointer);
        break;
    
    case 1:
        *(battle_ptr+i) = *(pokedex_pointer+1);
        break;

    case 2:
        *(battle_ptr+i) = *(pokedex_pointer+2);
        break;

    case 3:     
        *(battle_ptr+i) = *(pokedex_pointer+3);
        break;

    case 4:
        *(battle_ptr+i) = *(pokedex_pointer+4);
        break;
    
    default:
      break;
    } 
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



int main(){
   

    srand(time(NULL));

   pokemon Pikachu = {
        .name = "Pikachu",
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 30,//110
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Charmander = {
        .name = "Charmander",
        .hp = 100,
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Squirtle = {
        .name = "Squirtle",
        .hp = 100,
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Bulbasur = {
        .name = "Bulbasur",
        .hp = 100,
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Mewtwo = {
        .name = "Mewtwo",
        .hp = 100,
        .action = { attack, block,NULL,NULL,NULL }
    };


    pokemon battle [2];
    pokemon * battle_ptr = battle;

    /*void * v_array[7]= {};*/


   pokemon pokedex [5]={Pikachu,Charmander,Squirtle,Bulbasur,Mewtwo};
   pokemon * pokedex_ptr = pokedex;
    
   // Establece los pokemones
    pokemon_set(battle_ptr,pokedex_ptr);

    // Solo muestra los pokemones
   pokemon_preview(battle_ptr);
   printf("Presiona enter para continuar\n");
   getchar();
   getchar();
   limpiar_pantalla();
    // Declara nombres ataques
    char atq1[10] ="Ataque";
    char atq2[10] = "Defensa";
    char atq3[10] = "Magia1";
    char atq4[10] = "Magia2";
    char atq5[10] = "Magia3";
    char *nombres_ataques[]={atq1,atq2,atq3,atq4,atq5};
    char **ptr_nombres=nombres_ataques;
    int constante =1, turno = 1, opcion_atque =-1;;



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
            printf("(%s) elige el ataque de tu %s:\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr+definir_turno)->name);
            for (int i = 0; i < 5; i++,ptr_nombres++)
            {
                printf("%d. %s\n",i,*ptr_nombres);
            }
            scanf("%d",&opcion_atque);
            printf("\n");
            battle[diferenciador(definir_turno)].action[opcion_atque]((battle_ptr+diferenciador(definir_turno)),(battle_ptr+definir_turno), definir_turno,diferenciador(definir_turno));

            printf("Presiona enter para continuar\n");
            getchar();
            getchar();

        }
        else if (definir_turno == 0){
            
            printf("\n");
            printf("Turno (%s)\n",mostrar_turno(definir_turno,param_ptr));
            printf("(%s) eligiendo el ataque de su %s\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr+definir_turno)->name);
            printf("Enemigo pensando\n");
            printf("Presiona enter para continuar\n");
            
            
            opcion_atque = rand()%1;
            // Sleep(4000);
            getchar();
            

            battle[diferenciador(definir_turno)].action[opcion_atque]((battle_ptr+diferenciador(definir_turno)),(battle_ptr+definir_turno), definir_turno,diferenciador(definir_turno));

            printf("Presiona enter para continuar\n");
            getchar();

            }

        turno+=1;
        printf("\n");
    }

}
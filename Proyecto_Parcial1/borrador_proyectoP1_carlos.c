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
    void (*action[5])(struct pokemon* pokemon_jugador, struct pokemon* pokemon_enemigo);

}pokemon;

char param[12];
char * param_ptr = param;

void attack(pokemon * pokemon_jugador,pokemon * pokemon_enemigo){
    if (pokemon_enemigo->defensa == 1)
    {
        pokemon_enemigo->hp-=5;
    }else{
        pokemon_enemigo->hp-=10;
    }
    
    printf("%s ataco a %s\n",pokemon_jugador,pokemon_enemigo);
    printf("%s tiene ahora %d HP\n",pokemon_enemigo->name,pokemon_enemigo->hp);
}

void block(pokemon * pokemon_jugador,pokemon * pokemon_enemigo){
    printf("Aqui el enemigo se pone mas defensa es prueba nomas\n");
    pokemon_enemigo->defensa=1;// Cambia a pokemon_jugador
    //pokemon_jugador->defensa=1;
}

void veneno(pokemon * pokemon_jugador,pokemon * pokemon_enemigo){
    
}

void dormir(int id){

}

void pokemon_set(int id){

      printf("Escribe el numero del pokemon a escoger ");

}

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
    else if (definir_turno ==1){
        return 0;
    }


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

    int pokemon_escogido=-1;


    while (pokemon_escogido <0 || pokemon_escogido >= 5)
    {
        printf("Jugador 1 escoge tu pokemon\n");
        scanf("%d", &pokemon_escogido);
        fflush(stdout);
    }
    

    for (int i= 0; i<2; i++){
    
    switch (pokemon_escogido)
    {
    case 0:
        *(battle_ptr+i) = Pikachu;
        break;
    
    case 1:
        *(battle_ptr+i) = Charmander;
        break;

    case 2:
        *(battle_ptr+i) = Squirtle;
        break;

    case 3:     
        *(battle_ptr+i) = Bulbasur;
        break;

    case 4:
        *(battle_ptr+i) = Mewtwo;
        break;
    
    default:
        /*printf("Escoge solo un pokemon valido\n");
        printf("Jugador 1 escoge tu pokemon\n");
        scanf("%s", pokemon_escogido);
        fflush(stdout);

        toupper(pokemon_escogido); */
      break;
    }


        
    pokemon_escogido = rand()%1;// Siempre pikachu para prueba

    //printf("%d\n", pokemon_escogido);

    }
    /*
    attack(battle_ptr,battle_ptr+1);
*/
    printf("Pokemon enemigo: %s\n",(battle+1)->name);
    printf("Salud enemigo: %d\n",(battle+1)->hp);

   
    // Declara ataques
    char atq1[10] ="Ataque";
    char atq2[10] = "Defensa";
    char atq3[10] = "Magia1";
    char atq4[10] = "Magia2";
    char atq5[10] = "Magia3";
    char *nombres_ataques[]={atq1,atq2,atq3,atq4,atq5};
    char **ptr_nombres=nombres_ataques;
    int constante =1, turno = 1, opcion_atque =-1;;



    while (battle[0].hp>0 && battle[1].hp>0){ 

        int definir_turno = (turno%2);

        printf("Detalles de la partida: \n");

        printf("Jugador %s Salud : %d\n",(battle)->name, (battle)->hp);
        
        printf("Enemigo %s Salud : %d\n",(battle+1)->name, (battle+1)->hp);

        ptr_nombres=nombres_ataques;

        if (definir_turno == 1){

        printf("Turno %s\n",mostrar_turno(definir_turno,param_ptr));
        printf("%s elige el ataque de tu %s:\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr+definir_turno)->name);
        for (int i = 0; i < 5; i++,ptr_nombres++)
        {
            printf("%d. %s\n",i,*ptr_nombres);
        }
        scanf("%d",&opcion_atque);

        battle[definir_turno].action[opcion_atque]((battle_ptr+definir_turno),(battle_ptr+diferenciador(definir_turno)));


        }
        else if (definir_turno == 0){

        Sleep(3000);

        printf("Turno %s\n",mostrar_turno(definir_turno,param_ptr));
        printf("%s elige el ataque de tu %s:\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr+definir_turno)->name);
        for (int i = 0; i < 5; i++,ptr_nombres++)
        {
            printf("%d. %s\n",i,*ptr_nombres);
        }
        opcion_atque = rand()%1;

        battle[definir_turno].action[opcion_atque]((battle_ptr+definir_turno),(battle_ptr+diferenciador(definir_turno)));

        }


         

        // -----------Turno Bot-----------//
    // son en milisegundos

        turno+=1;
        printf("\n");
    }

}
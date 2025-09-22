#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct pokemon{
    char name[20];
    int id;
    int hp;
    void (*action[5]);

}pokemon;



void attack(int id, int hp){
    hp -= 15;
}

void block(int id, int att){
    att += 5;
}

void veneno(int id, int hp){
    hp -=5;
}

void dormir(int id){

}

void pokemon_set(int id){

      printf("Escribe el numero del pokemon a escoger ");

}



int main(){

    srand(time(NULL));

   pokemon Pikachu = {
        .name = "Pikachu",
        .hp = 100,
        .action = { attack, block }
    };

    pokemon Charmander = {
        .name = "Charmander",
        .hp = 100,
        .action = { attack, block }
    };


    pokemon battle [2];
    pokemon * battle_ptr = battle;

    int pokemon_escogido;



    printf("Jugador 1 escoge tu pokemon\n");
    scanf("%d", &pokemon_escogido);
    fflush(stdout);

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
        *(battle_ptr+i) = Pikachu;
        break;

    case 3:     
        *(battle_ptr+i) = Pikachu;
        break;

    case 4:
        *(battle_ptr+i) = Pikachu;
        break;
    
    default:
        /*printf("Escoge solo un pokemon valido\n");
        printf("Jugador 1 escoge tu pokemon\n");
        scanf("%s", pokemon_escogido);
        fflush(stdout);

        toupper(pokemon_escogido); */
      
    }


        
    pokemon_escogido = rand()%5;

    printf("%d\n", pokemon_escogido);

    }


    *battle_ptr = Pikachu;
    *(battle_ptr+1) = Charmander;


    while (battle[0].hp>0 ||battle[1].hp>0){

        break;
    }

}





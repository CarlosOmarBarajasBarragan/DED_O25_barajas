#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct pokemon{
    char name[20];
    int hp;
    void (*action[5]);

}pokemon;



void pokemon_set(pokemon* poke_ptr){

      printf("Escribe el numero del pokemon a escoger ");
      scanf("%d", poke_ptr);
      fflush(stdout);


}



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


int main(){

   pokemon Pikachu = {
        .name = "Pikachu",
        .hp = 100,
        .action = { attack, block }
    };




    pokemon battle [2];
    pokemon * poke_ptr = battle;



}





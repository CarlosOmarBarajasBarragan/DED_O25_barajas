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
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 30,//110
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Charmander = {
        .name = "Charmander",
        .hp = 120,
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Squirtle = {
        .name = "Squirtle",
        .hp = 115,
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Bulbasur = {
        .name = "bulbasur",
        .hp = 125,
        .action = { attack, block,NULL,NULL,NULL }
    };

    pokemon Mewtwo = {
        .name = "Mewtwo",
        .hp = 130,
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
         
        ptr_nombres=nombres_ataques;
        printf("Turno %d\n",turno);
        printf("Jugador elige el ataque de tu %s:\n",battle_ptr->name);
        for (int i = 0; i < 5; i++,ptr_nombres++)
        {
            printf("%d. %s\n",i,*ptr_nombres);
        }
        scanf("%d",&opcion_atque);

        battle[0].action[opcion_atque](battle_ptr,battle_ptr+1);

        // -----------Turno Bot-----------//
        Sleep(3000);// son en milisegundos
        printf("Turno del enemigo \n");




        turno+=1;
        printf("\n");
    }

}



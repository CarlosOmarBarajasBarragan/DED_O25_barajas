#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h> 


typedef struct pokemon{
    char name[20];
    int hp;
    int id;
    int dormir;
    int defensa;
    int veneno; 
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

}

void veneno(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

    printf("si");
}

void dormir(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

}

void regen(void * pokemon_jugador,void * pokemon_enemigo){

    struct pokemon *jugador = (struct pokemon *)pokemon_jugador;
    struct pokemon *enemigo = (struct pokemon *)pokemon_enemigo;

}



void magia_set(pokemon * battle_ptr, void (**magia_array)(void*, void*), char **magia_names, int contador) {

    if ((battle_ptr+contador)->id == 0){

    printf("--- Escoge una Magia ---\n");

    for (int i = 0; i < 3; i++) {
        
        printf("%d. %s\n", i, *(magia_names + i));
    }

    int magia_escogida;

    printf("Jugador, escoge tu magia: ");
    scanf("%d", &magia_escogida);


    *((battle_ptr+contador)->action + 2) = *(magia_array + magia_escogida);
    }

    else{
    int magia_escogida;

    magia_escogida = rand()%1;


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
    }

    return NULL;
}

int main(){
   

    srand(time(NULL));

   pokemon Pikachu = {
        .name = "Pikachu",
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 30,//110
        .action = { attack, block,NULL}
    };

    pokemon Charmander = {
        .name = "Charmander",
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 100,
        .action = { attack, block,NULL}
    };

    pokemon Squirtle = {
        .name = "Squirtle",
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 100,
        .action = { attack, block,NULL}
    };

    pokemon Bulbasur = {
        .name = "Bulbasur",
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 100,
        .action = { attack, block,NULL}
    };

    pokemon Mewtwo = {
        .name = "Mewtwo",
        .defensa = 0,
        .dormir = 0,
        .veneno = 0,
        .hp = 100,
        .action = { attack, block,NULL}
    };


    pokemon battle [2];
    pokemon * battle_ptr = battle;


    
    void (*magia_array[3])(void*, void*) = {veneno, dormir, regen};
    char magia_1[20] ="Veneno";
    char magia_2[30] = "Dormir";
    char magia_3[20] = "Regeneracion";
    char *nombres_magia[]={magia_1,magia_2,magia_3};
    char **ptr_magia=nombres_magia;

   pokemon pokedex [5]={Pikachu,Charmander,Squirtle,Bulbasur,Mewtwo};
   pokemon * pokedex_ptr = pokedex;

       
   // Establece los pokemones
    pokemon_set(battle_ptr,pokedex_ptr, magia_array,ptr_magia);

       // Declara nombres ataques
    char atq1[20] ="Ataque";
    char atq2[20] = "Defensa";
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
   int conta_defensa_Jugador=2;
   int conta_veneno_Jugador=2;
   int conta_dormir_Jugador=2;
   int conta_regeneracion_Jugador=2;
   // Rival
   int conta_defensa_Rival=2;
   int conta_veneno_Rival=2;
   int conta_dormir_Rival=2;
   int conta_regeneracion_Rival=2;



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
            if (battle->defensa ==1)
            {
                //printf("Aqui aun tiene la defensa activada\n");
                conta_defensa_Jugador-=1;
                if (conta_defensa_Jugador<=0)
                {
                   // printf("Aqui ya se desactivo la defensa \n");
                    battle->defensa=0;
                    conta_defensa_Jugador=2;
                }
                
                
            }
           // getchar();
            

        }
        else if (definir_turno == 0){
            
            printf("\n");
            printf("Turno (%s)\n",mostrar_turno(definir_turno,param_ptr));
            printf("(%s) eligiendo el ataque de su %s\n",mostrar_turno(definir_turno,param_ptr),(battle_ptr+1)->name);
            printf("Enemigo pensando\n");
            printf("Presiona enter para continuar\n");
            
            
            opcion_atque = rand()%1;
            // Sleep(4000);
            getchar();
            

            battle[diferenciador(definir_turno)].action[opcion_atque]((battle_ptr+diferenciador(definir_turno)),(battle_ptr+definir_turno));

            printf("Presiona enter para continuar\n");
            getchar();

            }

        turno+=1;
        printf("\n");
    }

}
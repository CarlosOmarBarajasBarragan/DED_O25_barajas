#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Date.h"

struct strDate{
    int dia;
    int mes;
    char mesString[20];
    int ano;
};

char *NOMBRES_MESES[] = {
    "Mes Invalido",
    "Enero",
    "Febrero",
    "Marzo",
    "Abril",
    "Mayo",
    "Junio",
    "Julio",
    "Agosto",
    "Septiembre",
    "Octubre",
    "Noviembre",
    "Diciembre"
};


static const int DIAS_POR_MES[13] = { 
        0, 31, 28, 31, 30, 31, 30, 
        31, 31, 30, 31, 30, 31 
};

Date date_create(int dia, int mes, int ano){
    Date d1 = malloc(sizeof(struct strDate));
    if (mes>=1 && mes <=12){
    
        if (ano>=0){
        d1->ano=ano;
        }
        else{
            printf("Introduce un año mayor a 0\n");
        }

    if(mes == 2){

        d1->mes = 2;
        strcpy(d1->mesString,NOMBRES_MESES[2]);

        if(dia<= 28 && dia>=1){
            d1->dia= dia;
        }
        else{
            printf("Dia no valido, solo entre 1 y 28\n");
        }

    }

    else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12 ){

        d1->mes = mes;
        strcpy(d1->mesString,NOMBRES_MESES[mes]);

        if(dia<= 31 && dia>=1){
            d1->dia= dia;
        }
        else{
            printf("Dia no valido, solo entre 1 y 31\n");
        }
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        d1->mes = mes;
        strcpy(d1->mesString,NOMBRES_MESES[mes]);

        if(dia<= 30 && dia>=1){
            d1->dia= dia;
        }
        else{
            printf("Dia no valido, solo entre 1 y 30\n");
        }
    }
    else{
        printf("Mes no valido, solo entre 1 y 12\n");
    }
    }
    return d1;
};

void date_destroy(Date d1){
    free(d1);
};

void set_dia(Date d1, int dia){

    if(d1->mes == 2){

        if(dia<= 28 && dia>=1){
            d1->dia= dia;
        }
        else{
            printf("Dia no valido, solo entre 1 y 28\n");
        }

    }

    else if(d1->mes == 1 || d1->mes == 3 || d1->mes == 5 || d1->mes == 7 || d1->mes == 8 || d1->mes == 10 || d1->mes == 12 ){
        if(dia<= 31 && dia>=1){
            d1->dia= dia;
        }
        else{
            printf("Dia no valido, solo entre 1 y 31\n");
        }

    }
    else if (d1->mes == 4 || d1->mes == 6 || d1->mes == 9 || d1->mes == 11){
        if(dia<= 30 && dia>=1){
            d1->dia= dia;
        }
        else{
            printf("Dia no valido, solo entre 1 y 30\n");
        }
    }

};

void set_mes(Date d1, int mes){
    if (mes>=1 && mes <=12){
        d1->mes = mes;
    }
};

void set_ano(Date d1, int ano){
    if(ano >= 0){
    d1->ano=ano;
    }
};

int get_dia(Date d1){
    return d1->dia;
};

int get_mes(Date d1){
    return d1->mes;
};

int get_ano(Date d1){
    if (d1>=0){
    return d1->ano;
    }
    else{
        printf("Ingresar un año mayor a 0");
    }
};

void print_short(Date d1){
    printf(" %d / %d / %d\n",d1->dia,d1->mes,d1->ano);
};

void print_long(Date d1){
    printf(" %d de %s de %d\n",d1->dia,d1->mesString,d1->ano);
};

int int_cmp(int id1,int id2){
    if(id1>id2){
        return 1;
    }
    else{
        return 0;
    }
};

int date_cmp(Date d1, Date d2){
    if (d1->ano == d2->ano && d1->mes == d2->mes && d1->dia == d2->dia){
        return 0;
    }

    if (d1->ano != d2 ->ano){
        if(int_cmp(d1->ano,d2->ano) == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
    else{
        if (d1->mes != d2 ->mes){
            if(int_cmp(d1->mes,d2->mes) == 1){
                return 1;
            }
            else{
                return 2;
            }
        }
        else{
        if (d1->dia != d2 ->dia){
        if(int_cmp(d1->dia,d2->dia) == 1){
            return 1;
        }
        else{
            return 2;
        }
    }
        }
    
    }
};

int dias_desde_0(Date d) {
    int total = d->ano * 365; 

    for (int i = 1; i < d->mes; i++) {
        total += DIAS_POR_MES[i];
    }

    total += d->dia;
    return total;
}

int elapsed_days(Date d1, Date d2){
int total1 = dias_desde_0(d1);
    int total2 = dias_desde_0(d2);

    int diff = total1 - total2;
    if (diff < 0) diff = -diff;
    return diff;    
};

Date duplicate_date(Date d1){
    Date d2 = malloc(sizeof(struct strDate));
    d2->ano = d1->ano;
    d2->mes = d1->mes;
    strcpy(d2->mesString,d1->mesString);
    d2->dia = d1->dia;

    return d2;
};


#include <stdio.h>
#include <stdlib.h>
#include "Date.h"   

int main() {

    Date d1 = date_create(15, 3, 2024);
    Date d2 = date_create(1, 1, 2024);
    Date d3 = date_create(31, 12, 2023);


    print_short(d1);
    print_long(d1);

    print_short(d2);
    print_long(d2);

    print_short(d3);
    print_long(d3);

    get_dia(d1);
    get_mes(d1);
    get_ano(d1);

    set_dia(d1, 20);
    set_mes(d1, 4);
    set_ano(d1, 2025);
    print_long(d1);

    int cmp = date_cmp(d1, d2);
    
    printf("%d",cmp);


    printf("Dias transcurridos entre d1 y d2: %d dias\n", elapsed_days(d1, d2));
    printf("Dias transcurridos entre d2 y d3: %d dias\n", elapsed_days(d2, d3));
    printf("Dias transcurridos entre d1 y d3: %d dias\n", elapsed_days(d1, d3));

    Date copia = duplicate_date(d2);
    print_long(copia);

    /*
    date_destroy(d1);
    date_destroy(d2);
    date_destroy(d3);
    date_destroy(copia);
    */

    return 0;
}
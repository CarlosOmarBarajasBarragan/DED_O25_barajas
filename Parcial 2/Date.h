#ifndef DATE_H
#define DATE_H

typedef struct strDate * Date;

Date date_create(int dia, int mes, int ano);

void date_destroy(Date d1);

void set_dia(Date d1, int dia);

void set_mes(Date d1, int mes);

void set_ano(Date d1, int ano);

int get_dia(Date d1);

int get_mes(Date d1);

int get_ano(Date d1);

void print_short(Date d1);

void print_long(Date d1);

int date_cmp(Date d1, Date d2);

int elapsed_days(Date d1, Date d2);

Date duplicate_date(Date d1);


#endif
#ifndef SET_H
#define SET_H


typedef int boolean;
#define TRUE 1
#define FALSE 0


typedef struct set_str set;
typedef void (*print_func) (void * v1);
typedef int (*compare_func) (void * v1, void * v2);

set * set_create (compare_func cf, print_func pf);

int set_size(set * s);

boolean set_add(set * s, void * data);

boolean set_contains (set * s, void * data);

void set_destroy (set * s);


void set_print (set *s);


#endif
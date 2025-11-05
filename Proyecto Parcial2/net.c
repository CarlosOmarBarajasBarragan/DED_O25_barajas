#include <stdio.h>
#include <stdlib.h>
#include "net.h"

struct strUsuario { 
char username[30]; 
int edad; 
char genero; 
struct strUsuario* global_next; 
struct strUsuario* gender_next; 
struct strUsuario* gender_prev; 
int followCount; 
struct strUsuario* follows[4]; 
}; 
typedef struct strUsuario* user; 

struct str_net { 
user list; 
user list_male; 
user list_female; 
int  user_count; 
int  male_count; 
int  female_count; 
}; 
typedef struct str_net* net; 

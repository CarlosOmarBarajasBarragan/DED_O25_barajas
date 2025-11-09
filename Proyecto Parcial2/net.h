#ifndef NET_H
#define NET_H


#define FULL 0
#define BOYS 1
#define GIRLS 2

#include "bool.h"

typedef struct strUsuario* user; 
typedef struct str_net* net; 


net net_create();
void net_destroy(net n);
Bool net_addUser(net n, char* username, int age, char gender);
Bool net_delUser(net n, char username[]);
user findUser(net n, char username[]);
void net_print(net n, int part);
Bool net_follow(net n, char username1[], char username2[]);
Bool net_readFromFile(net n, char* netFilename, char* friendsFilename);
void net_toTextFile(net n, char* filename);



#endif 
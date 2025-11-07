#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

bool net_follow(net n,char username1[], char username2[]){
    if(n==NULL) return;
    if(strcmp(username1,username2)==0) return FALSE;    //strcmp retorna 0 si son iguales las cadenas
    user u1= findUser(n, username1);
    user u2=findUser(n,username2);
    
    if (u1==NULL || u2==NULL) return FALSE; 
    if(u1->followCount==4) return FALSE;
    
    for(int i=0;i<u1->followCount;i++){
        if(u1->follows[i]==u2) return FALSE;
    }
    u1->follows[u1->followCount]=u2;
    u1->followCount++;
    
    return TRUE;
}

void net_print(net n,int part){
    if (n==NULL)return;
    user list;
    if(part==BOYS|| part==GIRLS){
        printf("List of %s sorted by age:\n",part==GIRLS? "girls":"boys");
        list=(part==GIRLS)? n->list_female: n->list_male;

        if(list==NULL) {
            printf("No users\n");
            return;
        }
        
        while(list!=NULL){
            printf("%s\n",list->username);
            list=list->gender_next;
        }
        return;
    }
    list=n->list;
    
    if(list==NULL) {
            printf("No users\n");
            return;
    }
    while(list!=NULL){  //También se puede usar el contador de n->user_count
        if(list->followCount){
            printf("User %s follows %d user(s):\n",list->username,list->followCount);
            for(int i=0;i<list->followCount;i++) 
                printf("%d) %s\n",i+1,list->follows[i]->username);
        }else printf("User %s does not follow anyone yet.\n",list->username);
        
        list=list->global_next;
    }
}
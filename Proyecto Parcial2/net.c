#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "net.h"
#include "bool.h"

#define MAX_FOLLOWS 4

struct strUsuario { 
    char username[30]; 
    int edad; 
    char genero; 
    struct strUsuario* global_next; 
    struct strUsuario* gender_next; 
    struct strUsuario* gender_prev; 
    int followCount; 
    struct strUsuario* follows[MAX_FOLLOWS]; 
}; 


struct str_net { 
    user list; 
    user list_male; 
    user list_female; 
    int  user_count; 
    int  male_count; 
    int  female_count; 
}; 


net net_create()
{
    net n = (net) malloc (sizeof(struct str_net));
    n->list = NULL;
    n->list_male = NULL;
    n->list_female = NULL;
    n->user_count = 0;
    n->male_count = 0;
    n->female_count = 0;

    return n;
}

void net_destroy(net n)
{
    if (!n) 
    {
        return;
    }

    user aux = n->list;

    while(aux)
    {
        user next = aux->global_next;
        free(aux);
        aux = next;
    }

    free(n);
}


user user_create(char username[], int edad, char genero)
{
    user u = malloc((sizeof (struct strUsuario)));
    strncpy(u->username, username, sizeof(u->username) - 1);
    u->username[sizeof(u->username) - 1] = '\0';
    u->edad = edad;
    u->genero = genero;
    u->global_next = NULL;
    u->gender_next = NULL;
    u->gender_prev = NULL;
    u->followCount = 0;

    return u;
}

user findUser(net n, char username[])
{
    user aux = n->list;
    while(aux != NULL)
    {
        if(strcmp(aux->username, username) == 0)
        {
            return aux;
        }

        aux = aux->global_next;
    }

    return NULL;
}


void net_addUserGlobal(user* list, user newUser)
{
    if((*list) == NULL)
    {
        *list = newUser;
        return;
    }

    user aux = (*list);
    while(aux->global_next != NULL)
    {
        aux = aux->global_next;
    }

    aux->global_next = newUser;
}

void net_addUserGender(user* list, user newUser)
{
    if (*list == NULL || (*list)->edad >= newUser->edad) 
    {
        newUser->gender_next = *list;
        if (*list != NULL)
        {
            (*list)->gender_prev = newUser;
        }
        *list = newUser;
        return;
    }

    user aux = *list;
    while (aux->gender_next && aux->gender_next->edad < newUser->edad) 
    {
        aux = aux->gender_next;
    }

    newUser->gender_next = aux->gender_next;
    newUser->gender_prev = aux;
    aux->gender_next = newUser;

    if (newUser->gender_next != NULL) 
    {
        newUser->gender_next->gender_prev = newUser;
    }
}


Bool net_addUser(net n, char username[], int edad, char genero)
{
    if (findUser(n, username) != NULL) //ya existe
    {
        return FALSE;  
    }

    user newUser = user_create(username, edad, genero);

    net_addUserGlobal(&n->list, newUser);

    user* genderList = genero == 'H' ? &n->list_male : &n->list_female;
    net_addUserGender(genderList, newUser);

    n->user_count++;
    if(genero == 'H')
    {
        n->male_count++;
    }
    else n->female_count++;

    return TRUE;
}


Bool net_delUserGlobal(user* list, user todel)
{
    if(*list == NULL) 
    {
        return FALSE;
    }

    user prev = NULL;
    user aux = *list;

    while(aux) 
    {
        if (aux == todel) 
        {
            if (prev == NULL) 
            {
                *list = aux->global_next;
            } 
            else 
            {
                prev->global_next = aux->global_next;
            }
            return TRUE;
        }
        prev = aux;
        aux = aux->global_next;
    }

    return FALSE;
}

void net_delUserGender(user* list, user todel)
{
    if (*list == NULL)
    {
        return;
    }

    if (todel->gender_prev == NULL) 
    {
        *list = todel->gender_next;
    } 
    else 
    {
        todel->gender_prev->gender_next = todel->gender_next;
    }

    if(todel->gender_next != NULL) 
    {
        todel->gender_next->gender_prev = todel->gender_prev;
    }
}

void net_updateFollowers(net n, user deletedUser)
{
    user aux = n->list;
    while (aux)
    {
        for (int i = 0; i < aux->followCount; i++)
        {
            if (aux->follows[i] == deletedUser)
            {
                // desplazar los siguientes followers una posición hacia atras
                for (int j = i; j < aux->followCount - 1; j++)
                {
                    aux->follows[j] = aux->follows[j + 1];
                }
                aux->followCount--;
                i--; // volver a revisar esta posición (ya tiene un nuevo valor)
            }
        }
        aux = aux->global_next;
    }
}


Bool net_delUser(net n, char username[])
{
    user todel = findUser(n, username);
    if (!todel)
    {
        return FALSE;
    }

    net_delUserGlobal(&n->list, todel);

    user* genderList = (todel->genero == 'H') ? &n->list_male : &n->list_female;
    net_delUserGender(genderList, todel);

    net_updateFollowers(n, todel);

    n->user_count--;
    if (todel->genero == 'H') n->male_count--;
    else n->female_count--;

    free(todel);

    return TRUE;
}


Bool net_follow(net n,char username1[], char username2[]){
    if(n==NULL || username1 == NULL || username2 == NULL) return FALSE;
    if(strcmp(username1,username2)==0) return FALSE;    //strcmp retorna 0 si son iguales las cadenas
    user u1= findUser(n, username1);
    user u2=findUser(n,username2);
    
    if (u1==NULL || u2==NULL) return FALSE; 
    if(u1->followCount>=MAX_FOLLOWS) return FALSE;
    
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

Bool net_readNet(net n, char* netFilename)
{
    FILE* netFile = fopen(netFilename, "r");
    if(!netFile)
    {
        return FALSE;
    }

    int count = -1;
    if(fscanf(netFile, "%d\n", &count) != 1)
    {
        fclose(netFile);
        return FALSE;
    }
    
    for (int i = 0; i < count; i++) 
    {
        char username[30];
        int edad;
        char genero;

        if (fscanf(netFile, "%s %d %c", username, &edad, &genero) == 3) 
        {
            net_addUser(n, username, edad, genero);
        } 
        else 
        {
            fclose(netFile);
            return FALSE;
        }
    }


    fclose(netFile);

    return TRUE;
}

Bool net_readFriends(net n, char* friendsFilename)
{
    FILE* friendsFile = fopen(friendsFilename, "r");
    if(!friendsFile)
    {
        return FALSE;
    }

    char username1[30];
    char username2[30];

    while(fscanf(friendsFile, "%s %s", username1, username2) == 2)
    {
        if(!net_follow(n, username1, username2))
        {
            fprintf(stderr, "Warning: %s could not follow %s\n", username1, username2);
        }
    }

    fclose(friendsFile);
    return TRUE;
   
}

Bool net_readFromFile(net n, char* netFilename, char* friendsFilename)
{
    if(!net_readNet(n, netFilename))
    {
        return FALSE;
    }

    if(!net_readFriends(n, friendsFilename))
    {
        return FALSE;
    }

    return TRUE;
}

void net_toTextFile(net n, char* filename)
{
    FILE* file = fopen(filename, "w");

    if(!file)
    {
        perror("Error saving the net\n");
        return;
    }
    
    fprintf(file, "Net has %d users\n", n->user_count);
    user aux = n->list;

    while(aux)
    {
        fprintf(file, "%s,", aux->username);

        for(int i = 0; i < aux->followCount; i++)
        {
            fprintf(file, "%s,", aux->follows[i]->username);
        }
        fprintf(file, "\n");

        aux = aux->global_next;
    }

    fclose(file);
}
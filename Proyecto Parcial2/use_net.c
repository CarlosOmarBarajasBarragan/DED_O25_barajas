#include <stdio.h>
#include <stdlib.h>
#include "TDA_QUEUE\queue.h"
#include "net.h"

int main(){

    queue soporte_online = queue_create();

    queue_enqueue(soporte_online,"Juan");

    int x = queue_isEmpty(soporte_online);

    printf("%d\n",x);

    char * user = queue_peek(soporte_online);

    printf("%s\n",user);

}
#include <stdio.h>
#include <stdlib.h>

int main(){
    int scores[] = {9,8,10,6,4};

    int avg = 0;
    int max = scores[0];
    
    int x = sizeof(scores)/sizeof(scores[0]);

    printf("Size of scores array: %d\n", x);


        return 0;

}
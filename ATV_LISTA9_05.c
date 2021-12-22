#include <stdio.h>
#include <stdlib.h>

void main(void){
    float funcio[300];
    int i=0, pos=0;
    for (i;i<300; i++){
        funcio[i] = 7;
        printf("O valor em %d é %.0f \n", i, funcio[i]);
    }

}


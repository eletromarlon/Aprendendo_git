#include <stdio.h>
#include <stdlib.h>

void main(void){
    float funcio[51];
    int i=0, pos=100;
    for (i;i<51; i++){
        funcio[i] = pos;
        printf("O valor em %d é %.0f \n", i, funcio[i]);
        pos++;
    }

}


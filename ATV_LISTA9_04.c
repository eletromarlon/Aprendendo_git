#include <stdio.h>
#include <stdlib.h>
#define SAL 1045.0

void main(void){
    float funcio[400];
    int i=0, pos=0;
    for (i;i<400; i++){
        funcio[i] = SAL;
    }
    printf("Escolha uma posição do array para verificar: \n");
    scanf("%d", &pos);
    printf("O salário do %d é %.2f", pos, funcio[pos]);
}


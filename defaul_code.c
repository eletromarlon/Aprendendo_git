#include <stdio.h>
#include <stdlib.h>

int a=1, b=4;

void main (){
    int *p, m;

    printf("Valor em a = %i, valor em b = %i \n", a, b);
        m = a;
        p = &b;
        a = b;
        *p = m;
    printf("Valor em a = %i, valor em b = %i \n", a, b);

}

#include <stdio.h>

int main (){
    int *a, *b, c = 8, d = 2;
    a = &c;
    b = &d;
    *a = 5;
    (*a)+=10;
    *b = *a;

    printf("Valor em c = %d d = %d a = %d b = %d", c, d, *a, *b);
}


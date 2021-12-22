#include <stdio.h>
#include <stdlib.h>

void permuta (char *a, char *b){
    char m;

    m = *a;
    *a = *b;
    *b = m;

}

void main (){
    char a, b;

    printf("Digite dois char: \n");
    scanf(" %c", &a);
    scanf(" %c", &b);

    permuta(&a, &b);
    printf("permutados %c e %c", a, b);

}

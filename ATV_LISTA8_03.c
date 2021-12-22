#include <stdio.h>
#include <stdlib.h>

void sw (int *v1, int *v2){
    int troca;
    troca = *v1;
    *v1 = *v2;
    *v2 = troca;
}

void main ()
{
    int a, b;

    printf("Digite um número para A:\n");
    scanf("%d", &a);
    printf("Digite um número para B:\n");
    scanf("%d", &b);

    if (a>=b){
        printf("Ficamos em A com %d e B com %d", a, b);
    } else if (a<b){
        sw(&a, &b);
        printf("Ficamos em A com %d e B com %d", a, b);
    }

}

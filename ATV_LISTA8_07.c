#include <stdio.h>
#include <stdlib.h>

float *pos, *neg;

double pi(int n){
    float resul;
        resul = 4 * ((*pos)+ (*neg));
    return resul;
    }


int main (){
    int n, i;
    float resulPosit = 0.0, resulNegat = 0.0;
    printf("Digite o número de elementos para Leibniz: \n");
    scanf("%d", &n);

    //guarda_n = &n;
    for (i = 1;i<=n;i+4){
        resulPosit = (1/i) + resulPosit;
    }
    for (i=3;i<=n;i+4){
        resulNegat = (-1/i) - resulNegat;
    }

    neg = &resulNegat;
    pos = &resulPosit;


    pi(1);

    printf("O valor de saída é igual a: %lf ", pi(1));
    return 0;
}


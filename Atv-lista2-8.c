#include<stdio.h>

int main(){
        int valor, milhar, centena, dezena, a, b, c;
        printf("Digite um número de 4 dígitos:");
        scanf("%d", &valor);
        milhar = valor % 1000;
        centena = milhar % 100;
        dezena = centena % 10;
        a = valor/1000;
        b = milhar/100;
        c = centena/10;
        printf("%d %d %d %d", dezena, c, b, a);
        return 0;
}



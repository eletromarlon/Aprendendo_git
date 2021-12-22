#include <stdio.h>
#include <stdlib.h>


float calculaF(int n){  //Função responsável por calcular o fatorial
    if (n==1)
        return 1;
    else
        return (n*calculaF(n-1));
}

float calculaS(int n){  //Função responsável por realizar o somatório
    if (n==1)
        return 1;
    else
        return (1/calculaF(n)) + calculaS(n-1);
}

int main(){
    int n;

    do{
    printf("Digite o valor para n: \n");
    scanf("%i", &n);
    } while (n<1);

    /*Poderia ser realizado o mesmo calculo utilizando apenas uma
    função recursiva para o fatorial e o seguinte "for":
    for (int i=1;i<=n;i++){
        temp += 1/calculaF(i);
    }*/

    printf("Resultado: %.3f", calculaS(n));

}

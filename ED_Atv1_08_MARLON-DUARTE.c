#include <stdio.h>
#include <stdlib.h>


float calculaS(int n){
    if (n==1)
        return 1;
    else
        return (n*calculaS(n-1));
}

int main(){
    int n;
    float guarda=0;

    do{
    printf("Digite o valor para n: \n");
    scanf("%i", &n);
    } while (n<1);

    for (int i=1;i<=n;i++){
        guarda += 1/calculaS(i);
    }

    printf("Resultado: %.3f", guarda);

}

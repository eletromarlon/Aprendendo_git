#include <stdio.h>
#include <stdlib.h>

float superF(int n){    //Função que desenvolve o fatorial

    if (n==1){
        return 1;
    }
    else {
        return (n*superF(n-1));
    }
}

void main(){
    int n;
    float guarda=0;

    printf("Digite o número de elementos: \n");
    scanf("%d", &n);

    for (int i=1;i<=n;i++){ //For responsável por realizar o somatório.
        guarda += superF(i);
    }
printf("resultado %.2f\n\n", guarda);
}

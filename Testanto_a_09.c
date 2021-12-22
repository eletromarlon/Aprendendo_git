#include <stdio.h>
#include <stdlib.h>

float superF(int n){
    float guarda;
    if (n==1){
        return 1;
    }
    else {
        guarda = (n*superF(n-1));
    }

    for (int i=1;i<=n;i++){
        guarda += superF(i);
    }

}

void main(){
    int n;
    float guarda=0;
    printf("Digite o número de elementos: \n");
    scanf("%d", &n);

    printf("resultado %f", superF(n));
}

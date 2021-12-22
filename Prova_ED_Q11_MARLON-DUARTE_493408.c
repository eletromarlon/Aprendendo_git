#include <stdio.h>
#include <stdlib.h>
#define tam 10

void mostra_vetor(char *vetor){
    printf("\n\n");
    for (int i=0;i<tam;i++){
        printf(" %c ", vetor[i]);
    }
}

void organiza_vetor(char *vetor){
    char temp, vLetra[tam], vNum[tam];
    int j=0;
    for (int i=0;i<tam;i++){
        temp = vetor[i];
        if ((temp >= 48) && (temp <= 57)){
            vNum[j] = temp;
        }
        else if ((temp >= 65) && (temp <=90)){
            vLetra[j] = temp;
        }
    }
    for (int i=0;i<tam;i++){
        printf(" %c", vNum[i]);
    }
    for (int i=0;i<tam;i++){
        printf(" %c", vLetra[i]);
    }
}
int main (){
    char vetor[tam]={'A','1','N','5','T','7','W','8','O'};
    int x;
    mostra_vetor(vetor);
    organiza_vetor(vetor);
    return 0;
}

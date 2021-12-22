#include <stdio.h>


int main (){
    float altura, degraus;
    printf("Digite a altura que deseja subir em metros: \n");
    scanf("%f", &altura);
    degraus = (100*altura/30);
    printf("%.2f degraus", degraus);

    return 0;
}

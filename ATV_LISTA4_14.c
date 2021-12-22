#include <stdio.h>


int main (){
    float altura, degrau, convert;
    printf("Digite a altura que deseja subir em metros: \n");
    scanf("%f", &altura);
    printf("Digite a altura dos degraus em cm \n");
    scanf("%f", &degrau);
    convert = (degrau/100); //transformei em metros
    printf("%.0f degraus", (altura/convert)); //basta dividir a altura a subir pela altura do degrau

    return 0;
}


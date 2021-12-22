#include <stdio.h>
#define p 3.1415
int main (){
    float diam;
    printf("Digite o diâmetro da circunferência:");
    scanf("%f", &diam);
    printf("A área da circunferência é de aprox. %.2f", p*((diam/2)*(diam/2)));
    return 0;
}

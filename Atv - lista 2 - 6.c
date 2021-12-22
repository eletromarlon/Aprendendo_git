#include <stdio.h>

main (){
    float a;
    printf("Digite o valor da temperatura em Celcius:");
    scanf("%f", &a);
    printf("%.2f Celcius em Fahrenheit fica: %.2f", a,((a*9/5)+32));
}

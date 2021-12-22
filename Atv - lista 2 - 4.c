#include <stdio.h>

main (){
    float a, b, c, d;
    printf("Digite um valor!");
    scanf("%f", &a);
    printf ("Digite um valor!");
    scanf("%f", &b);
    printf ("Digite um valor! (ou zero para nenhum)");
    scanf("%f", &c);
    printf ("Digite um valor! (ou zero para nenhum)");
    scanf("%f", &d);
    printf("A média dos valores inseridos é %.2f", (a + b + c + d)/4);


}

#include <stdio.h>

main (){
    float a, b, c, d;
    printf ("Digite um número!");
    scanf("%f", &a);
    printf ("Digite um número!");
    scanf("%f", &b);
    printf ("Digite um número! (ou zero para nenhum)");
    scanf("%f", &c);
    printf ("Digite um número! (ou zero para nenhum)");
    scanf("%f", &d);
    printf("A soma total dos números digitados é %.2f", (a + b + c + d));
}

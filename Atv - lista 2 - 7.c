#include <stdio.h>

main (){
    float a, b;
    printf("Digite um valor:");
    scanf("%f", &a);
    printf("Digite outro valor:");
    scanf("%f", &b);
    if (a>b){
        printf("O valor maior é %.2f e o menor é %.2f", a, b);
        }
        if (b>a){
            printf("O valor maior é %.2f e o menor é %.2f", b, a);
            }
            if (b==a){
                printf("Os valores %.2f e %.2f são iguais", a, b);
                }
}

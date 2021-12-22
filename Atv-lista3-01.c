#include <stdio.h>

int main (){
    float base, altura;
        printf("Informe a base do triângulo:");
        scanf("%f", &base);
        printf("Informe a altura do triângulo:");
        scanf("%f", &altura);
        printf("A áres do triângulo é: %.2f", ((base*altura)/2));
        return 0;
}

#include <stdio.h>

int main () {
    float sal1, cheque;
    printf("Digite o salário recebido \nR$  ");
    scanf("%f", &sal1);
    printf("Digite o valor emitido em cheques \nR$  ");
    scanf("%f", &cheque);
    printf("-------------Saldo da conta ------------ \n");
    printf("O saldo atual da conta é -----      %.2f \n", sal1-(cheque+(cheque*0.0038)));


    return 0;
}

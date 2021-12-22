#include <stdio.h>
#include <stdlib.h>

int main (){
    float salarioBruto;
    printf("Digite o valor do salário do funcionário: \n");
    scanf("%f", &salarioBruto);
    printf("=====Salário do Funcionário===== \n");
    printf("Salário Bruto -------------R$ %.2f \n", salarioBruto);
    printf("Desconto do IR-------------R$ %.2f \n", salarioBruto*0.2);
    printf("Desconto INSS -------------R$ %.2f \n", salarioBruto*0.1);
    printf("Salário Líquido------------R$ %.2f \n", salarioBruto - ((salarioBruto*0.2) + (salarioBruto*0.1)));




	return 0;
}

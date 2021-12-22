#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num = 0, contador = 0, menor_valor, maior_valor, anterior = 0, valores_par = 0;
    float soma_par = 0;
    do
    {
        maior_valor = num;
        anterior = num;
        printf("Digite um valor: \n");
        scanf("%d", &num);
        contador++;
        if (contador == 1)
        {
            menor_valor = num;
        }

        if(num%2 == 0)
        {
            valores_par++;
            soma_par = soma_par + num;
        }

    }while (anterior < num);

    printf("\t O total de números digitados foi:         %d \n", contador);
    printf("\t O menor valor da sequência crescente foi: %d \n ", menor_valor);
    printf("\t O maior valor da sequência crescente foi: %d \n ", maior_valor);
    printf("\t A média dos pares é:                      %.2f \n ", soma_par/valores_par);




    maior_valor = num;
	return 0;
}

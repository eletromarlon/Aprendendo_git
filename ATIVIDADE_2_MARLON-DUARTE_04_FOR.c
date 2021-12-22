#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int i, n, resultado = 1, contador = 1;
    printf("Digite um número inteiro positivo: \n");
    scanf("%d", &n);

    if (n<0)
    {
        printf("\t\t Somente inteiros positivos! \n");
    }   else if (n == 0)
        {
            printf("\t %d fatorial = %d \n\n ", n, resultado);
        }   else if (n>0)
            {
                for (i=1; i <= n; i++)
                {
                resultado = resultado * i;
                }

                printf("\t %d fatorial = %d \n\n ", n, resultado);

            }



	return 0;
}

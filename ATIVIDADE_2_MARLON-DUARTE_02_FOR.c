#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num, teste, i=2, somador = 1;

    printf("Digite um número: \n");
    scanf("%d", &num);
    if (num<1)
    {
        printf("\t\t Digite apenas inteiros maiores que 1 \n");
    }   else if (num <=2)
        {
            printf("\t Número primo! \n");
        }else
        {
            for (i; i < num; i++)
            {
                teste = num % i;
                somador = somador * teste;
            }

            if (somador == 0)
            {
                printf("\t Este número não é primo \n");
            }   else
                {
                    printf("\t Número primo! \n");
                }

        }
	return 0;
}

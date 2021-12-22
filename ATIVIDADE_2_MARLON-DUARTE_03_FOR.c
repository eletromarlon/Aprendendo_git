#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    float resultado = 0, i;

    printf("Digite um número inteiro positivo: \n");
    scanf("%d", &n);

        for (i=1;i <= n; i++)
        {
            resultado = (resultado) + (1/i);
        }
    printf("\t O resultado é %f \n ", resultado );
	return 0;
}

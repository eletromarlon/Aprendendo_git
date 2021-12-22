#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num, contador = 0;

    do
    {
        printf("Digite um valor: \n");
        scanf("%d", &num);
        if (num > 0)
        {
            contador++;
        }
    }while (num != 0);
    printf("\t O total de números positivos: %d \n\n ", contador);
	return 0;
}

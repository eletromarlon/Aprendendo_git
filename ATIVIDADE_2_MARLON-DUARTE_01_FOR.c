#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num = 1, contador = 1, num_anterior, fibo;
    for  (num; num<=8; num++) //Alterando o valor de "num<=8", você determina até que valor você apresentará
    {
        printf("\t %d \n", contador);
        fibo = contador;
        contador = contador + num_anterior;
        num_anterior = fibo;
    }
	return 0;
}

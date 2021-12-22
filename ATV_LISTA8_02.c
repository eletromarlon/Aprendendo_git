#include <stdio.h>
#include <stdlib.h>

void troca(int *v1, int *v2){
    int temp;
    temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}

int main ()
{
    int a, b, c;// *v1, *v2;

    printf("Digite um valor: \n");
    scanf("%d", &a);
    printf("Digite um valor: \n");
    scanf("%d", &b);

    printf("em a temos %d e em b temos %d \n", a, b);

    troca (&a, &b);

    printf("Mudança!\n");
    printf("Em a temos %d e em b temos %d \n", a, b);

	return 0;
}

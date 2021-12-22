#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a1, *a2;
    float b1, *b2;
    char c1, *c2;

    a1 = 2;
    b1 = 4;
    c1 = '6';

    a2 = &a1;
    b2 = &b1;
    c2 = &c1;

    printf("Valor em a1 = %d \n", a1);
    printf("Valor em b1 = %.2f \n", b1);
    printf("Valor em c1 = %c \n", c1);

    *a2 = 8;
    *b2 = 10;
    *c2 = 's';

    printf("Depois da alteração! \n");

    printf("Valor em a1 = %d \n", a1);
    printf("Valor em b1 = %.2f \n", b1);
    printf("Valor em c1 = %c \n", c1);

	return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main (){
    float x;
    printf("Valor de x: \n");
    scanf("%f", &x);

    printf("O valor de y para x = %.0f é %.2f", x, (1/(x+1))+3);

	return 0;
}

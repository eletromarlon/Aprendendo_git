#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int contador = 0, contador_altura = 0;
    float altura, maior = 0, somador = 0;

    do
    {
        printf("Digite a altura: \n");
        scanf("%f", &altura);
        if (altura > 0)
        {
            contador++;
            somador = somador + altura;

                if (maior < altura)
                {
                    maior = altura;
                }
                if (altura > 2)
                {
                    contador_altura++;
                }
        }
    }while (altura > 0);

    printf("\t A maior altura é: %.2f \n", maior);
    printf("\t A média do grupo é: %.2f \n", somador/contador);
    printf("\t Os com mais de 2 metros: %d \n", contador_altura);


	return 0;
}

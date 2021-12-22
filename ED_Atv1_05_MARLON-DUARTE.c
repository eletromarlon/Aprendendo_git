#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct campos {
    float x[5];
    float y[5];
};

float dist(float ax, float bx, float ay, float by){
    float d;

    printf("\n\tax = %.2f bx = a %.2f ay = %.2f by = %.2f \n", ax, bx, ay, by);
    d = sqrt (((bx-ax)*(bx-ax)) + ((by-ay)*(by-ay)));
    //for (int i=0;i<5;i++)
    //d = sqrt (((campos.x[i+1] - campos.x[i])*(campos.x[i+1] - campos.x[i])) + (((campos.y[i+1] - campos.y[i])*(campos.y[i+1] - campos.y[i]))));

    return d;
}

void main(){

    struct campos c={};
    float guardar=0, resultado;

    for (int i=0;i<5;i++){
    printf("Digite 5 valores para x:\n %i º  valor ", i+1);
    scanf("%f", &c.x[i]);
    }
    for (int i=0;i<5;i++){
    printf("Digite 5 valores para y:\n %i º  valor ", i+1);
    scanf("%f", &c.y[i]);
    }

    for (int i=0;i<5;i++){
        printf("\t\tValor no x indice %i = %.2f \n", i, c.x[i]);
        printf("\t\tValor no y indice %i = %.2f \n", i, c.y[i]);

    }

    for (int i=0;i<5;i++){
        resultado = dist(c.x[i], c.x[i+1], c.y[i], c.y[i+1]);
        printf("i = %i - i+1 = %i\n", i, i+1);
        if ((i==0)||(resultado<guardar)){
            guardar = resultado;
        }

    }

    printf("\n\t\tA menor distância entre os pontos é %.2f\n\n", guardar);
}

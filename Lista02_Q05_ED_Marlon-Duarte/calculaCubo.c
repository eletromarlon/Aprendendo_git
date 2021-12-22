#include <stdio.h>
#include "calculaCubo.h"

void medida(float valor){
    float saida=valor;
    printf("\nOs lados do cubo medem: %f", saida);
}
float area(float lado){
    return ((lado*lado)*(6));
}
float volume(float lado){
    return (lado*lado*lado);
}

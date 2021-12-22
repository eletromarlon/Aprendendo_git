#include <stdio.h>
#include "numcomplex.h"

void cria (float x, float y){
    printf("%.0f + %.0fi", x, y);
}
void apaga (float x, float y){  //Não entendi o que deve ser feito
                                //Vou deixar vazio por enquanto
}
void soma (float x1, float y1, float x2, float y2){
    float a, b;
    a = x1 + x2;
    b = y1 + y2;
    cria(a, b);

}
void subtrai(float x1, float y1, float x2, float y2){
    float a, b;
    a = x1 - x2;
    b = y1 - y2;
    cria(a, b);

}
void multiplica(float x1, float y1, float x2, float y2){
    float a, b;
    a = (x1*x2) - (y1*y2); //Não está correto o calculo
    b = (x1*y2) + (y1*x2); //precisa ser revisto
    cria(a, b);

}


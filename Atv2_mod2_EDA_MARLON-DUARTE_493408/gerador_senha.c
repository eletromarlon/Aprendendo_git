#include "gerador_senha.h"

int gera_senha (int op1, int op2, int contador){
    char senha[5];
    int temp;
    temp = (op1 * 10000) + (op2 * 1000) + (contador); //12000 22000 11000
    //printf("\nValor de temp %d", temp);
    sprintf(senha, "%d", temp);
    printf("\n\nUltima senha gerada %s", senha);
    return atoi(senha);
}


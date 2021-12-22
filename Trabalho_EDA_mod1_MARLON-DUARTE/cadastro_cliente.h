#ifndef CADASTRO_CLIENTE_H_INCLUDED
#define CADASTRO_CLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s{
    char nome[30];
    char cpf[12];
    char end[50];
    int cartao_credito;
}cadastro;

cadastro cadastro_cliente();

#endif // CADASTRO_CLIENTE_H_INCLUDED

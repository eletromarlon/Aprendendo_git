#ifndef CABECA_H_INCLUDED
#define CABECA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    int idade;
} cadastro;

cadastro *estudante();

void create (char[20], int idade);


#endif // CABECA_H_INCLUDED

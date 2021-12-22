#ifndef SIS_VALIDACAO_H_INCLUDED
#define SIS_VALIDACAO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    float valor;
} item;



void criar_repositorio(item *p);
void adicionar(item *p, int cod, float valor);
void imprimir_repositorio(item *p);

//tratar
int tamanho();

//presquisar_valor
//pesquisar_codigo
int esta_cheio();
int esta_vazio();

#endif // SIS_VALIDACAO_H_INCLUDED

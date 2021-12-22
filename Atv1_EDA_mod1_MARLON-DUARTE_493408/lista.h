#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "itens.h"

// CONSTANTES PARA O BUFFERS DE TECLADO E OUTROS
#define MAX 30


FILE *sel;

//ESTRUTURA DO TIPO Selecao
typedef struct{
	char valor[MAX]; // valor e cod ou nome
	int quantidade; // quantidade
	Produto produto; // estrutura de retorno salva no arquivo
}Selecao;

void BaseSelecao(char cod[]);

void inicializarSelecao(Selecao *selecao);

void lerSelecao(Selecao *selecao);

void exibirSelecao(Selecao *selecao);

void cadastrarSelecao();

void listarSelecao();


#endif // LISTA_H_INCLUDED

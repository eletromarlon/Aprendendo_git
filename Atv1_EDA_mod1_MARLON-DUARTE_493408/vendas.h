#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"
#include "lista.h"
#include "cartao.h"
// CONSTANTES PARA O BUFFERS DE TECLADO E OUTROS
#define MAX 30
#define ARQ_VENDAS "vendas.txt"

FILE *ven;

//ESTRUTURA DO TIPO PESSOA
typedef struct{
	char cod[MAX];
	char nome[MAX];
	Selecao selecao[MAX];
	int pagamento;
	float total;
	int tamanho;
}Venda;

void baseVenda();

void inicializarVenda(Venda *venda);

void exibirVenda(char nome[MAX], char cod[MAX]);

void carregarSelecao(char *cod, Venda *venda);

void carregarVenda(char *cod, char *nome);

void exibirProdVenda(Venda *venda);

void listarVenda();

void exibirListaVenda(Venda *venda);

void AlterarVenda(char *cod);

int PesquisarVenda(char *cod);

int carregaCodigo();
#endif // VENDAS_H_INCLUDED

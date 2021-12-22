#ifndef CAIXAS_H_INCLUDED
#define CAIXAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


//int cx[10], cont_caixas=0; //Contador de caixas informa quais caixas estao abertos

void abrir_caixa ();
int status_caixas ();
int fechar_caixa ();
int senha_caixa (int chave);
void senha_caixa_2(int chave);
void caixa_livre ();
int caixa_vago ();
int num_caixas();

#endif // CAIXAS_H_INCLUDED

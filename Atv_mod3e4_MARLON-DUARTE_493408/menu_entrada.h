#ifndef MENU_ENTRADA_H_INCLUDED
#define MENU_ENTRADA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerador_ID.h"
#include "tabela_hash.h"
#define barra 50

void entrada();
void contorno();
int opcoes_correlatas();
int verifica_x(int x);
void guarda_assunto(int ID_assunto, int ID_usuario);
void assuntos_users ();
int guardar_no_repositorio(int codigo, char * valor);
int imprime_repositorio();


#endif // MENU_ENTRADA_H_INCLUDED

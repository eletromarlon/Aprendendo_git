#ifndef FILA_ATENDIMENTO_H_INCLUDED
#define FILA_ATENDIMENTO_H_INCLUDED
#include "lcde.h"

/**Struct para armazenamento das informações!
Apresenta complexidade constante, O(1), pois se destina apenas a reserva de
espaço de memória para alocar os dados que serão movimentados pelo usuário
*/
typedef struct estrutura_paciente{
    char nome[50];
    int idade;
    long int codigo;
} Paciente;

void iniciar_fila();
void inserir_paciente();
void imprimir_fila();
void imprimir_da_vez();
void todos_atendidos();
void limpar_lista();
void status();


#endif // FILA_ATENDIMENTO_H_INCLUDED

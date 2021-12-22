#include <stdio.h>
#include <stdlib.h>
#include "fila_atendimento.h"

int main(){

    iniciar_fila();
    inserir_paciente();
    system("clear");
    inserir_paciente();
    system("clear");
    inserir_paciente();
    system("clear");
    inserir_paciente();
    system("clear");
    inserir_paciente();
    system("clear");

    imprimir_fila();
    imprimir_da_vez();
    imprimir_da_vez();
    imprimir_da_vez();
    imprimir_da_vez();
    imprimir_da_vez();
    imprimir_da_vez();

    return 0;
}

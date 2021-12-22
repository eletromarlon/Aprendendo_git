#include <stdio.h>
#include <stdlib.h>
#include "sis_validacao.h"

int main(){
    item *p= criar_repositorio(p);
    adicionar(p, 7891, 15.50);
    printf("\nTamanho do repositório %d\n", tamanho());
    printf("\nStatus do repositorio %d (0 - vazio / 1 - cheio) \n", esta_cheio());
    printf("\nStatus do repositorio %d (1 - vazio / 0 - cheio) \n", esta_vazio());
    imprimir_repositorio(p);

    return 0;
}

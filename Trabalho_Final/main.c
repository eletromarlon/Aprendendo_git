#include <stdio.h>
#include <stdlib.h>
#include "vetor_produtos.h"

int main(){
    create_repositorio();

    add(1892,15.5, 1);
    add(1893,14.5, 1);
    add(1894,16.5, 1);
    add(1895,12.5, 1);
    add(1896,6.0, 1);
    add(1897,5.5, 1);
    add(1898,6.1, 1);
    add(1899, 7.2, 1);

    imprime_repositorio();

    limpar_repositorio();

    create_repositorio();

    add(2541,15.5,2);
    add(2542,14.5,2);
    add(2543,16.5,2);
    add(2544,12.5,2);
    add(2545,6.0,2);
    add(2546,5.5,2);
    add(2547,6.1,2);
    add(2548, 7.2,2);

    imprime_repositorio();

    limpar_repositorio();

    create_repositorio();

    add(3641,15.5,3);
    add(3642,14.5,3);
    add(3643,16.5,3);
    add(3644,12.5,3);
    add(3645,6.0,3);
    add(3646,5.5,3);
    add(3647,6.1,3);
    add(3648, 7.2,3);

    imprime_repositorio();

    limpar_repositorio();

    create_repositorio();

    add(4641,15.5,4);
    add(4642,14.5,4);
    add(4643,16.5,4);
    add(4644,12.5,4);
    add(4645,6.0,4);
    add(4646,5.5,4);
    add(4647,6.1,4);
    add(4648, 7.2,4);

    imprime_repositorio();

    limpar_repositorio();

    create_repositorio();

    add(5641,15.5,5);
    add(5642,14.5,5);
    add(5643,16.5,5);
    add(5644,12.5,5);
    add(5645,6.0,5);
    add(5646,5.5,5);
    add(5647,6.1,5);
    add(5648, 7.2,5);
    imprime_repositorio();

    printf("#########################################################################");
    printf("\nO digito inicial do código corresponde ao número da questão da atividade!\n");
    printf("#########################################################################");

    limpar_repositorio();

    return 0;
}

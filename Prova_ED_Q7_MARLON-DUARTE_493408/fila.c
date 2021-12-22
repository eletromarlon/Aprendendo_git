#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void comeca(int *vetor, int espaco){ //Aloca memória suficiente no menu de acordo com a constante

    vetor = (int*) malloc (espaco * sizeof(int));
    fim = 0;
    if (vetor == NULL)
        printf("\n\nErro de alocação de memória:");
    else
        printf("\n\nFila iniciada com sucesso:");
}

int vazio(int *vetor){  //Verificador simples de status do vetor
    if (fim == 0)
        return 1;       //Caso verídico para vazio retornará 1;
    else
        return 0;
}

int cheio(int *vetor, int espaco){ //Verificador simples de status do vetor
    if (fim == espaco)
        return 1;           //Caso verídico para cheio retornará 1
    else
        return 0;
}

void insere(int *vetor, int x, int espaco){ //Funçao de inserção de valores dentro do vetor
    if (cheio(vetor, espaco) == 1)
        printf("\n\nNão há mais espaço na fila!");
    else{
        vetor[fim] = x;
        fim++;
        printf("\n\nValor inserido com sucesso!");
    }
}

int tamanho(int *vetor){    //Retorna o tamanho do vetor
    return fim;
}

int retira(int *vetor){ //Retorna um item do vetor
    int saida;
    if (vazio(vetor) == 1){
        printf("\n\nFila vazio!");
        exit (0);
    }
    else{
        saida = vetor[0];           //Variavel saida guarda o primeiro item inserido na fila
        for (int i=0;i<fim;i++){    //Esse "for" faz descer todos os elementos da fila tornando o indice 0
            vetor[i] = vetor[i+1];  //novamento o início da fila
        }
        fim--;
    }
    return saida;
}

void imprime(int *vetor){   //Função para impressão de todos os elementos dentro da fila
    if (vazio(vetor) == 1)
        printf("\n\nFila vazia!");
    else {
        printf("\n\n");
        for (int i=0;i<fim;i++){
            printf(" %d ", vetor[i]);
        }
    }
}






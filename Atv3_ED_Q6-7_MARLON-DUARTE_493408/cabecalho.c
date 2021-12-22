#include "cabecalho.h"
void comeca(int *vetor,int espaco){
    vetor = (int*) malloc (espaco * sizeof(int));
    topo = -1;
    if (vetor == NULL)
        printf("\n\nErro ao criar a pilha!!!");
    else
        printf("\n\nPilha iniciada com sucesso!");
}

int vazio(int *vetor){
    if (topo < 0)
        return 1;
    else
        return 0;
}

int cheio(int *vetor, int espaco){
    if (topo == espaco-1)
        return 1;
    else
        return 0;
}

void insere(int *vetor, int x){
    topo++;
    vetor[topo]=x;
}

void tamanho(int *vetor){
    printf("O tamanho da pilha é %d\n", topo+1);
}

int retira(int *vetor){
    int x;
    x=vetor[topo];
    topo--;
    return x;
}

void imprime(int *vetor){
    for (int i=0;i<=topo;i++){
        printf(" %d ", vetor[i]);
    }
}

void inverte(int *vetor, int espaco){
    int temp[espaco], topo2;
    topo2=topo;
    if (vazio(vetor) == 1)
        printf("\n\nPILHA VAZIA!!!");
    else {
            for (int i=0;i<=topo;i++){
                temp[i]=vetor[topo2];
                topo2--;
            }

            topo2 = topo;
            topo = -1;

            for (int i=0;i<=topo2;i++){
                insere(vetor, temp[i]);
                //printf("O valor em temp indice %d é %d\n", i, temp[i]);
            }

    }
}


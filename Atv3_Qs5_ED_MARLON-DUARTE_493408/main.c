#include <stdio.h>
#include <stdlib.h>
#include "pilha5.h"

int main(void)
{
    node *PILHA = (node *) malloc(sizeof(node));    //É necessário um ponteiro que se ligará às outras funções.
                                                    //Esse ponteiro precisa ter o mesmo tamanho, por isso precisamos que
                                                    //ele tenha o tamanho de um "NO"

    if(!PILHA){                                     //A exclamação nega uma comparação com NULL
        printf("Sem memoria disponivel!\n");
        exit(1);
    }else{
        inicia(PILHA);                              //Apontando *prox para NULL
        int opt;

        do{
            opt=menu();
            opcao(PILHA,opt);
        }while(opt);

        free(PILHA);
        return 0;
    }
}

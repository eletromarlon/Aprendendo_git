#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define tam 10
#define tam2 5

int main(){
    int vetor[tam], x=10, opc=1, vetor_secundario[tam2], opc2, fim_fila2=0, temp;

    while (opc != 0){ //Estrutura de repetição para menu global

    opc2=1; //Iniciando dentro do while

    printf("\n\n ----------------------- "); //Menu de opções para operação com a Fila;

    printf("\n 0 - Sair do programa");
    printf("\n 1 - Iniciar a Fila ");
    printf("\n 2 - Estado da Fila ");
    printf("\n 3 - Inserir um valor ");
    printf("\n 4 - Retirar um valor ");
    printf("\n 5 - Inserir uma nova fila ");
    printf("\n 6 - Concatenar as fila do programa ");
    printf("\n 7 - Imprimir fila ");
    printf("\n 8 - Tamanho da fila ");
    printf("\n 9 - Imprimir fila recursivamente "); //Opção que resolve a questão 9 da PROVA de ED



    printf("\n\n Escolha uma opcao: ");
    scanf("%d",&opc);

        switch (opc){

            case 0: {   //encerramento do menu global
                printf("\n\nPrograma encerrado!");
                continue;
            }
            case 1: {
                comeca(vetor, tam);
                break;
            }
            case 2: {   //Opçaõ que retorna o status da fila
                if (vazio(vetor) == 1)
                    printf("\n\nFila vazia!");
                else if (cheio(vetor, tam) == 1)
                    printf("\n\nFila cheia!");
                else
                    printf("\n\nFila contém elementos!");
            break;
            }
            case 3: {
                printf("\n\nDigite uma valor para inserir:");
                scanf("%d", &x);
                insere(vetor, x, tam); //Repasso a constante "tam" evitando chamar outra função (no caso "cheio()")
                break;
            }
            case 4: {
                printf("\n\nValor retirado da fila: %d", retira(vetor));
                break;
            }
            case 5: {   //Entrada para um menu secundário de um vetor secundário
                printf("\n\nVocê pode criar uma segunda fila de até %d elementos!", tam2);
                while (opc2 != 0){

                printf("\n\n ----------------------- ");
                printf("\n 0 - Sair");
                printf("\n 1 - Inserir valor na fila secundária:"); //A retirada de itens desse segundo vetor exigiria
                printf("\n 2 - Imprimir fila secundária:");         //outras funções. Por isso limitei em apenas preencher um
                printf("\n\n Escolha uma opcao: ");                 //novo vetor por conta do usuário
                scanf("%d", &opc2);

                    switch (opc2){
                        case 0:{
                            printf("\n\nEncerrado!");
                            continue;
                        }
                        case 1:{
                            if (fim_fila2 == tam2) //Verifica o status do vetor secundario
                                printf("\n\nFila já está cheia:");
                            else{
                                printf("\n\nDigite uma valor para inserir:");
                                scanf("%d", &x);
                                vetor_secundario[fim_fila2] = x; //Adiciona valores no vetor secundário
                                fim_fila2++;
                            }break;
                        }
                        case 2:{    //Mostra os itens que estão inseridos dentro do vetor secundário
                            printf("\n\n");
                            for(int i=0;i<fim_fila2;i++){
                                printf(" %d ", vetor_secundario[i]);
                            }
                            break;
                        }

                    }

                }
                break;
            }
            case 6: {   //Concatenação das filas. Vetor primário F1 e secundário F2.
                    printf("\n\nA primeira fila é F1 e a secundária F2!");

                    if (cheio(vetor,tam) == 1)
                        printf("\n\nF1 está cheio");
                    else{
                        printf("\n\nConcatenando as filas!");
                        temp = fim_fila2;   //Armazena o valor de fim de F2 pois será alterado no processo.
                        for (int i=0;i<temp;i++){
                            insere(vetor, vetor_secundario[0], tam);    //Insere na sequência de F1 o início de F2
                            for(int j=0;j<fim_fila2;j++){
                                vetor_secundario[j]=vetor_secundario[j+1]; //Atualiza o F2, tornando o indice 0 o inicio da fila
                                fim_fila2--;
                            }
                        }
                    }
                    break;
                }
            case 7: {
                imprime(vetor); //Chama a função que imprimei o vetor primário (F1)
                break;
            }
            case 8:{
                printf("\n\nO tamanho da fila é: %d", tamanho(vetor));
                break;
            }
            case 9:{
                printf("\n\nPrograma para impressão de fila recursivamente:");
                print_rec(vetor);
            break;
            }
        }
    }

    return 0;
}

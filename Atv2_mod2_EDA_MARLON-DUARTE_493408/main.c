#include <stdio.h>
#include <stdlib.h>
#include "menu_atendimento.h"
#include "caixas.h"
#include "fila_pref.h"

int main(){
    int opc=1, esc;
    Heap *heap = criar_heap(100, 0); //Fila de preferencial --- Limite estabelecido em 100 pessoas
    Heap *heap2 = criar_heap(100, 0); //Fila de Publico Geral --- Limite estabelecido em 100 pessoas

        if( heap == NULL ){
            printf("\n\n\t\tProblema de memória\n");
            printf("\n\n\t\tTente novamente ou reinicie a máquina\n");
            return -1;
        }

        if( heap2 == NULL ){
            printf("\n\n\t\tProblema de memória\n");
            printf("\n\n\t\tTente novamente ou reinicie a máquina\n");
            return -1;
        }


    while (opc != 0){
        int temp=-1;
        printf("\n\n\tDing dong!!!!!");
        status_caixas();
        printf("\n");

        printf("\n====== Menu Principal ====== ");
        printf("\n(0) Fechar                   ");
        printf("\n(1) Atendimento              ");
        printf("\n(2) Caixas                   ");
        printf("\n(3) Próxima senha            ");
        printf("\n(4) Fechar o Último caixa    ");
        printf("\n(5) Desocupar um caixa       ");


        printf("\n\n");
        scanf("%d", &opc );
        switch (opc){
            int senha_temp;
            case 0:
                continue;
            case 1:
                temp = menu_entrada();
                if ((temp < 12000) || (temp > 13000)){ //Fila com preferência para Pessoa Jurídica
                    insert(heap, temp);
                }   else
                        insert(heap2, temp);
                break;
            case 2:
                status_caixas();
                printf("\n\n\tDesejas abrir caixas? (1)Sim \t (0)Não \n");
                printf("\n\n");

                scanf("%d", &esc);
                    if (esc == 1)
                        abrir_caixa();
                system("clear");
                break;
            case 3:
                temp = status_caixas();
                if (caixa_vago() == 0){
                    printf("\n\n\tCaixas lotados!\n");
                    printf("\n\n\tVocê pode desocupar os caixas no menu inicial!\n");
                    break;
                }
                system("clear");
                    if (num_caixas() > 1){
                        if (senha_caixa(0) == 0) {
                        printf("\n\n\tVocê pode desocupar os caixas no menu inicial!");
                        } else {
                            if (temp == 0){
                                break;
                            }   else {
                                    printf("\n\t(0) Preferencial ou (1) Geral?");
                                    printf("\n\n");

                                    scanf("%d", &temp);

                                    if (temp == 0){
                                        senha_temp = PopMin(heap);
                                        if (senha_temp == -1){
                                            printf("\n\n\n\tFila vazia!");
                                        }   else {
                                                senha_caixa(senha_temp);
                                            }
                                    }   else if (temp == 1){
                                            senha_temp = PopMin(heap2);
                                            if (senha_temp == -1){
                                                printf("\n\n\n\tFila vazia!");
                                            }   else
                                                    senha_caixa(senha_temp);
                                        } else
                                            printf("\n\tDigito inválido!");
                                            //temp = PopMin(heap);
                                            //printf("Próxima Senha %d", PopMin(heap));
                                }
                        }
                    } else {
                        if(status_fila(heap) == 1){
                            senha_temp = PopMin(heap);
                            if (senha_temp == -1)
                                printf("\n\n\n\tFila vazia!");
                            else
                                senha_caixa(senha_temp);
                        } else {
                            senha_temp = PopMin(heap2);
                            if (senha_temp == -1)
                                printf("\n\n\n\tFila vazia!");
                            else
                                senha_caixa(senha_temp);
                        }
                    }
                break;
            case 4:
                if (((status_fila(heap) == 1) || (status_fila(heap2) == 1)) && (num_caixas() == 1)){
                    printf("\n\n\tAinda há pessoas para atender!");
                    break;
                } else {
                    fechar_caixa();
                }
                break;
            case 5:
                caixa_livre();
                break;
            default:
                printf("\n\nValor inválido");
                break;
        }
    }
    return 0;
}

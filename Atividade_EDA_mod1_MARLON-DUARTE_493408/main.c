#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_cliente.h"
#include "id_red_black.h"
#include "itens_AVL.h"

/**A minha ideia era de criar duas arvores com IDs de lista de pedidos e clientes.
Para os clientes eu escolhi a árvore vermelho e preto pelo fato de ser boa para inserções
e como a loja virtual é nova, imagino que haveria muitos cadastros novos de clientes pois estes
passariam a utilizar os serviços da loja online. Para os pedidos, eu escolhi a estrutura AVL por
ser muito boa em pesquisas, imaginando que tenhamos muitos pedidos na loja, e cada pedido haja muitos
itens. Porém, não consegui fazer a ligação entre as árvores e também não encontrei nenhum material
na internet que me ajudasse a fazer essa ligação, exceto alguns mais avançados que usavam recursos
cujos quais ainda não estudamos.
*/

int main(){
    int opc=1,opc1,efeito=10, num_clientes=0;
    cadastro clientela[10];
    Tno *arvore = NULL;
    Tnode *arv = NULL;
    do {
        //imprimir o titulo do menu
        for (int i=0; i<efeito;i++)
            printf("+");
        printf("Menu inicial/n");
        for (int i=0; i<efeito;i++)
            printf("+");
        printf("\n\t0 - Sair do sistema");
        printf("\n\t1 - Cadastrar cliente");
        printf("\n\t2 - Vender");
        printf("\n\t3 - Consultar Clientes");
        printf("\n\t4 - Excluir Cliente");
        printf("\n");

        scanf("%i", &opc);
        fflush(stdin);
        switch (opc){

            case 0:
                continue;
            case 1:
                clientela[num_clientes]= cadastro_cliente();
                system("clear");
                printf("\nID %i do cliente %s\n", clientela[num_clientes].id, clientela[num_clientes].nome);
                arvore = inserir(arvore, clientela[num_clientes].id);
                printf("\n");
    			imprime(arvore);
                num_clientes++;
                break;
            case 2:
                opc1=1;
                system("clear");
                imprime_avl(arv);
                do {
                    for (int i=0; i<efeito;i++)
                        printf("+");
                    printf("Itens disponiveis/n");
                    for (int i=0; i<efeito;i++)
                        printf("+");
                    printf("\n\t\tCod.: 10 - Arroz\n");
                    printf("\n\t\tCod.: 12 - Feijão\n");
                    printf("\n\t\tCod.: 13 - Cuscuz\n");
                    printf("\n\t\tCod.: 15 - Açucar\n");
                    printf("\n\t\tCod.: 18 - Sal\n");
                    printf("\n\t\tCod.: 20 - Tomate\n");
                    printf("\n\t\tCod.: 22 - Cebola\n");
                    printf("\n\t\tCod.: 0 - FINALIZAR!\n");
                    scanf("%d", &opc1);
                        if (opc1 != 0){
                            inserir_avl(arv, opc1);
                        }
                }while (opc1 != 0);
                    printf("\n\t\t");
                    imprime_avl(arv);
                    printf("\n\t\t");
                break;
            case 3:
                system("clear");
                    for (int i=0; i<efeito;i++)
                        printf("+");
                    printf("Clientes Cadastrados/n");
                    for (int i=0; i<efeito;i++)
                        printf("+");
                    for (int i=0;i<num_clientes;i++){
                        printf("\n\tNome: %s \n\tCPF: %s  \n\tID: %d \n\n\n", clientela[i].nome, clientela[i].cpf, clientela[i].id);
                    }
                break;
            case 4:
                printf("\n\tDigite o ID do cliente:");
                scanf("%d", &opc1);

                break;
            default:
                printf("Digito errado! Tente Novamente");
        }
    } while (opc != 0);

    /*for(int i = 0;i<num_clientes;i++){
        printf("\t Nome: %s \n", clientela[i].nome);
        printf("\t CPF: %s \n", clientela[i].cpf);
        printf("\t Endereço: %s \n", clientela[i].end);
        printf("\t Cartao: %d \n", clientela[i].cartao_credito);
    }*/
    return 0;
}


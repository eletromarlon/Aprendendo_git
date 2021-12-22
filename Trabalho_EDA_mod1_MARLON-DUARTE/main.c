#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastro_cliente.h"


/*typedef struct s{
    char nome[30];
    char cpf[12];
    char end[50];
    int cartao_credito;
}cadastro;


cadastro cadastro_cliente(){
    char cpf[12];
    int icpf[12];
    int i,somador=0,digito1,result1,result2,digito2,valor;

    cadastro cliente;

    printf("\tDigite o nome completo:\n");
    scanf("%s", cliente.nome);
    fflush(stdin);
    printf("\tDigite o endereco:\n");
    scanf("%s", cliente.end);
    fflush(stdin);
    printf("\tDigite o cartao de credito (apenas digitos:\n");
    scanf("%d", &cliente.cartao_credito);
    fflush(stdin);

    printf("Digite o CPF(Apenas numeros): ");
    scanf(" %s",cpf);


        for(i=0;i<11;i++){
            icpf[i]=cpf[i]-48;
        }

        for(i=0;i<9;i++){
            somador+=icpf[i]*(10-i);
        }

            result1=somador%11;

        if((result1==0) || (result1==1)){
            digito1=0;
        }else{
            digito1 = 11-result1;
        }

            somador=0;

        for(i=0;i<10;i++){
            somador+=icpf[i]*(11-i);
        }

            valor=(somador/11)*11;
            result2=somador-valor;

        if( (result2==0) || (result2==1) ){
            digito2=0;
        }else{
            digito2=11-result2;
        }

        if((digito1==icpf[9]) && (digito2==icpf[10])){
            printf("\nCPF VALIDO.\n");
        }else{
            printf("CPF nao e valido.\n");
        }

        strcpy(cliente.cpf, cpf);

    return cliente;
}
*/

int main(){
    int opc=1, efeito=10, num_clientes=0;
    cadastro clientela[10];

    do {
        //imprimir o titulo do menu
        for (int i=0; i<efeito;i++)
            printf("+");
        printf("Menu inicial/n");
        for (int i=0; i<efeito;i++)
            printf("+");
        printf("\n\t0 - Sair do sistema");
        printf("\n\t1 - Cadastrar cliente");
        printf("\n\t2 - Consultar lista de pedidos");
        printf("\n\t3 - Editar lista de pedidos");
        printf("\n\t4 - Cadastrar cliente");
        printf("\n");

        scanf("%i", &opc);

        if (opc == 1){
            clientela[num_clientes]= cadastro_cliente();
            num_clientes++;
        }

    } while (opc != 0);

    for(int i = 0;i<num_clientes;i++){
        printf("\t Nome: %s \n", clientela[i].nome);
        printf("\t CPF: %s \n", clientela[i].cpf);
        printf("\t Endereço: %s \n", clientela[i].end);
        printf("\t Cartao: %d \n", clientela[i].cartao_credito);
    }
    return 0;
}

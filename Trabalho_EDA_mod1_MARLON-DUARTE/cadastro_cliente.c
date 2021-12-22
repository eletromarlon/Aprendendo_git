#include <stdlib.h>
#include "cadastro_cliente.h"

cadastro cadastro_cliente(){
    char cpf[12];
    int icpf[12];
    int i,somador=0,digito1,result1,result2,digito2,valor, teste = 0;

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

        printf("\nDigite o CPF(Apenas numeros): ");
        scanf(" %s", cpf);

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
                teste++;
            }else{
                printf("CPF nao e valido.\n");
            }
            printf("\nCPF digitado %s", cpf);

        strcpy(cliente.cpf, cpf);
        printf("\n\n\n\t %s", cliente.cpf);

    return cliente;
}

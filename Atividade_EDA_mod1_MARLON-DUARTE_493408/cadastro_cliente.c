#include <stdlib.h>
#include "cadastro_cliente.h"

cadastro cadastro_cliente(){
    char cpf[12];
    int teste = 0;

    cadastro cliente;

    printf("\tDigite o nome completo:\n\t");
    scanf(" %s", cliente.nome);
    fflush(stdin);
    printf("\tDigite o endereco:\n\t");
    scanf(" %s", cliente.end);
    fflush(stdin);
    printf("\tDigite o cartao de credito (apenas digitos:\n\t");
    scanf("%d", &cliente.cartao_credito);
    fflush(stdin);

    do{
        printf("\nDigite o CPF(Apenas numeros): ");
        scanf(" %s", cpf);
        teste = verifica_cpf(cpf);
        fflush(stdin);

        printf("\nCPF digitado %s", cpf);

        fflush(stdin);
        }while (teste == 0);

        cliente.id = atoi(cpf);
        cliente.id = cliente.id/100000;
            if (cliente.id < 0)
                cliente.id = cliente.id * (-1);
        strcpy(cliente.cpf, cpf);
        printf("\n\n\n\t Cliente ID %i\n", cliente.id);

    return cliente;
}

int verifica_cpf(char *cpf){
    int icpf[12];
    int i,somador=0,digito1,result1,result2,digito2,valor;
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
        return 1;
    }else{
        printf("CPF nao e valido.\n");
        return 0;
    }
}

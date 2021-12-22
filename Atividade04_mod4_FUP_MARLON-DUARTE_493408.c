#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dominio 11  //Para o dominio @alu.ufc.br que contém 11 caracteres.
                    //Também poderia eu preencher um outro vetor com o dominio e
                    //contar os caracteres com strlen.
#define conta "@alu.ufc.br" //O domínio para comparação pode ser alterado sem mexer no código, alterando também "dominio".

int contaPalavras(char texto[]){
    int cont=0, numCaract;

    numCaract = strlen(texto);

    for (int i = 0;i <= (numCaract+1);i++){     //poderia utilizar o /n como um complemento na contagem das palavras
        if (texto[i] == 32){                    //mas a entrada da string foi limitada ao [^\n]
            cont++;                             //Assim, tive que adicionar +1 na saída.
            if ((texto[i+1] == 32) || (texto[i+1] == 0)){
                cont--;
            }
        }
    }

    return cont+1;
}

int verificaEmail(char texto[]){
    int totalCaracter, testaDominio;
    char testaElementos, email[dominio];

    totalCaracter = strlen(texto);
    testaDominio = totalCaracter - dominio;

    for (int i = 0;i < totalCaracter; i++){
        testaElementos = texto[i];

        //Nessa função poderia ser usado dois "for" para separar os vetores.
        //Ou poderia ser usado a função strrev e comparar com o inverso do dominio.
        //Optei por fazer desta forma porque fica mais "manual" e propõe um raciocinio diferente.

        if ((testaElementos < 97) || (testaElementos > 122)){
            if ((testaElementos < 64) || (testaElementos > 90)){
                if ((testaElementos < 48) || (testaElementos > 57)){
                    if (testaElementos != 46) //Para ser mais realista ignoro os pontos pois email pode ter ponto.
                    return 0;
                }
            }
        }
    }

    for (int i=0;i<testaDominio;i++){
			if (texto[i]==64) //Esse "for" elimina e-mails com 2 @ já que permiti char tipo @ na entrada.
				return 0;
		}

    for (int i = 0;i<dominio;i++){
        email[i] = texto[testaDominio+i];//esse "for" preenche um novo vetor para comparação com a constante "conta".
    }
    if (strcmp(conta, email) == 0)
        return 1;
    else
        return 0;
}

int main(){
    char *palavra, opcao;   //O menu esta como "char" para evitar erro quando o usuário digitar um tipo desse.
    int aloca;


    do {
        printf("\t-----------------MENU DE OPCOES------------------- \n \n");
        printf("\t1 - Conta palavras;------------------------------- \n");
        printf("\t2 - Validação de e-mail;-------------------------- \n");
        printf("\t3 - Sair------------------------------------------ \n\t");
        scanf(" %c", &opcao);

            switch (opcao){

                case '1':
                    printf("\n\tQuantos caracteres irá precisar?\n\t");
                    scanf("%d", &aloca);

                    palavra =(char*) malloc (aloca * sizeof(char));
                        if (palavra == NULL){
                            printf("\n\tErro inesperado! Tente novamente\n");
                        }   else {
                                printf("\n\tTudo Certo!\n");
                            }
                    printf("\n\tDigite a(s) palavra(s) da frase! \n\t");
                    scanf(" %[^\n]", palavra); //como estou limitando a cadeia ao enter(\n), vou somar +1 no contaPalavras.
                    printf("\n\tO número de palavras digitadas é: %d\n\n", contaPalavras(palavra));

                    free (palavra);

                break;
                case '2': //Criei alocação dinâmica para esse caso também, mesmo achando que não faz sentido.
                    printf("\n\tQuantos caracteres irá precisar?\n\t");
                    scanf("%d", &aloca);

                    palavra =(char*) malloc (aloca * sizeof(char));
                        if (palavra == NULL){
                            printf("\n\tErro inesperado! Tente novamente\n");
                        }   else {
                                printf("\n\tTudo Certo!\n");
                            }
                    printf("\n\tDigite o e-mail para verificar se pertence ao dominio %s\n\t", conta);
                    scanf(" %[^\n]", palavra);
                    if (verificaEmail(palavra) == 1)
                        printf("\n\t\t\tEmail válido!\n\n");
                    else
                        printf("\n\t\t\tEmail inválido!\n\n");

                    free (palavra);

                break;

                case '3':
                    printf("\t--------------------Tchau!!!---------------------- \n");
                break;
                default:
                    printf("\n\t\t\tOpção inválida! \n\n"); //caso seja digitado um caracter específico da lingua portuguesa ('ç')
                }                                           //haverá uma entrada fantasma do menu pois estes pertencem a tabela
    }while (opcao != '3');                                  //tabela ASCII "estendida" e ainda não fomos apresentados :)
        printf("\t----------Código encerrado pelo usuário!---------- \n");

    return 0;
}

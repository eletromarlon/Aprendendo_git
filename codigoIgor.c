#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

char *strrev(char *str) {
       char *p1, *p2;

       if (! str || ! *str)
              return str;

       for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
              *p1 ^= *p2;
              *p2 ^= *p1;
              *p1 ^= *p2;
              }
  return str;
}

int contaPalavras(char texto[]){
	int numPalavras = 0, i;
	int caracteres;
	caracteres = strlen(texto);
	for( i=0 ; i < caracteres ; i++ ){
		if(texto[i] == ' '){
			numPalavras++;
		}
	} return numPalavras+1;
}

int verificaEmail(char texto[]){
	int i, contumValido = 1, contdoisValido, qntComp;
	char instEmail[] = {("rb.cfu.ula@")}, *strVar;
	for( i=0 ; texto[i] != '@' ; i++ ){
		if(((texto[i]>=32)&&(texto[i]<=47))||((texto[i]>=58)&&(texto[i]<=64))||((texto[i]>=91)&&(texto[i]<=96))||((texto[i]>=123)&&(texto[i]<=126))){
		contumValido = 0;	}}

	strVar = strrev(texto);
	qntComp = strncmp(strVar,instEmail, 11);

	if(qntComp == 0){
		contdoisValido = 1;
	} else { contdoisValido = 0; }
	if(contumValido && contdoisValido){
		return 1;
	} else {
	return 0;}
		}

int main(){
setlocale(LC_ALL, "portuguese");
int tam, tamanho;
char *strPalavra, *strEmail;
float n;
do{
printf("________________\nMENU DE OPÇõES\n1 - Conta palavras\n2 - Validação de e-mail\n3 - Sair\nDigite a opção: ");
scanf("%f", &n);
	if(((n<1)||(n>3)) || ((n>1)&&(n<2)) || ((n>2)&&(n<3))){
		printf("\nOBS: Opção inválida, escolha uma das opções do menu.\n");
	}

	if(n == 1){
		printf("De quantos caracteres você precisa? ");
		scanf("%d", &tam);
		strPalavra = (char*) malloc(tam * sizeof(char));
		printf("Digite as palavras\n");
		scanf(" %[^\n]", strPalavra);
		printf("Foi encontrado %d palavras\n", contaPalavras(strPalavra));
	}

	if(n == 2){
		printf("De quantos caracteres você precisa? ");
		scanf("%d", &tamanho);
		strEmail = (char*) malloc(tamanho * sizeof(char));
		printf("Digite o email para validação\n");
		scanf(" %[^\n]", strEmail);
			if(verificaEmail(strEmail) == 1){
				printf("Email válido!\n");
			} else { printf("\nEmail inválido!\n");
			}
		}


}while(n!=3);


return 0;
}

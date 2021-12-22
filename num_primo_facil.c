#include<stdio.h>
 
void testa_primo(int num) {
	int resultado = 0;
 
	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			resultado++;
		break;
		}
	}
 
	if (num > 1)
		if (resultado == 0)
			printf("%d primo\n", num);
}

int main (){
	int valor;
	printf("Digite o número de primos desejado ");
	scanf("%d", &valor);
	
	for (int i=1;i<=valor;i++){
		testa_primo(i);
	}
}


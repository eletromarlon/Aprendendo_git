#include <stdio.h>
#include <stdlib.h>


float fat( int n ){

	if(n==1)
		return 1;
	else
		return n * fat(n-1);

}

float soma( int p ){

	if(p==1)
		return 1;
	else
		return (1/fat(p)) + soma(p-1);
}

int main(){
	int n;
	float o;
	printf("digite um numero inteiro (n) para calcular o somatorio de 1/n! numeros\n");
	scanf("%d", &n);
	o = soma(n);
	printf("%f", o);

	return 0;
}

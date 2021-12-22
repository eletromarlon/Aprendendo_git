#include<stdio.h>
int main(){
	float x, y, z;

	printf("Informe os lados de um triangulo\n ");
	printf("Informe o valor de x: ");
	scanf("%f", &x);
	printf("Informe o valor de y: ");
	scanf("%f", &y);
	printf("Informe o valor de z: ");
	scanf("%f", &z);

	if ( (x<=0) || (y<=0) || (z<=0) ){
		printf("informacoes invalidas");
	}
	else{
		//lados positivos e nao nulos
		if( (x<y+z) && (y<x+z) && (z<x+y) ){
			// temos lados de triangulos
			if( x==y && x==z){
				printf("Triangulo equilatero");
			}
			else{
				if( x!=y && x!=z && y!=z){
					printf("Triangulo escaleno");
				}
				else{
					printf("Triangulo Isosceles");
				}
			}
		}
		else{
			printf("nao eh um triangulo");
		}
	}

}

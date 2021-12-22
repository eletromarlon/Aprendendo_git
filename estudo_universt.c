#include <stdio.h>
#include <malloc.h>

int main (){
	int *x, y=7;
	x=&y;
	printf("endereco de x %x dentro de x %x endereco de y %x", &x, x, &y);
	
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buffer [1000], *palavra;

    printf("Digite o e-mail! \n");
    scanf(" %[^\n]", buffer);

    palavra = (char*) malloc (sizeof(char) * strlen(buffer));


    free(buffer);

    printf("E %d \n", palavra);

	return 0;
}

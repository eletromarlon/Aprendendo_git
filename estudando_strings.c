#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void){
    char s1[80], s2[80];
    fgets(s1, 80, stdin);
    fgets(s2, 80, stdin);

    printf("comprimentos: %d %d \n", strlen(s1), strlen(s2));
    if (!strcmp(s1, s2))
        printf("As strings são iguais \n");
    strcat(s1, s2);
    printf("%s \n", s1);

    strcpy(s1, "isso é um teste \n");
    printf("%s %s", s1, s2);
    if (strchr("alo", 'o'))
        printf("o está em alo \n");
    if (strstr("ola aqui", "ola"))
        printf("Olá encontrado");
}

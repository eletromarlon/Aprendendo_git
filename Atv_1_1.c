#include <stdio.h>

int main (){
    int a, b, c;
    printf("Digite 2 valores!\n");
    scanf("%d", &a);
    scanf("%d", &b);

    if (a==b){
        c = (a + b);
        printf ("A soma resultou em %d", c);
        }
        else {
            c = (a*b);
            printf("A multiplicação resultou em %d", c);
        }
}

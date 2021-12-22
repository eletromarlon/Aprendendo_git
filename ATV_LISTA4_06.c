#include <stdio.h>

int main () {
    int num1;
    printf("Digite um número \n");
    scanf("%d", &num1);
    //printf("Digite a 2ª nota \n");
    //scanf("%f", &nota2);
    printf("------------Tabuada de %d -------------- \n", num1);
    printf("%d x 1 = %d ---------------- %d x 6 = %d \n", num1, num1*1, num1,  num1*6);
    printf("%d x 2 = %d ---------------- %d x 7 = %d \n", num1, num1*2, num1,  num1*7);
    printf("%d x 3 = %d ---------------- %d x 8 = %d \n", num1, num1*3, num1,  num1*8);
    printf("%d x 4 = %d ---------------- %d x 9 = %d \n", num1, num1*4, num1,  num1*9);
    printf("%d x 5 = %d ---------------- %d x 10= %d \n", num1, num1*5, num1,  num1*10);




    return 0;
}

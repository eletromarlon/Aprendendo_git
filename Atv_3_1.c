#include <stdio.h>
int main (){
    int x,y,z,ordem;
    printf("Digite 3 valores!\n");
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    printf("Digite a ordem que deseja colocar os números!\n");
    printf("1 => Decrescente  |||||||||  2 => Crescente.\n");

    scanf("%d", &ordem);
    switch (ordem){
        case 1:
            if ((x>y)&&(x>z)&&(y>z)){
                printf("%d %d %d", x, y, z);
            }
            if ((x>y)&&(x>z)&&(z>y)){
                printf("%d %d %d", x, z, y);
            }
            if ((y>x)&&(y>z)&&(x>z)){
                printf("%d %d %d", y, x, z);
            }
            if ((y>x)&&(y>z)&&(z>x)){
                printf("%d %d %d", y, z, x);
            }
            if ((z>x)&&(z>y)&&(x>y)){
                printf("%d %d %d", z, x, y);
            }
            if ((z>x)&&(z>y)&&(y>x)){
                printf("%d %d %d", z, y, x);
            }
            break;
        case 2:
            if ((x>y)&&(x>z)&&(y>z)){
                printf("%d %d %d", z, y, x);
            }
            if ((x>y)&&(x>z)&&(z>y)){
                printf("%d %d %d", y, z, x);
            }
            if ((y>x)&&(y>z)&&(x>z)){
                printf("%d %d %d", z, x, y);
            }
            if ((y>x)&&(y>z)&&(z>x)){
                printf("%d %d %d", x, z, y);
            }
            if ((z>x)&&(z>y)&&(x>y)){
                printf("%d %d %d", y, x, z);
            }
            if ((z>x)&&(z>y)&&(y>x)){
                printf("%d %d %d", x, y, z);
            }
            break;
    }

}

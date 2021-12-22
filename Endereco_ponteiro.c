#include <stdio.h>

int main(){
    int x=10, *y;
    y=&x;
    printf("Valor em x %i\n", x);
    printf("Valor em y %p\n", y);
    printf("Valor em y %p\n", &y);

}

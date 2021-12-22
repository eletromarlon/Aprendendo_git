#include <stdio.h>
#include <stdlib.h>

int main (){
    int x;

    struct teste {
        int y;
        struct teste *pont;
    };

    typedef struct teste Teste;

    Teste *t = (Teste*)malloc(sizeof(Teste));
    printf("Digite um valor\n");
    scanf("%d", &x);

    t->y = x;

    printf("O valor em y = %d\n", t->y);


    t->y = 10;
    //(*t)->(*pont) = &y;
    printf("O valor em y = %d\n", (*t).y);
    printf("O valor em y = %d\n", (*t).pont);


    return 0;
}

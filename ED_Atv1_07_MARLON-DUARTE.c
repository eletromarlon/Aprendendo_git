#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct idade1{
    int data;
    char nome[50];
};

struct idade2{
    int data;
    char nome[50];
};

int velhote (int velho1, int velho2){
    if (velho1<velho2){
        return 0;
        } else if (velho2<velho1){
            return 1;
            } else if (velho1==velho2){
                return 2;
                }

}

void main(){
    struct idade1 i1;
    struct idade2 i2;

    printf("Digite o nome do 1º indivíduo: \n ");
    scanf(" %[^\n]", i1.nome);
    printf("Digite a data do 1º indivíduo: \n ");
    scanf("%i", &i1.data);

    printf("Digite o nome do 2º indivíduo: \n ");
    scanf(" %[^\n]", i2.nome);
    printf("Digite a data do 2º indivíduo: \n ");
    scanf("%i", &i2.data);

    switch (velhote(i1.data, i2.data)){

    case 0: printf("O(A) mais velho(a) é %s ", i1.nome);
    break;
    case 1: printf("O(A) mais velho(a) é %s ", i2.nome);
    break;
    case 2: printf("%s tem a mesma idade que %s ", i1.nome, i2.nome);
    break;
    default : printf("Erro!");
    }

}

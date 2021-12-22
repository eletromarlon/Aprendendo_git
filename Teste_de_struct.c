#include <stdio.h>
#include <stdlib.h>

int main (){
    int x;
    struct aluno {
        char nome[50];
        int idade;
    };


    printf("\nQuantos alunos?");
    scanf("%d", &x);
    struct aluno Aluno[x];

    for (int i=0;i<x;i++){
        printf("\nDigite o nome do aluno:");
        scanf(" %[^\n]s", Aluno[i].nome);
        printf("\nDigite a idade do aluno:");
        scanf(" %d", &Aluno[i].idade);
    }
    for (int i=0;i<x;i++){
        printf("\nValor em nome %s %d", Aluno[i].nome, Aluno[i].idade );
    }
}

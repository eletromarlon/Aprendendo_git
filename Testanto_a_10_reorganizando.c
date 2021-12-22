#include <stdio.h>
#include <stdlib.h>

/*Variáveis utilizadas:

    novo = valor a ser inserido dentro do vetor;
    Vetor = Vetor trabalhado;
    local = Indice a ser alterado conforme valor de x;
    x = Guarda o valor a ser inserido no vetor;
    tam = tamanho do vetor, (algumas vezes usada como indice do vetor);
    tam ... Como o vetor começa em zero, "tam=y" pode ser usado como valor de indice;
    y = Tamanho inicial do vetor;

*/

int novo = 14;

void organizaV(int *vetor, int local, int tam){ //Função responsável por reorganizar os elementos
    int i=tam;                                  //Fazendo por decremento, não precisei criar outra variável
    for(i;i>local;i--){
        vetor[i]=vetor[i-1];
    }
}

int inserir(int *vetor, int tam, int x){ //Função responsável por alterar o vetor e inserir o novo valor

    printf("Valor em x = %i\n", x);
    printf("\n\n");

    vetor = (int *)realloc (vetor, (tam+1)*sizeof(int));

        if (!vetor) {
            printf ("\nERRO!!\n");
            exit (1);
        }

        for(int i=0;i<(tam+1);i++){
            if (x<vetor[i]){
                organizaV(vetor, i, (tam));
                vetor [i]=x;
                return 0;
            } else if (x>=vetor[tam-1]) {
                    vetor[tam]=x;
                    return 0;
                }
        }

}

int main(){
    int *vetor, y=5;

    vetor = malloc (y*sizeof(int));

    if (!vetor){                        //Condicional para erro de memória
        printf (" Erro de memória!! ");
        exit (1);
        }

        for (int i=0;i<y;i++){
            vetor[i] = y*(i+2);
        }

        for(int i=0;i<(y);i++){
            printf("Valor anterior no indice %i = %i\n", i, vetor[i]);
        }

    printf("\n\n");

    inserir(vetor, y, novo);            //chama a função que altera o vetor e insere o novo elemento

        for(int i=0;i<(y+1);i++){
            printf("Valor posterior no indice %i = %i\n", i, vetor[i]);
        }

    free (vetor);

}

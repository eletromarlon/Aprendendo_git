#include <stdio.h>
#include <stdlib.h>
#include "repositorios.h"


Item *ptr_item;
int k=0;

/**Função de criação de repositório para inserçaõ de itens!
Apresenta complexidade também constante, O(1), pois se destina a, somente,
reservar espaço de alocação no ponteiro ptr_item, o qual estará sendo
utilizado como um vetor de índice n, pois a cada nova inserção este será
realocado.
*/
void create_repositorio (){
    ptr_item = (Item*) realloc(ptr_item, sizeof(Item));
}

/**Função de retorno de status de repositorio, retorna o tamanho do mesmo!
Apresenta complexidade constante, O(1), deverá unicamente retornar ao usuário
o tamanho do vetor, ou seja, o número de itens presente no repositório que
o usuário está preenchendo.
*/
int tamanho(){
    return k++;
}

/**Função que organiza os dados dentro do vetor!
Apresenta complexidade quadrática, O(n²), pegando pelo melhor caso, esta função executa
n operações, onde n representa apenas o número de elementos do vetor. Já, se analisarmos
o pior caso, serão feitas n² operações. Dessa forma, a função não seria recomendada para
programas que necessitem de muita velocidade e que operem com um número considerável de
dados.
*/
void organizador(){
    ptr_item = (Item*) realloc(ptr_item, (k+1)*sizeof(Item));

    Item temp;

    for (int i=0;i<=k;i++){
        for (int j=i;j<=k;j++){
            if (ptr_item[i].codigo > ptr_item[j].codigo){
                temp = ptr_item[i];
                ptr_item[i] = ptr_item[j];
                ptr_item[j] = temp;
            }
        }
    }
}

/**Função responśvel por adicionar valores no vetor!
Apresenta complexidade também quadrática, O(n²), pois para finalização do algoritmo
desta função, será necessário passar pela função "organizador", a qual tem este nível
de complexidade. Se analisado a função, desprezando o acesso a outra funçaõ, esta teria
complexidade constante, pois se obrigaria apenas de adicionar novos valores em um vetor.
*/
void add(int codigo, char * valor){
    ptr_item = (Item*) realloc(ptr_item, (k+1)*sizeof(Item));

    ptr_item[k].codigo = codigo;
    ptr_item[k].valor = valor;

        organizador();

    printf("\nItem inserido!\n");
    tamanho();
}

/**Função de busca de valores dentro do vetor e retorna a posição!
Apresenta complexidade logarítimica, O(log n(base binária)), ou seja, esta função
realiza sua tarefa quebrando-a pela metade, o que reduz bastante o tempo de realiza
ção da mesma. A depender da constante a se comparar, uma função logarítmica pode até
ser mais eficiente. Como os testes que realizei são com pequenas quantidade de dados,
a diferença não pôde ser notada.
*/
int find_valor(char * valor){

    for (int i=0; i<=k;i++){
        if (valor == ptr_item[i].valor){
            return ptr_item[i].codigo;
        }
    }
    return -1;
}

/**Função de busca de códigos dentro do vetor e que retorna a posição!
Apresenta complexidade logarítimica, O(log n(base binária)), ou seja, esta função
realiza sua tarefa quebrando-a pela metade, da mesma forma como a anterior. A única
diferença entre as duas é o tipo de parâmetro repassado na chamada.
*/
char * find_codigo(int cod){
    int esq = 0, dir=k;

    while (esq <= dir){
        int meio = (esq+dir) / 2;

        if (ptr_item[meio].codigo == cod){
            return ptr_item[meio].valor;
        } else if (ptr_item[meio].codigo > cod){
            dir = meio -1;
        } else {
            esq = meio + 1;
        }
    }
    return "ERROR";
}
/**Função responsável por retirar o maior valor do repositório!
Apresenta complexidade contante, O(1), pois tem a única finalidade de retirar
o último valor do repositório e depois decrementar a variável k. Ao final deve
retornar o valor mais alto extraido do repositório.
*/
float tratar(){
    Item temp = ptr_item[k-1];
    k--;
    return -1.5;
}

/**Função responsável por imprimir os dados do vetor
Apresenta complexidade linear, O(n), pois o tempo de execução da tarefa deverá
ter relação com o tamanho do vetor, ou seja o número de itens inseridos no mesmo.
Desta forma, ela percorrerá todo o vetor para finalizar sua tarefa.
*/
void imprime_repositorio(){
    if (k>0){
        for (int i=0;i<k;i++){
            printf("\nItem %d - Codigo %i / Valor %s\n", i, ptr_item[i].codigo, ptr_item[i].valor);
        }
    } else
        printf("\nRepositorio vazio!\n");
}


/**Função de verificação do status do vetor!
Apresenta complexidade constante, O(1), pois se destina apenas a verificar
o valor dentro da variável k.
*/
int esta_cheio(){
    if (k==0)
        return 0;
    else
        return 1;
}

/**Função de verificação do status do vetor!
Apresenta complexidade constante, O(1), pois se destina apenas a verificar
o valor dentro da variável k.
*/
int esta_vazio(){
    if (esta_cheio())
        return 0;
    else
        return 1;
}

/**Função responsável por "zerar" o vetor!
Apresenta complexidade constante, O(1), pois destina-se unicamente a liberar os
espaços de memória reservados pelo ponteiro. É certo que esses dados continuaram,
de certa forma, na memória. Mas como reseta o 'K', então automaticamente, o vetor
pode ser reutilizado.
*/
void limpar_repositorio(){
    k=0;
    free(ptr_item);
}

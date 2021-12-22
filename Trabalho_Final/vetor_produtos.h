#ifndef VETOR_PRODUTOS_H_INCLUDED
#define VETOR_PRODUTOS_H_INCLUDED

/**Struct que representa um item no repositório!
Apresenta complexidade constante, ou seja, O(1). Haja vista que a única
tarefa a realizar é a reserva de espaço de memória para as variáveis e
definição de tipo pelo typedef.
*/
typedef struct item{
    int codigo;
    float valor;
}Item;

void create_repositorio ();
int tamanho();
void insertion_sort();
void selection_sort();
void bubble_sort();
void mergeSort(Item *v, int n) ;
void mergeSort_ordena(Item *v, int esq, int dir) ;
void mergeSort_intercala(Item *v, int esq, int meio, int dir) ;
void quick_sort(Item *v, int inicio, int fim);
int particiona(Item *v, int inicio, int final);
void add(int codigo, float valor, int escolha);
int find_valor(float valor);
int find_codigo(int cod);
void imprime_repositorio();
void limpar_repositorio();

#endif // VETOR_PRODUTOS_H_INCLUDED

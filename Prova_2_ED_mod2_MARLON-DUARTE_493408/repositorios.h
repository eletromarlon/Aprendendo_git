#ifndef REPOSITORIOS_H_INCLUDED
#define REPOSITORIOS_H_INCLUDED

/**Struct que representa um item no repositório!
Apresenta complexidade constante, ou seja, O(1). Haja vista que a única
tarefa a realizar é a reserva de espaço de memória para as variáveis e
definição de tipo pelo typedef.
*/
typedef struct item{
    int codigo;
    char * valor;
}Item;

void create_repositorio ();
int tamanho();
void add(int codigo, char * valor);
int find_valor(char * valor);
char * find_codigo(int cod);
float tratar();
void imprime_repositorio();
int esta_cheio();
int esta_vazio();
void limpar_repositorio();

#endif // REPOSITORIOS_H_INCLUDED

#ifndef REPOSITORIO_H_INCLUDED
#define REPOSITORIO_H_INCLUDED

/**Struct que representa um item no repositório!

typedef struct item{
    int codigo;
    char * valor;
}Item;

void create_repositorio ();
int tamanho();
void guardar_no_repositorio(int codigo, char * valor);
int find_valor(char * valor);
char * find_codigo(int cod);
float tratar();
int imprime_repositorio();
int esta_cheio();
int esta_vazio();
void limpar_repositorio();


#endif // REPOSITORIO_H_INCLUDED

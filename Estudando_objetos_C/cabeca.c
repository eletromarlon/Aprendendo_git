#include "cabeca.h"

cadastro *estudante(){
    cadastro *a1 = (cadastro*) malloc (sizeof(cadastro));

    return a1;
}

void create (char nome[20], int idade){
    estudante->nome = nome;
    estudante->idade = idade;
}


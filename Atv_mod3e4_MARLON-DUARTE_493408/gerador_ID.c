#include "gerador_ID.h"

int gerar_id (char * login){ ///Recebe uma string e gera um ID
    char novo_login[MAX_NAME], *temporaria;

    remove_espacos( novo_login, login );

    temporaria = novo_login;

    return codigo_id(temporaria);
}


char * remove_espacos( char * out, char * in ) ///Elimina espaços das strings recebidas
{
    const char * p = in;
    int i = 0;

    while( *p ){ //Procua espaços na string
        if( !isspace(*p) )
            out[i++] = *p;
        p++;
    }

    out[i] = 0;

    return out;
}

int codigo_id (char * nome){ ///Gera um código ID unico para cada string recebida
    int valor, tam;

    srand(time(NULL));
    tam = strlen(nome);
    valor = (rand() % 100) * tam;

    if (valor >= 1000){
        valor = (valor % 1000);
    }
    return valor;
}

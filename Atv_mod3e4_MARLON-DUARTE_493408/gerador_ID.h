#ifndef GERADOR_ID_H_INCLUDED
#define GERADOR_ID_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX_NAME 80

int gerar_id (char * login);
char * remove_espacos( char * out, char * in );
int codigo_id (char * nome);

#endif // GERADOR_ID_H_INCLUDED

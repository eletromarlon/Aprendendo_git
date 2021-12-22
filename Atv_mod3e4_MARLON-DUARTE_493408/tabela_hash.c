#include "tabela_hash.h"
///Cria uma nova tabela hash

int cont=0; ///Variavel de contagem

hashtable_t *ht_create() { ///Criar um tipo tabela hash
	int tam_ht = sizeof (char);

	hashtable_t *hashtable = NULL;
	int i;

	if( tam_ht < 1 ) return NULL;

	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) { ///Aloca a tabela
		return NULL;
	}

	if( ( hashtable->table = malloc( sizeof( entry_t * ) * tam_ht ) ) == NULL ) { ///Aloca ponteiros para os nós principais
		return NULL;
	}
	for( i = 0; i < tam_ht; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = tam_ht;

	return hashtable;
}

int ht_hash( hashtable_t *hashtable, char *key ) { ///Criar um hash de uma string para uma determinada tabela

	unsigned long int hashval;
	int i = 0;

	while( hashval < ULONG_MAX && i < strlen( key ) ) { //converter uma string para ponteiro
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}

entry_t *ht_newpair( char *key, char *value ) { ///Criar um par de valor para as chaves
	entry_t *newpair;

	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->value = strdup( value ) ) == NULL ) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}

void ht_set( hashtable_t *hashtable, char *key, char *value ) { ///Inserir uma par de valores strings em uma tabela hash
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	cont++;

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) { //Se existe um par, substitura a string

		free( next->value );
		next->value = strdup( value );

	} else { //criar um par caso nao exista
		newpair = ht_newpair( key, value );

		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;

		} else if ( next == NULL ) {
			last->next = newpair;

		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}

char *ht_get( hashtable_t *hashtable, char *key ) { ///Retirar valores da tabela hash
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
        pair = pair->next;
	}

	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;

	} else {
		return pair->value;
	}
}

void print_hash (hashtable_t *hashtable ){ ///Imprimir toda a tabela hash
    int bin = 0;
    entry_t *pair;

    pair = hashtable->table[ 0 ];
    printf("\n\tLista de Usuários cadastrados\n");
    for (int i=0;i<cont;i++){
        printf("\n\tUsuário %s - ID %s\t\n", pair->value, pair->key);
        pair = pair->next;
    }
}

char * busca_hash (hashtable_t *hashtable, char * key ){ ///Imprimir um valor apartir de uma chave Key
    int bin = 0;
    entry_t *pair;

    pair = hashtable->table[ 0 ];
    //printf("\n\tLista de Usuários cadastrados\n");
    for (int i=0;i<cont;i++){
        if (strcmp(pair->key, key) == 0){
            return pair->value;
        }
        //printf("\n\tUsuário %s - ID %s\t\n", pair->value, pair->key);
        pair = pair->next;
    }
    return NULL;
}

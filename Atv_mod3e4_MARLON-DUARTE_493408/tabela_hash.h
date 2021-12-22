#ifndef TABELA_HASH_H_INCLUDED
#define TABELA_HASH_H_INCLUDED
/* Read this comment first: https://gist.github.com/tonious/1377667#gistcomment-2277101
 * 2017-12-05
 *
 *  -- T.
 */

#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux.  See feature_test_macros(7) */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct entry_s {
	char *key;
	char *value;
	struct entry_s *next;
};

typedef struct entry_s entry_t;

struct hashtable_s {
	int size;
	struct entry_s **table;
};

typedef struct hashtable_s hashtable_t;

hashtable_t *ht_create() ;
int ht_hash( hashtable_t *hashtable, char *key ) ;
entry_t *ht_newpair( char *key, char *value ) ;
void ht_set( hashtable_t *hashtable, char *key, char *value ) ;
char *ht_get( hashtable_t *hashtable, char *key ) ;
void print_hash (hashtable_t *hashtable );
char * busca_hash (hashtable_t *hashtable, char * key );

#endif // TABELA_HASH_H_INCLUDED

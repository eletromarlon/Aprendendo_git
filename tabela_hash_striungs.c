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


/* Create a new hashtable. */
hashtable_t *ht_create() {
	int tam_ht = sizeof (char);
	
	hashtable_t *hashtable = NULL;
	int i;

	if( tam_ht < 1 ) return NULL;

	/* Allocate the table itself. */
	if( ( hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) {
		return NULL;
	}

	/* Allocate pointers to the head nodes. */
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * tam_ht ) ) == NULL ) {
		return NULL;
	}
	for( i = 0; i < tam_ht; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = tam_ht;

	return hashtable;	
}

/* Hash a string for a particular hash table. */
int ht_hash( hashtable_t *hashtable, char *key ) {

	unsigned long int hashval;
	int i = 0;

	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[ i ];
		i++;
	}

	return hashval % hashtable->size;
}

/* Create a key-value pair. */
entry_t *ht_newpair( char *key, char *value ) {
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

/* Insert a key-value pair into a hash table. */
void ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;

	bin = ht_hash( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	/* There's already a pair.  Let's replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {

		free( next->value );
		next->value = strdup( value );

	/* Nope, could't find it.  Time to grow a pair. */
	} else {
		newpair = ht_newpair( key, value );

		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
	
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}

/* Retrieve a key-value pair from a hash table. */
char *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;

	bin = ht_hash( hashtable, key );

	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}

	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;

	} else {
		return pair->value;
	}
	
}


int main( int argc, char **argv ) {

	int tam=10000;
	float j=1;
	hashtable_t *hashtable = ht_create( sizeof(char) );

	for (int i=0;i<tam;i++){
		
		char buffer[5], buffer2[10];
		sprintf(buffer,"%d", i);
		sprintf(buffer2,"%f", 547/j);
		
		printf("\nValor dos bufferes %s e %s\n", buffer, buffer2);
		
		ht_set( hashtable, buffer, buffer2 );
		j++;
		}
	
	for (int i=0;i<tam;i++){
		char buffer[5];
		sprintf(buffer,"%d", i);
		printf( "\n%s\n", ht_get( hashtable, buffer ) );
		printf("\ni = %d\n", i);
	}
	
	
	/**ht_set( hashtable, "key1", "inky" );
	ht_set( hashtable, "key2", "pinky" );
	ht_set( hashtable, "key3", "blinky" );
	ht_set( hashtable, "key4", "floyd" );
	ht_set( hashtable, "key5", "marlon" );
	ht_set( hashtable, "key6", "tatiane" );
	ht_set( hashtable, "key7", "thayla" );
	ht_set( hashtable, "key8", "luisa" );
	ht_set( hashtable, "key9", "toinha" );
	ht_set( hashtable, "key10", "jose" );


	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );
	printf( "%s\n", ht_get( hashtable, "key5" ) );
	printf( "%s\n", ht_get( hashtable, "key6" ) );
	printf( "%s\n", ht_get( hashtable, "key7" ) );
	printf( "%s\n", ht_get( hashtable, "key8" ) );
	printf( "%s\n", ht_get( hashtable, "key9" ) );
	printf( "%s\n", ht_get( hashtable, "key10" ) );
	*/
	


	return 0;
}

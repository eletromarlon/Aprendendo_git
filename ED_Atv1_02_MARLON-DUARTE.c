#include <stdio.h>

void main( ){
	int *a, *b, c = 8, d = 2;
	a = &c;
	b = &d;
	*a = 5;
	*a +=10;
	*b = *a;
	printf ("*a = %i\n *b = %i\n c = %i\n d = %i\n ", a, b, c, d);
	}

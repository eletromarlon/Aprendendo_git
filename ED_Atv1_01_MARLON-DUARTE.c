#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main( ) {
    int x = 10;
        printf("%i\n", x);
    int *p_x = &x;
        printf("%i\n", *p_x);
    int **p_p_x = &p_x;
        printf("%i\n", **p_p_x);
    int ***p_p_p_x = &p_p_x;
        printf("%i\n", ***p_p_p_x);
    **p_p_x += 5;
    printf("- x = %i\n - *p_x = %i\n - p_x = %i\n - **p_p_x = %i\n - p_p_x = %i\n - ***p_p_p_x = %i\n - p_p_p_x = %i\n ", x, *p_x, p_x, **p_p_x, p_p_x, ***p_p_p_x, p_p_p_x );

    x+=10;

    printf("- x = %i\n - *p_x = %i\n - p_x = %i\n - **p_p_x = %i\n - p_p_x = %i\n - ***p_p_p_x = %i\n - p_p_p_x = %i\n ", x, *p_x, p_x, **p_p_x, p_p_x, ***p_p_p_x, p_p_p_x );

    *p_x = sqrt(*p_x);

    printf("- x = %i\n - *p_x = %i\n - p_x = %i\n - **p_p_x = %i\n - p_p_x = %i\n - ***p_p_p_x = %i\n - p_p_p_x = %i\n ", x, *p_x, p_x, **p_p_x, p_p_x, ***p_p_p_x, p_p_p_x );
}


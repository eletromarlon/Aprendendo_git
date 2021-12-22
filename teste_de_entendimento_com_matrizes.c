#include <stdio.h>
#include <stdlib.h>

#define col 9
#define lin 9

void main (void){
    int matriz [lin][col], i=0, j=0, l=1;

    for (i;i<lin;i++){
        for (j; j<col;j++){
            matriz [i][j]= i + (j*5);
            printf("%d ", matriz [i][j]);
        }
        printf("\n");
        j=0;
        l++;
    }
}

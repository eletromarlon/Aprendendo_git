#include <stdio.h>
#include <stdlib.h>

double pi(int n){
    float i=1, j=3, num, total;
    float resulPosit = 0, resulNegat = 0;
    num = n;
    num = num*2;

        do {
            resulPosit = (1/i) + (resulPosit);
            i+= 4;
        } while (i<=num);

        do {
            resulNegat = -(1/j) + (resulNegat);
            j+= 4;

        } while (j<=num);

    total = 4*((resulPosit)+(resulNegat));

    return total;
}

int main(){
    int n;

    printf("\tDigite a precisão no número de Leibniz: \n\t");
    scanf("%d", &n);

    printf("\t--------------------------------------------------\n");
    printf("\t                   Total %.4lf                    \n", pi(n));
    printf("\t--------------------------------------------------\n");

    return 0;
}

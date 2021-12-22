#include <stdio.h>

int main (){
    int saque;
    int n1, n2, n3, n4, n5, n6;
    printf("Temos cédulas de: 100, 50, 20, 10, 5, 2 \n");
    printf("Digite o valor que deseja sacar sem os centavos: \n");
    scanf("%d", &saque);
    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    n5 = 0;
    n6 = 0;
    if (saque >= 100)
    {
    n1 = saque/100;
    }
    if (saque>=50)
    {
    n2 = ((saque % 100)/50);
    }   if (saque>=20)
    {
    n3 = (((saque%100)%50)/20);
    }   if (saque>=10)
    {
    n4 = ((((saque%100)%50)%20)/10);
    }   if(saque>=5)
    {
    n5 = (((((saque%100)%50)%20)%10)/5);
    }   if (saque>=2)
    {
    n6 = ((((((saque%100)%50)%20)%10)%5)/2);
    }

    printf("%d %d %d %d %d %d \n", n1, n2, n3, n4, n5, n6);
    return 0;
}

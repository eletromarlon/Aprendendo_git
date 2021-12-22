#include <stdio.h>
#include <stdlib.h>
#include "repositorios.h"

int main (){
    create_repositorio();


    add(7892,"marlon");
    add(7893,"tatiane");
    add(7894,"jessica");
    add(7895,"mateo");
    add(7896,"toinha");
    add(7897,"jose");
    add(7898,"thayla");
    add(7899, "luisa");

    imprime_repositorio();

    printf("\nBusca por marlon - item %d\n", (find_valor("marlon")));

    printf("\nBusca por thayla - item %d\n", (find_valor("thayla")));

    printf("\nBusca por neto - item %d\n", (find_valor("neto")));


    printf("\nBusca pelo codigo 7895 - item %s\n", (find_codigo(7895)));

    printf("\nBusca pelo codigo 7899 - item %s\n", (find_codigo(7899)));

    printf("\nBusca pelo codigo 7888 - item %s\n", (find_codigo(7888)));


    imprime_repositorio();

    return 0;
}

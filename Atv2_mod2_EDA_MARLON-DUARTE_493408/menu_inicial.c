#include "menu_inicial.h"

int contador=0;

void borda_menu (int valor){
    for (int i=0;i<valor;i++){
        printf("=");
    }
}
int menu_entrada (){
    int opc=1, memo1=0, memo2=0, temp_senha;
    while (opc != 0){
        borda_menu(54);
        printf("\n");
        borda_menu(20);
        printf("Menu principal");
        borda_menu(20);
        printf("\nFísica (1) ou Jurídica (2)");
        printf("\n");


        scanf("%d", &opc);

        if (opc > 0){
            memo1=opc;
            while ((memo2 < 1) || (memo2 > 6)){
                borda_menu(54);
                printf("\n");
                borda_menu(20);
                printf("Menu principal");
                borda_menu(20);
                printf("\n(1) Preferencial");
                printf("\n(2) Geral");
                printf("\n");

                scanf("%d", &memo2);
            }
        }
        if ((memo1 && memo2) > 0){
            opc=0;
        }
    }
    temp_senha = gera_senha(memo1, memo2, contador);

    contador++;
    //system("clear");
    return temp_senha;
}



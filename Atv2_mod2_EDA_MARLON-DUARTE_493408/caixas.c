#include "caixas.h"

int cx[10], cont_caixas=0; //Contador de caixas informa quais caixas estao abertos

void abrir_caixa (){
    int opc=1;
    if (cont_caixas == 0){ //os caixas são sempre abertos em sequância do 0 até o numero máximo.
        printf("\n\tCaixas abertos 0 e 1");
        cont_caixas = 2;
        getchar();
    } else{
        while (opc != 0){
            printf("\n\tO que deseja fazer?");
            printf("\n(0) Desistir");
            printf("\n(1) Abrir o próximo caixa desocupado");
            printf("\n\n");
            scanf("%d", &opc);
            if (opc > 1){
                printf("\n\n\tOpção inválida!!");
            } else if (opc == 1){
                cont_caixas++;
                printf("\n\n\t\tCaixa aberto com sucesso");
                status_caixas();
            }
        }
    }
}

int status_caixas (){
    if (cont_caixas < 1){
        printf("\n\nNenhum caixa aberto ainda!");
        return cont_caixas;
    } else {
        for (int i=0;i < cont_caixas; i++){
            printf("\n\tCaixa %d", i);
            printf("\n\t\tSenha # %d #", cx[i]);
        }
        return cont_caixas;
    }
}

int fechar_caixa () {
    if (cont_caixas <= 0){
        printf("\n\n\tVerifique se tem algum caixa aberto antes de fechar ou chamar senhas!");
        cont_caixas=0;
        return 0;
    }   else{
            cont_caixas--;
            return 1;
        }
}

int senha_caixa (int chave){
    for (int j=0;j<cont_caixas;j++){
        if (cx[j]==0){
            if(((chave < 12000) || (chave > 13000)) && (chave > 10000)){ //chave preferencial e apenas 3 caixas abertos
                if (cont_caixas <= 3){
                    cx[0] = chave;
                } else if (cont_caixas > 3){
                    for (int i=0;i<2;i++){
                        if (cx[i] == 0){
                            cx[i] = chave;
                            break;
                        }
                    }
                }
            }   else if (cont_caixas == 2){
                    if (cx[1] == 0){
                        cx[1] = chave;
                    }   else{
                            //printf("\n\n\t\tTodos os caixas ocupados!");
                            //printf("\n\n\t\tAguarde novas vagas");
                            return 0;
                        }
                }   else if (cont_caixas > 2){
                        for (int i=1;i<cont_caixas;i++){
                            if (cx[i] == 0){
                                cx[i] = chave;
                                break;
                            }
                        }
                    }
        return 1;
        }
    }
    printf("\n\n\t\tTodos os caixas ocupados!");
    printf("\n\n\t\tAguarde novas vagas");
    return -1;
}

void senha_caixa_2(int chave){
    cx[0] = chave;
}

void caixa_livre (){
    int opc;

    if (status_caixas() > 0){
        printf("\n\tQual caixa deseja liberar?\n");
        scanf("%d", &opc);
        cx[opc]=0;
    }
}

int caixa_vago (){
    for (int i = 0;i<cont_caixas;i++){
        if (cx[i] == 0)
            return 1;
    }
    return 0;
}

int num_caixas(){
    return cont_caixas;
}



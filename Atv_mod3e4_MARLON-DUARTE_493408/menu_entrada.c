#include "menu_entrada.h"
#include "grafo_comunidades.h"

int musica, politica, ciencia, tecnologia, cultura, counter=0, contador=0;

typedef struct Vet{
    int identificador;
    char *nome;
}vet;

vet *vetor, *repositorio; ///Ajuste com "repositorio" por conta de um erro

void entrada(){
    int opc = 1, x, y ;

    hashtable_t *hashtable = ht_create( sizeof(char) ); ///Ciando uma tabela hash

    //create_repositorio(); ///Criando um banco de dados para nomes e IDs

    ListaDinamica Grafo;    // Criando uma Lista Dinamica com o Nome GRAFO
    CriaLD(&Grafo);         // Setando Quantidade e ponteiros para NULL

    ///====================== Geração e armazenamento dos IDs das áreas correlatas =========================
    //==========================Strings aleatórias para evitar Repetição de IDs=============================

    musica = gerar_id("cinemaParadiso");
        InserirVertice(&Grafo, musica);
    politica = gerar_id("politica");
        InserirVertice(&Grafo, politica);
    ciencia = gerar_id("charlesDarwin");
        InserirVertice(&Grafo, ciencia);
    tecnologia = gerar_id("tecnologia");
        InserirVertice(&Grafo, tecnologia);
    cultura = gerar_id("cultura");
        InserirVertice(&Grafo, cultura);
    //ImprimeGrafoCompleto(&Grafo);

    ///======================================================================================================

    contorno();

    while (opc != 0){
        char nome[20], temp[5];
        int cont=0;

        printf("\n- 0 - Sair: ");
        printf("\n- 1 - Cadastrar usuário: ");
        printf("\n- 2 - Cadastrar comunidade: ");
        printf("\n- 3 - Ver usuários: ");
        printf("\n- 4 - Ver comunidades: ");
        printf("\n- 5 - Usuários e áres de interesse: ");
        printf("\n- 6 - Encontrar usuário pelo ID: ");
        printf("\n- 7 - IDs dos assuntos: ");
        printf("\n- 8 - Inserir usuário na comunidade: ");
        printf("\n- 9 - Imprimir esquema dos grafos: ");

        printf("\n");

        contorno();
        printf("Opção: ");
        scanf(" %d", &opc);
        getchar();


        switch (opc){
            case 0:
                return;
                break;
            case 1: ///Cadastrar usuários
                //*nome = NULL; *temp = NULL; x=0; y=0;

                system("clear");
                //system("cls"); //Para windows
                y = 1, cont=0;
                contorno();
                printf("\nDigite o nome para usuário(exemplo: marlongduarte):\n");
                scanf("%[^\n]", nome);
                    getchar(); //limpar o buffer
                printf("\nBem vindo %s! ! !\n", nome);
                    x = gerar_id(nome); ///Gerar um ID unico

                printf("\n\tATENÇÃO ! ! ! Seu ID é %d\n\n", x);

                    sprintf(temp,"%d", x); //Converter um inteiro para strings pois a Tabela recebe dois strings

                ht_set(hashtable, temp, nome); ///Guardando na tabela hash

                InserirVertice(&Grafo, x); ///Criando um vertice para o usuário

                while (y != 0){
                    y = opcoes_correlatas(cont); ///Chamada a um novo menu
                    if (y > 0){
                        guarda_assunto(y, x); ///Assunto do usuário
                        if (VerificaAresta(&Grafo, y, x) <= -1) //Verifica algum erro no armazenamento
                            printf("\nERROR\n");
                    }
                    if (y == -10){
                        guarda_assunto(musica, x); ///Assunto do usuário
                        guarda_assunto(politica, x);
                        guarda_assunto(ciencia, x);
                        guarda_assunto(tecnologia, x);
                        guarda_assunto(cultura, x);
                        if ((VerificaAresta(&Grafo, musica, x) <= -1) || (VerificaAresta(&Grafo, politica, x) <= -1) || (VerificaAresta(&Grafo, ciencia, x) <= -1) ||
                        (VerificaAresta(&Grafo, tecnologia, x)<=-1) || (VerificaAresta(&Grafo, cultura, x)<=-1)) //Verifica algum erro na ligação de todos
                            printf("\nERROR\n");
                        y=0;
                    }
                    cont ++;
                    if (y == -404) ///Verificação de digito errado
                        break;
                }
                /*printf("\nEntrar em alguma comunidade? (1 - Sim / 0 - Não)\n");
                scanf("%d", &y);
                getchar();

                if (y>0){
                    printf("\nLista de comunidades disponíveis:\n");
                    imprime_repositorio();
                    if (imprime_repositorio() == 1){
                        printf("\nID da comunidade que deseja se cadastrar:\n");
                        scanf("%d", &y);
                        if (VerificaAresta(&Grafo, y, x) <= -1) //Verifica algum erro no armazenamento
                        printf("\nERROR\n");
                    } else
                        printf("\nNenhuma comunidade cadastrada ! ! !\n\n");
                }*/
                break;
            case 2: ///Cadastrar comunidade

                system("clear");
                //system("cls"); //Para windows
                contorno();
                printf("\nDigite seu ID de usuário: Vide opção 3 do menu principal\n");
                scanf("%[^\n]", temp);
                getchar();

                printf("\n\nOlá %s, cadastre sua comunidade! ! !\n\n", busca_hash(hashtable, temp));

                if (busca_hash(hashtable, temp) == NULL){
                    printf("\nID desconhecido! ! !\n");
                    break;
                } else {
                    printf("\nDigite o nome da comunidade:\n");
                        scanf("%[^\n]", nome);
                    getchar(); //limpeza de teclado
                    printf("\nA comunidade ''%s'' vai ser super animada! ! !\n", nome);

                    x = gerar_id(nome); ///x ID comunidade - nome é o nome comunidade

                    guardar_no_repositorio(x, nome); ///Guardando nome da comunidade com o ID

                    y = opcoes_correlatas(-1); ///Chamada a um novo menu de opções

                        if (y == -404) ///Tratamento de erro
                            break;

                    InserirVertice(&Grafo, x); ///Criando um vertice para a comunidade
                        if (VerificaAresta(&Grafo, y, x) <= -1) //Verifica algum erro no armazenamento e
                            printf("\nERROR\n");                ///liga comunidade a assunto

                    y = atoi (temp); //Converte char para inteiro
                    if (VerificaAresta(&Grafo, x, y) <= -1)     //Verifica algum erro no armazenamento
                            printf("\nERROR\n");                ///liga comunidade ao usuário
                }
                    printf("\nComunidade cadastrada! ! !\n");
                break;
            case 3: ///Ver usuários
                system("clear");
                //system("cls"); //Para windows
                contorno();
                printf("\n\nMusica     ID = %d", musica);
                printf("\nPolitica   ID = %d", politica);
                printf("\nCiência    ID = %d", ciencia);
                printf("\nTecnologia ID = %d", tecnologia);
                printf("\nCultura    ID = %d\n", cultura);
                contorno();
                print_hash(hashtable); ///Mostra na tela os usuários e IDs da tabela hash
                contorno();
                ImprimeGrafoCompleto(&Grafo); ///Mostrar as ligações entre os IDs
                getchar();
                break;
            case 4:///Ver comunidades
                system("clear");
                //system("cls"); //Para windows
                contorno();
                printf("\nLista de comunidades cadastradas\n");
                imprime_repositorio(); ///Exibe a lista de comunidade com os seus IDs
                contorno();
                ImprimeGrafoCompleto(&Grafo); ///Mostrar as ligações entre os IDs
                contorno();
                getchar();
                break;
            case 5: ///Áreas de interesses dos usuários
                system("clear");
                //system("cls"); //Para windows
                contorno();
                print_hash(hashtable); ///Mostra na tela os usuários e IDs da tabela hash
                contorno();
                assuntos_users(); ///Mostra na tela as áreas correlatas dos usuários
                break;
            case 6:  ///Buscar usuário po ID
                system("clear");
                //system("cls"); //Para windows
                contorno();
                printf("\nDigite o ID do usuário\n");
                scanf("%[^\n]", temp);
                getchar();
                printf("\nO nome deste usuário é %s\n", busca_hash(hashtable, temp)); ///Encontra o nome de usuario pelo ID
                break;
            case 7: ///Mostrar assuntos
                system("clear");
                //system("cls"); //Para windows
                contorno();
                printf("\n\nMusica     ID = %d", musica);
                printf("\nPolitica   ID = %d", politica);
                printf("\nCiência    ID = %d", ciencia);
                printf("\nTecnologia ID = %d", tecnologia);
                printf("\nCultura    ID = %d\n", cultura);
                getchar();
                contorno();
                break;
            case 8: ///Inserir usuário na comunidade
                contorno();
                printf("\nLista de comunidades disponíveis:\n");
                    if (imprime_repositorio() == 1){
                        printf("\nID da comunidade que deseja se cadastrar:\n");
                        scanf("%d", &y);
                        printf("\nID do usuario para inserir nesta comunidade\n");
                        scanf("%d", &x);
                        if (VerificaAresta(&Grafo, y, x) <= -1) //Verifica algum erro no armazenamento
                        printf("\nERROR\n");
                    } else
                        printf("\nNenhuma comunidade cadastrada ! ! !\n\n");
                contorno();
                break;
            case 9: ///Esquema completo
                system("clear");
                //system("cls"); //Para windows
                ImprimeGrafoCompleto(&Grafo);
                imprime_repositorio();
                print_hash(hashtable);
                break;
            default:
                printf("Digite uma das opções do menu");
                break;
        }
    }
}

void contorno(){
    for (int i=0;i<barra;i++)
        printf("=");
    printf("\n");
}

int opcoes_correlatas(int cont){
    //system("clear");
    //system("cls"); //Para windows
    int opcione;
    contorno();
    if ((cont > 0))
        printf("\n- 0 - Sair: ");
    printf("\n- 1 - Músicas: ");
    printf("\n- 2 - Política: ");
    printf("\n- 3 - Ciência: ");
    printf("\n- 4 - Tecnologia: ");
    printf("\n- 5 - Cultura: ");
    if ((cont > -1) && (cont < 4))
        printf("\n- 6 - Todas: ");
    printf("\n");
    contorno();
    printf("\nQual desses assuntos é de seu interesse?\n");
    scanf("%d", &opcione);
    getchar();
    switch (opcione){
        case 0:
            printf("\nFinalizado! ! !\n");
            return 0;
            break;
        case 1:
            return musica;
            break;
        case 2:
            return politica;
            break;
        case 3:
            return ciencia;
            break;
        case 4:
            return tecnologia;
            break;
        case 5:
            return cultura;
            break;
        case 6:
            return -10;
        default:
            printf("\nEsse digito esta errado! Cadastro cancelado\n");
            return -404;
            break;
    }
}

void guarda_assunto(int ID_assunto, int ID_usuario){
    vetor = (vet*)realloc (vetor, (counter +1) * sizeof(vet));
        if (!vetor){
            printf("\n\nERRO DE MEMÓRIA\n\n");
            return;
        }
    if (ID_assunto == musica){
        vetor[counter].identificador=ID_usuario;
        vetor[counter].nome = "Musica";
    }
    if (ID_assunto == politica){
        vetor[counter].identificador=ID_usuario;
        vetor[counter].nome = "Politica";
    }
    if (ID_assunto == ciencia){
        vetor[counter].identificador=ID_usuario;
        vetor[counter].nome = "Ciencia";
    }
    if (ID_assunto == tecnologia){
        vetor[counter].identificador=ID_usuario;
        vetor[counter].nome = "Tecnologia";
    }
    if (ID_assunto == cultura){
        vetor[counter].identificador=ID_usuario;
        vetor[counter].nome = "Cultura";
    }
    counter++;
}

void assuntos_users (){
    for(int i=0;i<counter;i++){
        printf("\nUsuário ID %d - assunto %s\n", vetor[i].identificador, vetor[i].nome);
    }

}

int guardar_no_repositorio(int codigo, char * valor){ ///Repositorio mais simples que o apresentado no video
    repositorio = (vet*)realloc (repositorio, (contador +1) * sizeof(vet)); ///Criei essa maneira de armazenar mais facil que a apresentada no video
    if (!repositorio){                                                      ///Porém deixei o arquivo na pasta caso a senhora queira verificar
            printf("\n\nERRO DE MEMÓRIA\n\n");                              ///Reduz o tamanho do projeto e cumpre o mesmo papel quando
            return -404;                                                    ///Utiliza a função de impressão a baixo.
    }
    printf("\n\nValor em valor %s\n\n", valor);
    repositorio[contador].identificador = codigo;
    repositorio[contador].nome = valor;
    contador++;
    return 1;
}

int imprime_repositorio(){  ///Imprimir o repositório de titulos das comunidades para facilitar a compreensão dos IDs.
    if (contador > 0){                  ///Porém as comunidades estão armazenadas dentro dos grafos através de seus IDs
        for(int i=0;i<contador;i++){
            printf("\nComunidade %s - ID %d\n", repositorio[i].nome, repositorio[i].identificador);
        }
        return 1;
    }
    return 0;
}

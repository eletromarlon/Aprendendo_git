#include "grafo_comunidades.h"

void CriaLD(ListaDinamica *L) /// Função usada na "main"
{
    L->quantV = 0;    // Setando Quantidade de Vertices do Grafo em zero
    L->inicio = NULL; // atualizando ponteiro Inicio para NULL
}

void Free_All(ListaDinamica *L) /// Função usada na "main"
{
    ponto *AuxV, *AuxA, *InicioA; // Ponteiro inicioA é para criar um Inicio para Arestas
    while (L->inicio != NULL)    // Loop responsavel por dar free em todos os vertices do grafo
    {
        AuxV = L->inicio;       // Enquanto L->inicio é != de NULL então tem ponto para dar free
        InicioA = AuxV->prox;   // Inicio de Aresta sempre começa no AuxV->prox;
        while (InicioA != NULL) // começa aqui para dar free nas arestas
        {
            AuxA = InicioA;
            InicioA = AuxA->prox;
            free(AuxA); // free na aresta
            AuxA = NULL;
        }
        L->inicio = AuxV->baixo;
        free(AuxV); // free no vertice
        AuxV = NULL;
    }
    // \/ NÂO PRECISA FAZER ISSO PORQUE MEU GRAFO NÃO É CRIADO COM MALLOC E SIM POR TIPO
    //free(L); // dando free na estrutura grafo
    //L = NULL;
}

void ImprimeGrafoCompleto(ListaDinamica *L) /// Função usada na "main" case 3
{
    ponto *auxV = L->inicio; // Criando tipo ponto V para vertice e pontoA para aresta.
    ponto *auxA;
    printf("IDS que se conectam\n");
    while (auxV != NULL) // Vai terminar de printar o grafo quando chegar no ultimo vertice
    {
        auxA = auxV;                            // auxA precisa receber auxV para o auxA sempre printar os itens da sua linha
        printf("   %d  ------>", auxV->numero); // Printando o Vertice
        if (auxA->prox == NULL)                 // Se o proximo ponto de Vertice for NULL ele vai printar um NULL
        {
            printf("   NULL\n");
        }
        else // Se não for NULL quer dizer que tem itens para proximo de Vertice ...
        {
            auxA = auxV->prox;   // Precisa fazer isso porque senão ele vai printar o Vertice de novo ... A aresta sempre começa do V->prox; e não de V.
            while (auxA != NULL) // Imprimir todos da Lista (Aresta)
            {
                printf(" %d ->", auxA->numero);
                auxA = auxA->prox; // Percorrendo Lista na Horizontal (Printando todas as Arestas) do vertice V
            }
            printf(" NULL\n");
        }
        auxV = auxV->baixo; // Para Percorrer até o ultimo Vertice da lista
    }
}

ponto *NovoVertAresta(int value) /// Usada na função "Inserir Vertice"
{
    ponto *aux;                  // Criando variavel tipo ponto
    aux = malloc(sizeof(ponto)); // Alocando dinamicamente
    aux->numero = value;        // atribuindo o numero do Vertice para aux->numero
    aux->prox = NULL;           // Atualizando ponteiro para NULL (Arestas)
    aux->baixo = NULL;          // Atualizando ponteiro para NULL (vertices)
    return aux;                 // Retornando o ponteiro para o aux criado
}

ponto *RetornapontoAnterior(ListaDinamica *L, int v1) /// Funcao usada em "VerificaRemoveVertices"
{
    ponto *C = L->inicio;
    while (C->baixo->numero != v1)
    {
        C = C->baixo;
    }
    return C;
}

// ===================================== FUNÇOES PARA VERTICE ===============================================
int InserirVertice(ListaDinamica *L, int n) /// Função usada na "main"
{                                           // CHECKLIST DE VERIFICAÇÃO DE VERTICES                                       STATUS     RETURN
    //      * NÃO PODE TER VERTICES IGUAIS                                         OK!        (-1)
    //      * PODE TER VERTICE NEGATIVO || Resp: Sim mas n precisa validar         OK!        (--)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...
    ponto *aux;          // Criando variavel aux para percorrer o Grafo
    if (L->quantV != 0) // Se QuantV for 0 ... certamente o numero que o usuario informou não tem no grafo então não precisa validar e pode adicionar ele direto.
    {                   // Se QuantV != 0 ... então precisa validar se n tem no grafo ou não.
        int i;
        aux = L->inicio;                // Setando aux para o Ponteiro inicio do Vertice
        for (i = 0; i < L->quantV; i++) // Vai percorrer a Lista inteira para ver se acha um vertice igual o informado
        {
            if (aux->numero == n) // Se ele achar um n ja existente no grafo vai retornar -1 (ERRO)
            {
                return -1; // Retornando -1 ... validar Resposta para esse (ERRO)
            }
            aux = aux->baixo; // Atualizando o aux para baixo (vertice) para ele conseguir percorrer o grafo
        }
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÂO ...

    aux = NovoVertAresta(n);        // chamando função que cria um ponto e seta valor e atualiza ponteiros para NULL
    InserirVerticeOrdenado(L, aux); // Chamando função que insere Vertice
    return 1;                       // Se chegou até aqui é porque deu tudo CERTO !!!
}

void InserirPrimeiroVertice(ListaDinamica *L, ponto *c) // Usada na função "InserirVerticeOrdenado"
{
    L->quantV++; // Acrescentando quantidade relativo aos Vertices
    c->baixo = L->inicio;
    L->inicio = c; // Atualizando ponteiro L->inicio para o Vertice C
}

void InserirFimVertice(ListaDinamica *L, ponto *c) // Usada na função "InserirVerticeOrdenado"
{
    //OBS: NÃO VALIDEI POS=0 POIS O CODIGO INTEIRO JA ESTA FAZENDO ESSA VALIDACAO ... MAS SE FOR USAR ESSA FUNCAO COLOQUE
    int pos = L->quantV; // Como vai adicionar no fim da lista ... Só pegar a ultima posição da lista pelo QuantV
    int cont = 0;
    ponto *aux = L->inicio;   // atualizando aux para inicio da lista
    while (cont < (pos - 1)) // percorrendo a lista até o ultimo ponto
    {
        aux = aux->baixo;
        cont++;
    }
    c->baixo = aux->baixo;
    aux->baixo = c;
    L->quantV++;
}

void InserirVerticeOrdenado(ListaDinamica *L, ponto *C) /// Usada na função "Inserir Vertice"
{
    ponto *aux = L->inicio; // criando o aux pois ele vai fazer o papel de um L->fim
    if (L->quantV != 0)    // se a lista esta vazia não precisa percorrer ela
    {
        while (aux->baixo != NULL) // loop responsavel por pegar o ultimo ponto da lista vertice
        {
            aux = aux->baixo;
        }
    }

    if (L->inicio == NULL) // Se tiver vazia a lista
    {
        InserirPrimeiroVertice(L, C);
    }

    else if (C->numero < L->inicio->numero) // Só tem numero grande e o numero dado é pequeno ... insere no inicio da lista
    {
        InserirPrimeiroVertice(L, C);
    }

    else if (C->numero > aux->numero) // Se o numero que vc quer inserir é maior que todos da lista .. insere no fim.
    {
        InserirFimVertice(L, C);
    }

    else // numero está entre o inicio e fim da lista.
    {
        ponto *auxa, *auxd; // Aux_Antes e Aux_Depois para comparar
        auxa = L->inicio;
        auxd = auxa->baixo;
        while (auxd->numero < C->numero)
        {
            auxa = auxa->baixo;
            auxd = auxa->baixo;
        }
        C->baixo = auxa->baixo;
        auxa->baixo = C;
        L->quantV++;
    }
}

// ===================================== FUNÇOES PARA ARESTAS ===============================================
int VerificaAresta(ListaDinamica *L, int v1, int v2) /// Função usada na "main"
{

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...
    if (L->quantV == 0 || L->quantV == 1)
    {              // Não tem como juntar 2 pontos sem ter dois pontos (trabalho não aceita laço)
        return -4; // Saida (-4) quer dizer que tem vertices insuficientes para criar aresta
    }

    if (v1 == v2) // Não pode ter laço
    {
        return -3; // Saida (-3) quer dizer que V1 é igual a V2.
    }

    // Verificar se existe no Grafo os Vertices V1 e V2 ...
    ponto *aux = L->inicio; // Criando tipo ponto e setando para começo do Grafo
    int cont = 0;          // Inicializando uma variavel contadora = 0 ... vai ser responsavel por contar se tem os V1 e V2
    while (aux != NULL)
    {
        if (aux->numero == v1 || aux->numero == v2)
        {
            cont++; // Se cair aqui 2x é porque o V1 e V2 existe na lista se cair 1 ou nenhuma vez é pq n tem
        }
        aux = aux->baixo; // Percorrendo grafo na vertical até Aux ser NULL
    }
    if (cont != 2) // Se for igual a 2 é porque o V1^V2 existe no Grafo, se for diferente não existe.
    {
        return -2; // Saida (-2) quer dizer que não tem V1 ou V2 no Grafo ou nenhum deles.
    }

    // Verificar Se já existe essa aresta no Grafo
    aux = L->inicio;          // Setando novamente Aux para inicio do Grafo
    cont = 0;                 // Setando novamente contador = 0 para validar return
    while (aux->numero != v1) // ele vai percorrer o gravo na Vertical(vertice) até achar o v1
    {                         // Ele vai achar o v1 pois ja foi verificado que v1 e v2 pertencem ao grafo
        aux = aux->baixo;
    }
    while (aux != NULL) // Agora o aux vai percorrer o gravo na Horizontal (Arestas).
    {
        if (aux->numero == v2) // Se ele achar o v2 é porque ja tem aresta ligando os pontos v1 e v2
        {
            cont++; // Se cair aqui é porque ja tem arestas ligando, então para validar uma saida o cont recebe 1;
        }           // Se cont=0 --> Não existe aresta ligando v1 e v2 | Se cont != 0 é porque existe aresta ligando V1 e V2
        aux = aux->prox;
    }
    if (cont != 0)
    {
        return -1; // Saida (-1) quer dizer que já existe aresta ligando os pontos V1 e V2
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÂO ...

    // ~~~~~~~~~~~~~~       &*&*    PARTE QUE VAI ADICIONAR ARESTAS    &*&*         ~~~~~~~~~~~~~
    aux = L->inicio;          // setando novamente aux para inicio do Grafo
    while (aux->numero != v1) // Vai percorrer a lista até achar o Vertice V1
    {
        aux = aux->baixo;
    }
    ponto *novo;                // declarando tipo ponto para inserir no v1 a aresta v2
    novo = NovoVertAresta(v2); // Chamando função para criar nova aresta
    InserirArestaOrdenado(L, novo, aux);

    // Precisamos fazer isso 2x ... um para inserir no v1 a aresta v2 e no outro inserir no v2 a aresta v1.
    aux = L->inicio;
    while (aux->numero != v2)
    {
        aux = aux->baixo;
    }
    novo = NovoVertAresta(v1);
    InserirArestaOrdenado(L, novo, aux);
    // Chamando função para inserir ... onde novo é o elemento a ser inserido e aux é onde a lista começa
    // horizontalmente (aresta) em v1

    return 1; // Se chegou aqui porque não parou em nenhum return e conseguiu analisar e inserir com sucesso !!!
}

void InserirArestaOrdenado(ListaDinamica *L, ponto *C, ponto *V) /// Função usada em "VerificaAresta"
{                                                              // ponto C --> ponto que vc quer inserir || ponto V é o Vertice Atual, isto é, o vertice que tu quer inserir a aresta
    if (V->prox == NULL)                                       // Se não tem arestas ... Basta atualizar ponteiro prox para o ponto novo
    {
        V->prox = C;
    }

    else if (C->numero < V->prox->numero) // Se o numero que vc vai inserir é menor que o primeiro numero da aresta
    {
        C->prox = V->prox;
        V->prox = C;
    }

    else // Inserir no FIM da lista (aresta) e no  meio
    {
        ponto *auxa = V->prox; // só vai precisar disso se cair no else, mas como eu vou percorrer o V
        //vou perder referencia, então fiz uma "copia" dele aqui.

        while (V->prox != NULL) // Estou percorrendo a lista até o ultimo ponto para verificar a condição abaixo
        {
            V = V->prox;
        }

        if (C->numero > V->numero) // Se o ultimo ponto da lista é MENOR que o C ... INSERIR NO FIM da lista
        {
            V->prox = C; // Inserir FIM basta atualizar o ponteiro prox do ultimo elemento para C
        }

        else // CASO DO MEIO ... vou precisar usar o auxa (aux antes)
        {
            ponto *auxd;        // auxiliar depois
            auxd = auxa->prox; // aux depois vai receber o prox de antes ... para comparar.
            while (auxd->numero < C->numero)
            {
                auxa = auxa->prox;
                auxd = auxa->prox;
            }
            C->prox = auxa->prox;
            auxa->prox = C;
        }
    }
}

// =================================== FUNÇOES PARA TIRAR VERTICES =========================================
int VerificaRemoveVertices(ListaDinamica *L, int v1) /// Funcao usada na "main"
{                                                    // CHECKLIST DE VERIFICAÇÃO DE REMOÇÃO DE VERTICES                                 STATUS    RETURN
    //      * VERIFICAR SE V1 EXISTE NO GRAFO                                         OK!       (-1)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...
    ponto *aux = L->inicio;
    int cont = 0, i;

    for (i = 0; i < L->quantV; i++) // percorrer o grafo inteiro para achar um vertice
    {
        if (aux->numero == v1)
        {
            cont++; // se caiu aqui pq tem v1 no grafo
            break;  // para não fazer o for ir até o fim ... se achou um não precisa percorrer o resto.
        }
        aux = aux->baixo;
    }
    if (cont == 0)
    {
        return -1; // se cont for 0 não tem vertice para remover ... então retorna (-1)
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÃO ...

    // ~~~~~~~~~~~~~~       &*&*    PARTE QUE VAI REMOVER VERTICE    &*&*         ~~~~~~~~~~~~~
    if (aux->prox != NULL) // Se não for NULL é porque tem arestas ... precisa tirar uma por uma e depois exclui o V
    {
        int Aresta; // variavel responsavel por pegar as arestas do vertice e passar como parametro para a funcao Remove Arestas
        while (aux->prox != NULL)
        {
            Aresta = aux->prox->numero;
            VerificaRemoveArestas(L, v1, Aresta);
        }
    }
    if (aux->prox == NULL) // se não tiver aresta é so ligar os vertices
    {
        if (L->quantV == 1) // se tiver só 1V é só dar free e criar outro Grafo
        {
            free(aux); // dando free no aux
            aux = NULL;
            CriaLD(L); // Criando outro Grafo, isto é, setando quantV=0 | Inicio/Fim == NULL
            return 1;  // não precisa fazer mais nada então return 1
        }

        else if (L->quantV == 2) // Se tiver 2V ou tira do INICIO ou FIM
        {
            if (L->inicio->numero == v1) // Se for tirar do INICIO
            {
                L->inicio = aux->baixo;
                aux->baixo = NULL;
            }
            else // Se v1 é o Ultimo ponto
            {
                L->inicio->baixo = NULL;
            }
        }

        else if (aux->numero == L->inicio->numero) // Se o Vertice que for tirar é o primeiro da lista
        {
            L->inicio = aux->baixo;
            aux->baixo = NULL;
        }

        else // Se o Vertice tiver Entre outros Vertices ...
        {
            ponto *aux_Ant = RetornapontoAnterior(L, v1);
            aux_Ant->baixo = aux->baixo;
            aux->baixo = NULL;
        }

        free(aux);
        aux = NULL;
        L->quantV--;
        return 1;
    }
    return 1;
}

// =================================== FUNÇOES PARA TIRAR ARESTAS ===========================================
int VerificaRemoveArestas(ListaDinamica *L, int v1, int v2) /// Função usada na "main"
{                                                           // CHECKLIST DE VERIFICAÇÃO DE REMOCÃO DE ARESTAS                                 STATUS    RETURN
    //      * VERIFICAR SE V1 É IGUAL V2                                              OK!       (-3)
    //      * VERIFICAR SE V1 E V2 EXISTE NO GRAFO                                    OK!       (-2)
    //      * VERIFICAR SE V1 E V2 FAZEM CONEXÃO                                      OK!       (-1)

    // --> COMEÇA AQUI A PARTE DE VERIFICAÇÂO ...

    // verificar se v1 = v2 ... não da para tirar laço pois o grafo não permite laço
    if (v1 == v2)
    {
        return -3; // Saida (-3) quer dizer que V1 == V2 ... não da para tirar laço se não tem laço
    }

    // Verificar se existe no Grafo os Vertices V1 e V2 ...
    ponto *aux = L->inicio; // Criando tipo ponto e setando para começo do Grafo
    int cont = 0;          // Inicializando uma variavel contadora = 0 ... vai ser responsavel por contar se tem os V1 e V2
    while (aux != NULL)
    {
        if (aux->numero == v1 || aux->numero == v2)
        {
            cont++; // Se cair aqui 2x é porque o V1 e V2 existe na lista se cair 1 ou nenhuma vez é pq n tem
        }
        aux = aux->baixo; // Percorrendo grafo na vertical até Aux ser NULL
    }
    if (cont != 2) // Se for igual a 2 é porque o V1^V2 existe no Grafo, se for diferente não existe.
    {
        return -2; // Saida (-2) quer dizer que não tem V1 ou V2 no Grafo ou nenhum deles.
    }

    // Verificar Se existe essa aresta no Grafo
    aux = L->inicio;          // Setando novamente Aux para inicio do Grafo
    cont = 0;                 // Setando novamente contador = 0 para validar return
    while (aux->numero != v1) // ele vai percorrer o gravo na Vertical(vertice) até achar o v1
    {                         // Ele vai achar o v1 pois ja foi verificado que v1 e v2 pertencem ao grafo
        aux = aux->baixo;
    }
    while (aux != NULL) // Agora o aux vai percorrer o gravo na Horizontal (Arestas).
    {
        if (aux->numero == v2) // Se ele achar o v2 é porque tem aresta ligando os pontos v1 e v2
        {
            cont++; // Se cair aqui é porque tem arestas ligando, então para validar uma saida o cont recebe 1;
        }           // Se cont=0 --> Não existe aresta ligando v1 e v2 | Se cont != 0 é porque existe aresta ligando V1 e V2
        aux = aux->prox;
    }
    if (cont != 1)
    {
        return -1; // Saida (-1) quer dizer que não existe aresta ligando os pontos V1 e V2
    }
    // --> TERMINA AQUI A PARTE DE VERIFICAÇÂO ...

    // ~~~~~~~~~~~~~~       &*&*    PARTE QUE VAI REMOVER ARESTAS    &*&*         ~~~~~~~~~~~~~
    aux = L->inicio;          // setando novamente aux para Inicio do Grafo
    while (aux->numero != v1) // loop para achar o vertice 1 e passar como parametro para função RemoverAresta
    {                         // Não precisa validar com NULL pois já verifiquei que existe o vertice 1
        aux = aux->baixo;     // percorrendo para baixo pois quero descobrir o vertice
    }
    RemoveAresta(L, aux, v2); // Função que vai remover a aresta ... passando Grafo, aux que seria o vertice v1 e o numero v2 para ele tirar de v1

    // Precisamos fazer isso 2x pois voce precisa tirar v1 de v2 e v2 de v1.
    aux = L->inicio;          // setando novamente aux para inicio do grafo
    while (aux->numero != v2) // loop para achar o vertice 2
    {
        aux = aux->baixo; // percorrendo para baixo pois quero descobrir o vertice
    }
    RemoveAresta(L, aux, v1); // agora ele vai tirar o v1 do vertice 2.

    return 1; // Se chegou até aqui porque não caiu em nenhum return e a verificação/remoção foi um success!!!
}

void RemoveAresta(ListaDinamica *Lista, ponto *V, int n) /// Função usada na "VerificaRemoveArestas"
{                                                       // ponto V corresponde ao Vertice ... e n é o numero que vc quer tirar da aresta
    ponto *aux, *temp;
    aux = V; // aux recebendo o começo do vertice que foi passada como parametro

    while (aux->prox->numero != n) // vai percorrer a até achar n (precisa usar && aux != NULL) ???
    {
        aux = aux->prox;
    }
    temp = aux->prox; // para não perder referencia
    aux->prox = temp->prox;
    temp->prox = NULL;
    free(temp); // dando free no ponto temp que foi adicionado com malloc.
}

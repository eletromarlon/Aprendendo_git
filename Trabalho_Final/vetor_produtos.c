#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vetor_produtos.h"


Item *ptr_item;
int k=0;

/**Função de criação de repositório para inserçaõ de itens!
Apresenta complexidade também constante, O(1), pois se destina a, somente,
reservar espaço de alocação no ponteiro ptr_item, o qual estará sendo
utilizado como um vetor de índice n, pois a cada nova inserção este será
realocado.
*/
void create_repositorio (){
    ptr_item = (Item*) realloc(ptr_item, sizeof(Item));
}

/**Função de retorno de status de repositorio, retorna o tamanho do mesmo!
Apresenta complexidade constante, O(1), deverá unicamente retornar ao usuário
o tamanho do vetor, ou seja, o número de itens presente no repositório que
o usuário está preenchendo.
*/
int tamanho(){
    return k++;
}

/**Função que organiza os dados dentro do vetor!
O algoritmo "insertion_sort" trabalha percorrendo o vetor, no qual ele verifica cada índice
analisando se o seu valor está na posição correta. Inicia a verificação pelo primeiro valor
e compara este com todos os outros. Caso o valor de 'i' recaia no caso de ser maior, o algoritmo
entrará na condição dentro do for, onde, com a ajuda de uma variável temporária realizará a permuta
dos valores mal posicionados. A eficiêcia deste algoritmo varia conforme o estado inicial do vetor, pois
percorrerá todo o vetor para fazer as comparações, caso esteja ordenado fará uma única vez. Possui algumas
vantagens, pois pode ordenar os elemtnso a medida que se façam as inserções e não precisa ter todo o conjunto
de dados para colocar em ordem.
Apresenta complexidade quadrática, O(n²). Analisando pelo melhor caso, este algoritmo executa n
operações, onde n representa apenas o número de elementos do vetor. Já, se analisarmos o pior caso,
serão feitas n² operações. Dessa forma, a função não seria recomendada para programas que necessitem
de muita velocidade e que operem com um número considerável de dados. Ao analisar o algoritmo
implementado neste trabalho, fiz uma mudança em relação ao que apresentei na prova passada.
Pois, percebo que o primeiro for iniciava em 0 o que levava a comparar o indice 0 com o proprio
índice quando da entrada do segundo laço, o que acaba consumido um ciclo desnecessário. A partir
do material postado pelo professor pude fazer essa correção e apresentar um algoritmo mais puro,
ou mais adequado.
*/
void insertion_sort(){
    int i, j;
    Item temp;

    for (i=1;i<=k;i++){
        temp = ptr_item[i];
        for (j=i;(j>0) && (temp.valor<ptr_item[j-1].valor);j--){
            ptr_item[j] = ptr_item[j-1];
        }
        ptr_item[j] = temp;
        }

            /* Algoritmo utiliazado na Última prova.
            for (int i=0;i<=k;i++){
                for (int j=i;j<=k;j++){
                    if (ptr_item[i].valor > ptr_item[j].valor){
                        temp = ptr_item[i];
                        ptr_item[i] = ptr_item[j];
                        ptr_item[j] = temp;
                    }
                }
            }*/
}

/**Função que organiza os dados dentro do vetor!
Neste algoritmo, ao passo que os laços vão acontecendo, ele vai escolhendo o melhor elemento para
ocupar determinada posição do array, que pode ser por maior ou menor elemento a depender da aplicação
da ordenação. Possui um desempenho, na prática, ligeiramente superior ao "bubble sort". Divide o array
em duas sessões: a primeira, ordenada, ficará a esquerda do elemento analisado, e o restante dos elementos
que ainda não foram organizados ficarão à direita do elemento analisado. Tem algumas vantagens a depender
da aplicação a que se destina, por exemplo nos trabalhos com memórias que se desgastam no processor de
escrita e leitura, mas uma vantagem em particular se destaca que é a estabilidade, pois não altera a ordem
dos dados que são iguais. Como esse algoritmo tem sua eficiência comprometida à medida em que se aumenta
o número de elementos, pois se torna muito custoso, ele não é indicado para aplicações com grandes quantidade de
dados. A complexidade deste algoritmo também é quadrática, O(n²), pois ele precisa realizar dois laços
em torno do vetor para conseguir finalizar o seu trabalho, isso no pior caso, é claro.
*/
void selection_sort(){
    int i,j,menor;
    Item temp;

    for(i=0;i<k;i++){
        menor = i;
        for (j=i+1;j<=k;j++){
            if (ptr_item[j].valor < ptr_item[i].valor)
                menor = j;
            }
            if (menor != i){
                temp = ptr_item[i];
                ptr_item[i]=ptr_item[menor];
                ptr_item[menor]=temp;
            }
    }
}

/**Função que organiza os dados dentro do vetor!
Esse algoritmo é o, também conhecido, bolha. Ele é bastante sugerido na internet em sites como "stackoverflow"
pela facilidade de implementação, talvez. Possui esse nome em uma analogia a bolhas flutuando em um tanque de água
em direção a superfície até encontrar o seu próprio nível - por isso ordenação crescente. Compara pares de
valores vizinhos e os troca caso estejam na ordem errada. Ele atua de forma a mover, uma posição por vez,
o maior valor existente na posição não ordenada de um array para a sua respectiva posição no array ordenado. Toda a
atividade é repetida até que sejam sanadas as incorreções. Na primeira etapa, o do-while: encontra o maior valor e o
movimenta até a última posição. Na segunda o do-while encontra o segundo maior valor e o movimenta para a penúltima
posição do vetor. Isso continua até que não haja mais necessidade. Tem uma vantagem de ser de fácil entendimento e
construção, o que provavelmente contribua para ser um dos métodos mais difundidos de ordenação. Não é eficiente para
trabalhos com numero de dados elevado. Apresenta complexidade quadrática tanto no médio quando no pior caso, O(N²),
pois ainda que esteja parcialmente ordenado, este ainda passará pelo vetor realizando a leitura dos valores.
*/
void bubble_sort(){
    int i,passo = k, bolha;

    Item temp;

    do {
        bolha = 0;
        for(i=0;i<k;i++){
            if (ptr_item[i].valor > ptr_item[i+1].valor){
                temp = ptr_item[i];
                ptr_item[i]=ptr_item[i+1];
                ptr_item[i+1]= temp;
                bolha=i;
            }
        }
        passo--;
    }while(bolha != 0);
}

/**Função que organiza os dados dentro do vetor!
Esse algoritmo foi o que eu mais demorei a entender, pois ele é muito extenso e possui muitas condicionais o que acaba
confundido a análise além da recursividade que é outro processo ainda complexo para um novato na programação. Ele trabalha
com intercalação e com a filosofia "dividir para conquistar", em que faz bom proveito dessa ideia à medida que reduz o
tamanho de sua tarefa para ser mais eficiente. O algoritmo divide os dados em conjuntos cada vez menores para depois
ordená-los e combiná-los por meio da intercalação, daí o seu nome: merge. Para que eu conseguisse compreender e ajustar
o funcionamento do algoritmo ao meu código que até havia usado na prova de ED-MODII. Dividi em 3 etapas, a primeira da
chamada, a segunda a que realiza a divisão recursivamente e a terceira a que coloca os dados em ordem. Como é possível perceber,
ele vai dividindo o vetor até restar apenas um elemento, em seguida cria dois vetores combinando estes em um maior e ordenado.
Apresenta complexidade O(N log N) para quaisquer que sejam os casos, o que o torna extremamente estável, ainda, sua eficiência
não depende do estado inicial dos casos. No pior caso, realiza cerca de 39% menos comparações do que o quick sort no seu caso
médio. Tem uma desvantagem que é o fato de precisar de mais espaço de memória para a criação dos outros vetores.
*/
void mergeSort(Item *v, int n) {
    mergeSort_ordena(v, 0, n);
}
/* ordena o vetor v[esq..dir] */
void mergeSort_ordena(Item *v, int esq, int dir) {
    if (esq == dir)
    return;
    int meio = (esq + dir) / 2;
    mergeSort_ordena(v, esq, meio);
    mergeSort_ordena(v, meio+1, dir);
    mergeSort_intercala(v, esq, meio, dir);
    return;
}

/* intercala os vetores v[esq..meio] e v[meio+1..dir] */
void mergeSort_intercala(Item *v, int esq, int meio, int dir) {
    int i, j, l, a_tam = meio-esq+1, b_tam = dir-meio;

    Item *a = (Item*) malloc(sizeof(Item) * a_tam);

    Item *b = (Item*) malloc(sizeof(Item) * b_tam);

    for (i = 0; i < a_tam; i++){
        a[i] = v[i+esq];
    }

    for (i = 0; i < b_tam; i++){
        b[i] = v[i+meio+1];
    }

    for (i = 0, j = 0, l = esq; l <= dir; l++) {
        if (i == a_tam)
            v[l] = b[j++];
        else if (j == b_tam)
            v[l] = a[i++];
            else if (a[i].valor < b[j].valor)
                v[l] = a[i++];
            else
                v[l] = b[j++];
    }

free(a); free(b);

}

/**Função que organiza os dados dentro do vetor!
Este algoritmo também é chamado de algoritmo de ordenação por partição. Assim como o MergeSort, este algoritmo também é
recursivo e também faz uso da filosofia "dividir para conquistar". Funciona dividindo o vetor a partir de um pivô, ficando,
por exemplo, os valores menores à esquerda do pivô e os maiores à direita. Então, um elemento é escolhido como pivô e,
recursivamente, assim como o merge, divide o vetor em partes até que se chegue a um único elemento. A função auxiliar chamada
de "particiona", ficará responsável por rearranjar os dados e calcular o pivô. Não é considerado um algoritmo estável por alguns
especialistas, pois ficam algumas incertezas em relação ao pivô: Como que se escolhe o pivô?
Perceba que um pivô, no pior caso, pode dividir o vetor em dois de forma que fiquem N-1 elementos em um lado e 0 no outro.
O que leva a uma outra percepção, o caso de o particionamento não ser balanceado, nesses casos o tempo de execução pode
chegar a O(N²). Sendo assim, essa é uma desvantagem do QuickSort, no caso de um particionamento não balanceado, o insertionsort
acaba se tornando tão eficiente quanto o QuickSort. Apesar de seu pior caso ser de ordem quadrática, este algoritmo costuma
ser a melhor opção prática para ordenação de grande números de dados. Isto pois, no melhor caso, quando o vetor não estar ordenado
em nenhum sentido, ou quando os valores não são iguais, o quicksort tem complexidade n log n, O(n (log n)).
*/
void quick_sort(Item *v, int inicio, int fim){
    int pivo;
    if (fim > inicio){
        pivo = particiona(v, inicio, fim);
        quick_sort(v, inicio, pivo-1);
        quick_sort(v, pivo+1, fim);
    }
}

int particiona(Item *v, int inicio, int final){
    int esq, dir;
    Item temp, pivo;
    esq = inicio;
    dir = final;
    pivo = v[inicio];
    while (esq < dir){
        while(esq <= final && v[esq].valor <= pivo.valor)
            esq++;
        while (dir >= 0 && v[dir].valor > pivo.valor)
            dir--;

        if(esq < dir){
            temp = v[esq];
            v[esq]=v[dir];
            v[dir]=temp;
        }
    }
    v[inicio] = v[dir];
    v[dir]= pivo;
    return dir;
}

/**Função responśvel por adicionar valores no vetor!
Apresenta complexidade também quadrática, O(n²), pois para finalização do algoritmo
desta função, será necessário passar pela função "organizador", a qual tem este nível
de complexidade. Se analisado a função, desprezando o acesso a outra funçaõ, esta teria
complexidade constante, pois se obrigaria apenas de adicionar novos valores em um vetor.
*/
void add(int codigo, float valor, int escolha){
    ptr_item = (Item*) realloc(ptr_item, (k+1)*sizeof(Item));

    if (ptr_item != NULL){

        ptr_item[k].codigo = codigo;
        ptr_item[k].valor = valor;

            switch(escolha){

                case 1:
                    insertion_sort();
                    break;
                case 2:
                    selection_sort();
                    break;
                case 3:
                     bubble_sort();
                     break;
                case 4:
                    mergeSort(ptr_item, k);
                    break;
                case 5:
                    quick_sort(ptr_item, 0, k);
                    break;
                default:
                    printf("\nEscolha inválida!\n");
            }

        tamanho();
    }else {
        printf("Erro de memória!");
        return;
    }
}

/**Função de busca de valores dentro do vetor e retorna a posição!
Apresenta complexidade logarítimica, O(log n(base binária)), ou seja, esta função
realiza sua tarefa quebrando-a pela metade, o que reduz bastante o tempo de realiza
ção da mesma. A depender da constante a se comparar, uma função logarítmica pode até
ser mais eficiente. Como os testes que realizei são com pequenas quantidade de dados,
a diferença não pôde ser notada.
*/
int find_valor(float valor){
    int esq = 0, dir=k;

    while (esq <= dir){
        int meio = (esq+dir) / 2;

        if (ptr_item[meio].valor == valor){
            return meio;
        } else if (ptr_item[meio].valor > valor){
            dir = meio -1;
        } else {
            esq = meio + 1;
        }
    }
    return -1;
}

/**Função de busca de códigos dentro do vetor e que retorna a posição!
Apresenta complexidade logarítimica, O(log n(base binária)), ou seja, esta função
realiza sua tarefa quebrando-a pela metade, da mesma forma como a anterior. A única
diferença entre as duas é o tipo de parâmetro repassado na chamada.
*/
int find_codigo(int cod){
    int esq = 0, dir=k;

    while (esq <= dir){
        int meio = (esq+dir) / 2;

        if (ptr_item[meio].codigo == cod){
            return meio;
        } else if (ptr_item[meio].codigo > cod){
            dir = meio -1;
        } else {
            esq = meio + 1;
        }
    }
    return -1;
}


/**Função responsável por imprimir os dados do vetor
Apresenta complexidade linear, O(n), pois o tempo de execução da tarefa deverá
ter relação com o tamanho do vetor, ou seja o número de itens inseridos no mesmo.
Desta forma, ela percorrerá todo o vetor para finalizar sua tarefa.
*/
void imprime_repositorio(){
    if (k>0){
        for (int i=0;i<k;i++){
            printf("\nItem %d - Codigo %i / Valor %.2f\n", i, ptr_item[i].codigo, ptr_item[i].valor);
        }
    } else
        printf("\nRepositorio vazio!\n");

    printf("\n\n");
}

/**Função responsável por "zerar" o vetor!
Apresenta complexidade constante, O(1), pois destina-se unicamente a liberar os
espaços de memória reservados pelo ponteiro. É certo que esses dados continuaram,
de certa forma, na memória. Mas como reseta o 'K', então automaticamente, o vetor
pode ser reutilizado.
*/
void limpar_repositorio(){
    k=0;
    free(ptr_item);
}

/**
6. Com base na complexidade computacional, qual você considerou como sendo o melhor
algoritmo de ordenação abordado? Justifique sua resposta em no mínimo 8 linhas.

Diante das análises feitas durante o processo de implementação, percebi que o algoritmo MergeSort
tem uma lógica muito interessante, apesar de complexa de se analisar. Eu demorei consideravelmente
a compreender o seu funcionamento e cheguei até a congitar não fazer essa questão. Porém recorri ao
velho Google e, através de algumas postagens em fóruns, entender a lógica deste algoritmo. Se comparmos
ele a outros algoritmos com a lógica de divisão e conquista, como o Quicksort, o Merge apresenta a mesma
complexidade no pior e médio caso, mas se destaca no melhor caso. Além do que, existem implementações do
mergesort que permitem que ele seja melhorado em relação ao uso de memória, que é O(N) para O(N log N).
Apenas um fator me incomoda em relação ao QuickSort e MergeSort que é o fator recursividade. Pois acredito
que, a depender do compilador, a recursão acaba utilizando muita memória para realizar as tarefas, visto que
a recursividade só irá liberar memória após a saída final da função. Mas como temos memórias muito grandes
atualmente, acredito que isso acabe sendo minimizado, porém é válido resaltar. Por isso considero o MergeSort
o melhor algoritmo de ordenação, sobretudo por conta de sua estabilidade.
*/



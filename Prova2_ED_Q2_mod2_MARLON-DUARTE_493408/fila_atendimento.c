#include "fila_atendimento.h"

/**TAD da resolução da 3 questão. Segue:
Q3-PROVA ED MARLON DUARTE - Um centro hospitalar resolveu abandonar as ficha de
papel pois havia muitos erros no trato com os os pacientes que aguardavam na fila
por atendimento comum (Atendimentos não emergenciais). O programa seria implementado
em um painel(display) que recomessa o processor todos os dias. Para essa mudança, 
o diretor do centro pediu que se construísse um programa simples em modo texto que: 

	#Recebesse as solicitações com um código identificador, idade e o nome do paciente;
    #Imprimisse a lista de solicitações;
    #Imprimisse o paciente da vez;
    #Avisasse quando todos tenham sido atendidos.

R: Para resolver essa tarefa, deve-se utilizar um TAD tipo FILA. Isto porque, como
se deseja atendimento comum, o primeiro que chega é que deverá ter prioridade. Como
a fila tem lógica, FIFO, first in first out, ela se aplica muito bem ao caso em questão.
*/

/*"Parênteses" :
Professor, sei que esta TAD é demasiada simples para a disciplina, porém o senhor deixou
enfatizado a originalidade da resolução da questão. Diante disso, fiquei um pouco sem
criatividade para desenvolver algo que usasse um dos código que já enviei em outras tarefas.
Mas, apesar de haver formas melhores, a implementação representa uma fila estática, conteúdo 
trabalhado até aqui. Ainda, fiz bom uso das ferramentas que foi possível a mim assimiliar de 
forma proveitosa. Todos os conceitos apresentados, apesar do ensino remoto, foram compreendidos.
*/
Paciente *paciente;
int tam=0, saida=0;

/**Função responsável por iniciar a alocação!
Apresenta complexidade constante, O(1), pois tem a unica funçaõ de chamar uma
outra função de complexidade constante para alocar dados necessários a utilização
do vetor.
*/
void iniciar_fila(){
    paciente = (Paciente*) realloc(paciente, sizeof(Paciente));
}

/**Função de incremento de variável global!
Apresenta complexidade constante, O(1), haja vista que esta função apenas adiciona
+1 a cada vez que é chamada.
*/
int tamanho(){
    return tam++;
}

/**Função responsável pela inserção de dados nos índices do vetor!
Apresenta complexidade constante, O(1), pois reserva espaço de memória através de
uma função externa e insere dados no vetor de struct.
*/
void inserir_paciente(){

    paciente = (Paciente*) realloc(paciente, (tam+1)*sizeof(Paciente));

    printf("\nQual o nome do paciente?\n");
    scanf("\n%[^\n]s", paciente[tam].nome);
    printf("\nQual a idade do paciente?\n");
    scanf("%d", &paciente[tam].idade);
    printf("\nDigite o código de atendimento:\n");
    scanf("%ld", &paciente[tam].codigo);

    tamanho();
}

/**Função de impressão para todos os dados do vetor!
Apresenta complexidade linear, O(n), esta função percorre os indices imprimindo todos
os itens inseridos no vetor. A complexidade é linear, justamente por ela percorrer todo
o vetor, ou seja, ela será tão demorada quanto quão grande seja o vetor.
*/
void imprimir_fila(){
    for (int i=0;i<tam;i++){
        printf("\nPaciente %d: %s - %d - %ld\n", i+1, paciente[i].nome, paciente[i].idade, paciente[i].codigo);
    }
}

/**Função responsável por contar as impressão de saída do display!
Apresenta complexidade constante ,O(1), pois esta função apenas tem a tarefa de incrementar
uma variável global.
*/
int contador(){
    return saida++;
}

/**Função de chamada de próximo a ser atendido!
Apresenta complexidade constante, O(1), possui um if que verifica se realmente houve incremento
na variável tamanho, a qual tem a função de registrar o numero de indices utilizados do vetor.
Após a execução do printf, ele incrementa o contador para indicar que o primeiro já foi atendido.
Em seguida, chama a função status para analisar se ainda existem itens a serem imprimidos.
*/
void imprimir_da_vez(){
    if (tam>0)
        printf("\nPróximo: %s - %ld\n", paciente[saida].nome, paciente[saida].codigo);
    contador();
    status();
}

/**Função que ferifica o status da fila de atendimento!
Apresenta complexidade constante, O(1), como mencionado na função "imprimir_da_vez", apenas imprimi
o status da fila. Caso tenham sido impressos um número de pacientes igual ao tamanho, significa que
todos já foram atendidos.
*/
void status(){
    if (saida == tam)
        printf("\nTodos atendidos!\n");
    else
        printf("\nFaltam pacientes serem atendidos\n");
}



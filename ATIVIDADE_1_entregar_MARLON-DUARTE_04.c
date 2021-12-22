#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float ano, idade = 0, aluno_3 = 0, total_livros = 0, redacao = 0;
    float livros, livros_2ano = 0, total_alunos = 0, redacao_like = 0;
    do {

        printf("Digite a sua idade: (0 para sair) \n");
        scanf("%f", &idade);
        if (idade != 0)
        {

            printf("Digite qual ano esta cursando: \n");
                scanf("%f", &ano);
            printf("Digite quantos livros você lê por mês: \n");
                scanf("%f", &livros);
            total_livros = total_livros + livros;

            printf("Você gosta de redação? 1 = sim; 0 => não \n");
                scanf(" %f", &redacao);
            printf("=========================================== \n");

            total_alunos++;
        }

        redacao_like = redacao_like + redacao;

            if (ano == 3)
            {
                aluno_3 = aluno_3 + 1;
            }
            if (ano == 2)
            {
                if (livros_2ano < livros)
                    {
                        livros_2ano = livros;
                    }
            }
    }while (idade != 0);


    printf("\t O total de alunos no 3º ano :              %.2f \n", aluno_3); //ok
    printf("\t A maior quantidade de livros lida pelo 2º: %.2f \n", livros_2ano);
    printf("\t A media de livros lida no total:           %.2f livros \n", total_livros/total_alunos); //ok
    printf("\t O percentual de não amantes da redação:    %.2f %% \n", ((100*(total_alunos - redacao_like))/total_alunos)); //ok
    printf("\t O total de alunos calculados foram:        %.2f \n\n ", total_alunos); //ok

	return 0;
}

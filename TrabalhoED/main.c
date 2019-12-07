#include <stdio.h>
#include <stdlib.h>
#include "listaSimplesAlunos.h"

int menu()
{
    int opcao;
    printf("\n");
    printf("\nOpcoes:");
    printf("\n0. Sair.");
    printf("\n1. Inserir um aluno no inicio da lista. ");
    printf("\n2. Inserir um aluno no fim da lista. ");
    printf("\n3. Mostrar aluno com a maior media.");
    printf("\n4. Alterar alguma informacao de um aluno. ");
    printf("\n5. Mostrar a lista de alunos. ");
    printf("\n6. Mostrar os alunos aprovados. ");
    printf("\n7. Mostrar os alunos reprovados. ");
    printf("\n8. Excluir um aluno da lista.");
    printf("\nInforme a opcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

int main()
{
    int opcao, ra;
    float n1, n2;
    char nome[50];
    Alunos *L, *aluno;
    L = criar();
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            setbuf(NULL, NULL);
            printf("\nInsira o nome do aluno: ");
            scanf("%[^\n]s", nome);
            printf("\nInsira o RA do aluno: ");
            scanf("%d",&ra);
            printf("\nInsira a nota 1: ");
            scanf("%f", &n1);
            printf("\nInsira a nota 2: ");
            scanf("%f", &n2);
            L = inserirInicio(L, nome, ra, n1, n2);
            break;
        case 2:
            printf("\nInsira o nome do aluno: ");
            scanf("%[^\n]s", nome);
            printf("\nInsira o RA do aluno: ");
            scanf("%d",&ra);
            printf("\nInsira a nota 1: ");
            scanf("%f", &n1);
            printf("\nInsira a nota 2: ");
            scanf("%f", &n2);
            L = inserirFim(L, nome, ra, n1, n2);
            break;
        case 3:
            printf("\nAluno com a maior media: ");
            aluno = buscarMaiorMedia(L);
            mostraAluno(aluno);
            break;
        case 4:
            printf("\nInforme o RA do aluno que tera suas informacoes alteradas: ");
            scanf("%i", &ra);
            alterarDados(L, ra);
            break;
        case 5:
            printf("\nAlunos: ");
            mostrar(L);
            break;
        case 6:
            mostrarAprovados(L);
            break;
        case 7:
            mostrarReprovados(L);
            break;
        case 8:
            printf("\nInsira o RA do aluno que deseja excluir: ");
            scanf("%d",&ra);
            L = excluir(L, ra);
            break;
        }
    }
    while(opcao != 0);
    liberar(L);
    return 0;
}

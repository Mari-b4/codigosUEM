#ifndef LISTASIMPLESALUNOS_H_INCLUDED
#define LISTASIMPLESALUNOS_H_INCLUDED

//tipo exportado
typedef struct listaSimplesAlunos Alunos;

//funcoes exportadas
Alunos* criar();
Alunos* inserirFim(Alunos *L, char[50] nome, int ra, float n1, float n2);
Alunos* inserirInicio(Alunos *L, char[50] nome, int ra, float n1, float n2);
Alunos* calcularMedia(Alunos *L);
Alunos* buscarMaiorMedia(Alunos *L);
Alunos* alterarDados(Alunos *L);
void mostrar(Alunos *L);
void mostrarAprovados(Alunos *L);
void mostrarReprovados(Alunos *L);
Alunos* excluir(Alunos* L, int ra);


#endif // LISTASIMPLESALUNOS_H_INCLUDED
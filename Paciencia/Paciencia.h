#ifndef PACIENCIA_H_INCLUDED
#define PACIENCIA_H_INCLUDED

typedef struct carta carta;

typedef struct listaParaFila fila;

typedef struct listaParaPilha no;

typedef struct pilha pilha;

pilha *criar(int naipeDaPilha);
no *alocarNo(carta novaCarta);
pilha *desempilhar(pilha *pilha, carta *cartaSaida);
int pilha_vazia(pilha *pilha);
void *liberarPilha(pilha *pilha);
fila *criar_fila(fila *fila);
fila alocarFila(carta cartaFila);
fila *enfileirar(fila *fila, carta carta);
fila *desenfileirar(fila *fila, carta *saida);
int fila_vazia(fila *fila);
void liberarFila(fila *fila);
carta alocarCarta(int valor, int naipe);
fila *criar_baralho();
pilha *criar_pilha();
void mostrarNaipe(carta carta);
void *exibir_fila(fila *fila);
void *exibir_pilha(pilha *pilha);
fila *embaralhar(fila *fila);
int movimento_valido(carta *carta, pilha *pilha);
void jogada(fila *baralho, pilha *pilhaNaipe);




#endif // PACIENCIA_H_INCLUDED

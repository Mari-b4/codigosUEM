#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Paciencia.h"

typedef struct carta{
  int valor;
  char naipe[10];
}carta;

typedef struct tipo_no{
  carta carta;
  carta *prox;
}no;

typedef struct listaSimples{
  carta cartaAtual;
  carta *proxCarta;
}fila;

typedef struct tipo_pilha{
  carta *base;
  carta *topo;
}pilha;

carta criaCarta(){
  carta nova;
  printf("Informe o valor da carta:");
  scanf("%i", &nova->valor);
  printf("Informe o naipe da carta:");
  scanf("%s", nova->naipe);

  return nova;
}

pilha *criar_pilha(){
  pilha *pilha = (pilha*) malloc (sizeof(pilha));
  if(pilha == NULL){
    printf("\nErro na reserva de memória");
  }else{
    pilha->base = NULL;
    pilha->topo = pilha->base;
  }
  return pilha;
}

int pilha_vazia(pilha *pilha){
  if(pilha->topo == NULL){
    return 1; //a pilha está vazia
  }else{
    return 0; //a pilha não está vazia
  }
}

pilha *empilhar(pilha *pilha, carta carta){
  fila
}

fila *criar_baralho(){
  fila *baralho = NULL;
  carta novaCarta = criaCarta();
  baralho = enfileirar(baralho, novaCarta);
}

fila alocar(carta novaCarta){
  fila *novo = (fila *) malloc (sizeof(fila));
  if(novo == NULL){
    printf("Erro na reserva de memoria");
  }else{
    novo->valor = novaCarta;
    novo->prox = NULL;
  }
  return novo;
}

fila enfileirar(fila *fila , carta novaCarta){ //enfileirar
  fila *aux, *novo;
  novo = alocar(novaCarta);
  aux = F;
  if (aux == NULL){ // Confere se L ainda está vazia
    aux = novo;
    novo->prox = NULL;
  }else{ // Se L não estiver vazia
    while (aux->prox != NULL){ //roda a fila até achar o último
      aux = aux->prox;
    }
    aux->prox = novo;
  }
  return aux;
}

fila desenfileirar(fila *F){
  fila *excluir, *aux;
  excluir = F;
  aux = F;
  if(aux != NULL){
    printf("O elemento %i foi removido!", aux->valor);
    aux = excluir->prox;
    free(excluir); // OU delete excluir; //(em C++)
  }else{
    printf("\nFila já está vazia");
  }
  return F;
}

void liberar(fila *F){
	fila *excluir;
	while(F != NULL){
	 	excluir = F;
		F = F->prox;
		free(excluir);
	}
	free(F);
}

void mostrar(fila *F){
  fila *aux = F;
  if (aux == NULL){
    printf("Fila vazia!");
  }else{
    while (aux != NULL){
      printf("\nValor: %i", aux->valor);
      aux = aux->prox;
    }
  }
}

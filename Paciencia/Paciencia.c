#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Paciencia.h"

typedef struct carta{
  int valor;
  int naipe; //1-copas; 2-espadas; 3-ouros; 4-paus
}carta;

typedef struct listaParaFila{ //para trabalhar a fila
  carta carta;
  struct listaParaFila *proxCarta;
}fila;

typedef struct listaParaPilha{ //para trabalhar a pilha
  carta cartaAtual;
  struct listaParaPilha *prox;
}no;

typedef struct pilha{
  int naipe;
  no *base;
  no *topo;
}pilha;

//operações elementares de pilha
pilha *criar(int naipeDaPilha){
  pilha *pilha = (pilha*) malloc (sizeof(pilha));
  if(pilha == NULL){
    printf("\nErro na reserva de memória");
  }else{
    pilha->naipe = naipeDaPilha;
    pilha->base = NULL;
    pilha->topo = pilha->base;
  }
}

no *alocar(carta novaCarta){
  no *novo = (no*) malloc (sizeof(no));
  if(novo == NULL){
    printf("\nErro na reserva de memória");
  }else{
    no->cartaAtual = novaCarta;
    no->prox = NULL;
  }
}

pilha *empilhar(pilha *pilha, carta novaCarta){
  no *novo = alocar(novaCarta);
  if(pilha_vazia(pilha)){
    pilha->base = novo;
    pilha->topo = novo;
  }else{
    pilha->topo->prox = novo;
    pilha->topo = novo;
  }
}

pilha *desempilhar(pilha *pilha, carta *cartaSaida){
  *cartaSaida->valor = pilha->topo->cartaAtual->valor;
  *cartaSaida->naipe = pilha->topo->cartaAtual->naipe;
  no *aux = pilha->base;
  if(aux == pilha->topo){
    pilha->base = NULL;
    free(pilha->topo);
    pilha->topo = pilha->base;
  }else{
    while(aux->prox != pilha->topo){
      aux = aux->prox;
    }
    free(pilha->topo);
    pilha->topo = aux;
    pilha->topo->prox = NULL;
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

void *liberar(pilha *pilha){
  pilha *excluir;
}

//operações elementares de fila

fila alocar(carta carta){
  fila *nova = (fila*) malloc (sizeof(fila));
  if(novo == NULL){
    printf("\nErro na reserva de memoria");
  }else{
    novo->carta = carta;
    novo->proxCarta = NULL;
  }
  return novo;
}

fila *enfileirar(fila *fila, carta carta){
  fila *aux, *novo;
  novo = alocar(carta);
  aux = fila;
  while(aux->prox != NULL){
    aux = aux->prox;
  }
  aux->prox = novo;
  return fila;
}

fila *desenfileirar(fila *fila, carta *saida){
  fila *excluir = fila;
  if(excluir != NULL){
    fila = excluir->prox;
    *saida = excluir->valor;
    free(excluir);
  }
  return fila;
}

int fila_vazia(fila *fila){
  if(fila == NULL){
    return 1; // a fila está vazia
  }else{
    return 0; //a fila nao está vazia
  }
}

void liberar(fila *fila){
	fila *excluir;
	while(fila != NULL){
	 	excluir = fila;
		fila = fila->prox;
		free(excluir);
	}
	free(fila);
}

//operações específicas do jogo
carta alocar(int valor, int naipe){}

fila *criar_baralho(){
  fila *baralho = NULL;
  carta carta;
  int valor, naipe;
  for(naipe=1;naipe<=4;naipe++){//define o naipe da carta
    carta->naipe = naipe;
    for(valor=1;valor<=13;valor++){
        carta->valor = valor;
    }
    baralho = enfileirar(baralho, carta);
  }
  return baralho;
}

pilha *criar_pilha(){
  int naipePilha;
  pilha *pilha = criar(naipePilha);

}

void mostrarNaipe(carta carta){
  switch(carta->naipe){
    case 1:
      printf("Copas");
      break;
    case 2:
      printf("Espadas");
      break;
    case 3:
      printf("Ouros");
      break;
    case 4:
      printf("Paus");
      break;
  }
}

void *exibir_fila(fila *fila){
  fila *aux = fila;
  if (aux == NULL){
    printf("Baralho vazio!");
  }else{
    while (aux != NULL){
      printf("\nValor da carta: %i", aux->valor);
      printf("\nNaipe da carta: ");
      mostrarNaipe();
      aux = aux->prox;
    }
  }
}

void *exibir_pilha(pilha *pilha){}

fila *embaralhar(fila *fila){}

int movimento_valido(carta *carta, pilha *pilha){}

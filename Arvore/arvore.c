struct tipo_no_arvore{
    int valor;
    struct tipo_no_arvore *esq;
    struct tipo_no_arvore *dir;
};

no_arvore *criar(){
    return NULL;
}

int arvore_vazia(no_arvore *raiz){
    if (raiz == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

no_arvore *alocar_arvore(int dado){
    no_arvore *novo=(no_arvore*) malloc(sizeof(no_arvore));
    if(!novo){
        printf("\nErro de reserva de memoria.\n");
        exit(1);
    }
    else{
        novo->valor = dado;
        novo->esq = NULL;
        novo->dir = NULL;
    }
    return novo;
}

no_arvore* inserir_arvore(no_arvore *raiz, no_arvore *novo){
    if(arvore_vazia(raiz)){
        raiz = novo;
    }
    else{
        if (novo->valor < raiz->valor){
            raiz->esq = inserir(raiz->esq, novo);
        }
        else{
            raiz->dir = inserir(raiz->dir, novo);
        }
    }
    return raiz;
}

no_arvore* buscar(no_arvore *raiz, int dado){
    if(arvore_vazia(raiz)){
        return NULL;
    }
    else{
        if (dado < raiz->valor){
            return buscar(raiz->esq, dado);
        }
        else{
            if (dado > raiz->valor){
            return buscar(raiz->dir, dado);
            }
        }
    }
    return raiz;
}

void mostrar_pre_ordem(no_arvore *raiz){
    if (raiz != NULL){
        printf("%d ", raiz->valor);
        mostrar_pre_ordem(raiz->esq);
        mostrar_pre_ordem(raiz->dir);
    }
}

void mostrar_in_ordem(no_arvore *raiz){
    if (raiz != NULL){
        mostrar_in_ordem(raiz->esq);
        printf("%d ", raiz->valor);
        mostrar_in_ordem(raiz->dir);
    }
}


void mostrar_pos_ordem(no_arvore *raiz){
    if (raiz != NULL){
        mostrar_pos_ordem(raiz->esq);
        mostrar_pos_ordem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

void mostrar_largura(no_arvore *raiz){
    fila *f = NULL;
    no_arvore *aux;
    f = enfileirar(f, raiz);
    do{
        f = desenfileirar(f, &aux);
        if(aux != NULL){
            printf("%d ",aux->valor);
            f = enfileirar(f, aux->esq);
            f = enfileirar(f, aux->dir);
        }
    }while (f!=NULL);
}



no_arvore *remover_copia_antecessor(no_arvore *raiz, int dado){
    no_arvore *aux;
    if(arvore_vazia(raiz)){
        return NULL;
    }
    else{
        if(dado < raiz->valor){
        raiz->esq = remover_copia_antecessor(raiz->esq, dado);
        }
   //}
    //else{
        if(dado > raiz->valor){
        raiz->dir = remover_copia_antecessor(raiz->dir, dado);
        }
    //}
    //else{
        if (raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            raiz = NULL;
        }
    //}
        else{
            if(raiz->esq == NULL){
            aux = raiz;
            raiz = raiz->dir;
            free(aux);
            }
        }
        //else{
            if(raiz->dir == NULL){
            aux = raiz;
            raiz = raiz->esq;
            free(aux);
            }
        //}
        //else{
            aux = raiz->esq;
            while(aux->dir!=NULL){
                aux = aux->dir;
            }
            raiz->valor = aux->valor;
            aux->valor = dado;
            raiz->esq = remover_copia_antecessor(raiz->esq, dado);
        //}
    }
    return raiz;
}

no_arvore *remover_fusao_antecessor(no_arvore *raiz, int dado){
    no_arvore *aux;
    no_arvore *excluir = raiz;
    if(arvore_vazia(raiz)){
        return NULL;
    }
    //else
        if(dado < raiz->valor){
            raiz->esq = remover_fusao_antecessor(raiz->esq, dado);
        }
    //else
        if(dado > raiz->valor){
            raiz->dir = remover_fusao_antecessor(raiz->dir, dado);
        }
    else{
        if (raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            raiz = NULL;
        }
        //else
            if(raiz->esq == NULL){
                aux = raiz;
                raiz = raiz->dir;
                free(aux);
            }
        //else
            if(raiz->dir == NULL){
                aux = raiz;
                raiz = raiz->esq;
                free(aux);
            }
        else{
            aux = raiz->esq;
            while(aux->dir!=NULL){
                aux = aux->dir;
            }
            aux->dir = raiz->dir;
            raiz = raiz->esq;
            free(excluir);
        }
    }
return raiz;
}

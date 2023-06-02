typedef struct no{
    int chave;
    struct no *esquerda, *direita;
}No;

typedef struct{
    No *raiz;
    int tam;
}Arv;

No* InserirArv(No *raiz,int valor){
    if(raiz == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    else{
        if(valor < raiz->chave){
            raiz->esquerda = InserirArv(raiz->esquerda,valor);
        }
        if(valor > raiz->chave){
            raiz->direita = InserirArv(raiz->direita,valor);
        }
        return raiz;
    }
}

void ImprimeArv(No *raiz){
    if(raiz != NULL){
        ImprimeArv(raiz->esquerda);
        printf("%d ", raiz->chave);
        ImprimeArv(raiz->direita);
    }
}

No* RemoverArv(No *raiz, int item){
    if(raiz == NULL){
        printf("\nValor nao encontrado!\n");
        return NULL;
    }else {
        if(raiz->chave == item){
            if(raiz->esquerda == NULL && raiz->direita == NULL){
                free(raiz);
                return NULL;
            }
            else{
                if(raiz->esquerda == NULL || raiz->direita == NULL){
                    No *aux;
                    if(raiz->esquerda != NULL)
                        aux = raiz->esquerda;
                    else
                        aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else{
                    No *aux = raiz->esquerda;
                    while(aux->direita != NULL)
                        aux = aux->direita;
                    raiz->chave = aux->chave;
                    aux->chave = item;
                    raiz->esquerda = RemoverArv(raiz->esquerda,item);
                    return raiz;
                }
            }
        }
        else{
            if(item < raiz->chave)
                raiz->esquerda = RemoverArv(raiz->esquerda, item);
            else
                raiz->direita = RemoverArv(raiz->direita, item);
            return raiz;
        }
    }
}

int BuscarArv(No *raiz, int val){
    if(raiz == NULL){
        printf("\nValor nao encontrado na Arvore!\n");
        return 1;
    }else{
        if(val < raiz->chave){
            return BuscarArv(raiz->esquerda, val);
        } else if(val > raiz->chave){
            return BuscarArv(raiz->direita, val);
        } else {
            printf("\nValor encontrado na Arvore!\n");
            return 0;
        }
    }
}

void ImprimirDireitaArv(No *raiz){
    if(raiz != NULL){
        ImprimirDireitaArv(raiz->direita);
        printf(" %d ", raiz->chave);
        ImprimirDireitaArv(raiz->esquerda);
    }
}

void MaiorArv(No *raiz) {
    if (raiz == NULL) {
        printf("\nArvore vazia!\n");
        return;
    }
    No *atual = raiz;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    printf("\nMaior elemento da Arvore é: %d\n", atual->chave);
}
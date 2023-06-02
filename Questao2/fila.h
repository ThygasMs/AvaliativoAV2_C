struct NodeF{
    int conteudo;
    struct NodeF *prox;
    int tam;
};
typedef struct NodeF nodeF;

int EMPTY(nodeF *FILA){
    if(FILA->prox == NULL)
        return 1;
    else
        return 0;
}

void EnqueueFila(nodeF *FILA){
    nodeF *novo=(nodeF *)malloc(sizeof(nodeF));
    novo->prox = NULL;
    
    printf("\nNovo item da Fila: ");
    scanf("%d", &novo->conteudo);
    
    if(EMPTY(FILA)){
        FILA->prox = novo;
    }
    else{
        nodeF *tmp = FILA->prox;
        while(tmp->prox != NULL){
            tmp= tmp->prox;
        }
        tmp->prox = novo;
    }
    FILA->tam++;
}

void DequeueFila(nodeF *FILA){
    if(FILA->prox == NULL){
        printf("\nFila esta vazia\n");
        return;
    }
    else{
        nodeF *tmp = FILA->prox;
        FILA->prox = tmp->prox;
        FILA->tam--;
        free(tmp);
    }
}

void ImprimeFila(nodeF *FILA){
    if(EMPTY(FILA)){
        printf("\nFila vazia!\n");
        return;
    }
    nodeF *tmp;
    tmp = FILA->prox;
    printf("\nFila:");
    while(tmp != NULL){
        printf("%3d", tmp->conteudo);
        tmp = tmp->prox;
    }
    printf("\nQtde itens PILHA: %d\n", FILA->tam);
}

void FreeFila(nodeF *FILA){
    while(FILA->prox != NULL){
        DequeueFila(FILA);
    }
}

int MaiorElementoFila(nodeF *FILA) {
    if (EMPTY(FILA)) {
        printf("\nFila vazia!\n");
        return -1;
    }
    int maior = FILA->prox->conteudo;
    nodeF *tmp = FILA->prox->prox;
    while (tmp != NULL) {
        if (tmp->conteudo > maior) {
            maior = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("\nO maior elemento da fila é: %d\n",maior);
}

int MenorElementoFila(nodeF *FILA) {
    if (EMPTY(FILA)) {
        printf("\nFila vazia!\n");
        return -1; 
    }
    int menor = FILA->prox->conteudo;
    nodeF *tmp = FILA->prox->prox;
    while (tmp != NULL) {
        if (tmp->conteudo < menor) {
            menor = tmp->conteudo;
        }
        tmp = tmp->prox;
    }
    printf("\nO menor elemento da fila é: %d\n",menor);
}
struct NodeP{
    int item;
    struct NodeP *prox;
    int tam;
    struct NodeP *topo;
};
typedef struct NodeP nodeP;

int vazia(nodeP *PILHA){
    if(PILHA->prox == NULL)
        return 1;
    else
        return 0;
    }
    
void EmpilhaPilha(nodeP *PILHA){
    nodeP *novo=(nodeP *) malloc(sizeof(nodeP));
    novo->prox = NULL;
    
    printf("\nNovo item: ");
    scanf("%d", &novo->item);
    
    if(vazia(PILHA)){
        PILHA->prox = novo;
    }
    else{
        nodeP *tmp = PILHA->prox;
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }
    PILHA->tam++;
    PILHA->topo = novo;
}

void ImprimePilha(nodeP *PILHA){
    if(vazia(PILHA)){
        printf("\nPILHA vazia!\n");
        return;
    }
    nodeP *tmp;
    tmp = PILHA->prox;
    printf("\nPILHA:");
    while( tmp != NULL){
        printf("%3d", tmp->item);
        tmp = tmp->prox;
    }
    printf("\nQtde itens PILHA: %d",PILHA->tam);
    printf("\n");
}

void DesempilharPIlha(nodeP *PILHA){
    if(PILHA->prox == NULL){
        printf("\nPILHA ja vazia\n");
        return;
    }
    else{
        nodeP *ultimo = PILHA->prox;
        nodeP *penultimo = PILHA;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        free(ultimo);
        penultimo->prox = NULL;
        PILHA->tam--;
        PILHA->topo = penultimo;
    }
}

void FreePilha(nodeP *PILHA){
    while(PILHA->prox != NULL){
        DesempilharPIlha(PILHA);
    }
}

int TopoPilha(nodeP *PILHA){
   if(vazia(PILHA)){
       printf("\nA Pilha está Vazia.\n");
       return -1;
    }
    else{
        int topo = PILHA->topo->item;
        printf("\nO topo da pilha é: %d\n", topo);
    }
    
}
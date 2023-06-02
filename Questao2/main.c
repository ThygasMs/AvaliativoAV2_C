// EXERCÍCIO AVALIATIVO AV2
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"
#include "arvore.h"

// 2. (LISTAS, PILHAS, FILAS e ÁRVORES) Implemente um menu em Linguagem C que apresente as
// seguintes opções de escolha (4,0 pontos):
// (1) Executar Pilha
// (2) Executar Fila
// (3) Executar Árvore
// O usuário tem poder de escolher qual estrutura deseja inserir seus dados. Para cada uma estrutura
// implementada, a mesma deve implementar as funções abaixo (em outro menu de escolha):
    // a. Estrutura Pilha: Empilha, Desempilha, Imprimir Pilha, Limpar Pilha, Imprimir Topo Pilha. (1 ponto)
    // b. Estrutura Fila: Enqueue, Dequeue, Imprimir Fila, Limpar Fila, Maior elemento da Fila, Menor
    // elemento da Fila. (1 ponto)
    // c. Estrutura Árvore e todas as operações vista em aula, bem como as seguintes operações:
        // i. Implemente a função de Buscar elemento na Árvore Binária.
        // ii. Implemente a função para imprimir os elementos da sub-árvore a direita primeiro,
        // imprime a raiz e depois imprime a sub-árvore a esquerda.
        // iii. Implemente a função recursiva que irá retornar o maior elemento da Árvore Binária.

int main(){
    int opcao,opcaoPilha,opcaoFila,opcaoArvore;
    
    nodeP *PILHA = (nodeP *) malloc(sizeof(nodeP));
    PILHA->prox = NULL;
    nodeF *FILA = (nodeF *) malloc(sizeof(nodeF));
    FILA->prox = NULL;
    Arv arv;
    arv.raiz = NULL;
    No *raiz = NULL;
    
    ("Digite qual deseja executar:\n");
    printf("(1)Pilha\n(2)Fila\n(3)Árvore\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);
    while(true){
        if(opcao == 1){
            printf("\nDigite qual deseja executar: \n");
            printf("(1)Empilha\n(2)Desempilhar\n(3)Imprimir Pilha\n(4)Limpar Pilha\n(5)Imprimir Topo Pilha\n(6)Finalizar Programa\n");
            printf("Digite sua escolha: ");
            scanf("%d", &opcaoPilha);
            if(opcaoPilha == 1){
               EmpilhaPilha(PILHA);
            }
            else if(opcaoPilha == 2){
                DesempilharPIlha(PILHA);
            }
            else if(opcaoPilha == 3){
                ImprimePilha(PILHA);
            }
            else if(opcaoPilha == 4){
                FreePilha(PILHA);
            }
            else if(opcaoPilha == 5){
               TopoPilha(PILHA);
            }
            else if(opcaoPilha == 6){
                printf("\nPrograma Finalizado");
                break;
            }
            else{
                printf("\nOpcão inválida!\n");
            }
        }
        else if(opcao == 2){
            printf("\nDigite qual deseja executar: \n");
            printf("(1)Enqueue\n(2)Dequeue\n(3)Imprimir Fila\n(4)Limpar Fila\n(5)Maior Elemento da Fila\n(6)Menor Elemento da Fila\n(7)Finalizar Programa\n");
            printf("Digite sua escolha: ");
            scanf("%d", &opcaoFila);
            if(opcaoFila == 1){
                EnqueueFila(FILA);
            }
            else if(opcaoFila == 2){
                DequeueFila(FILA);
            }
            else if(opcaoFila == 3){
                ImprimeFila(FILA);
            }
            else if(opcaoFila == 4){
                FreeFila(FILA);
            }
            else if(opcaoFila == 5){
                MaiorElementoFila(FILA);
            }
            else if(opcaoFila == 6){
                MenorElementoFila(FILA);
            }
            else if(opcaoFila == 7){
                printf("\nPrograma Finalizado");
                break;
            }
            else{
                printf("\nOpcão inválida!\n");
            }
        }
        else if(opcao == 3){
            printf("\nDigite qual deseja executar: \n");
            printf("(1)Inserir\n(2)Remover\n(3)Imprimir Arvore\n(4)Buscar Elemento\n(5)Imprimir Sub-Direita, Raiz e Sub-Esquerda\n(6)Maior Elemento\n(7)Finalizar Programa\n");
            printf("Digite sua escolha: ");
            scanf("%d", &opcaoArvore);
            if(opcaoArvore == 1){
                int valor;
                printf("\nDigite o valor que deseja inserir: ");
                scanf("%d",&valor);
                raiz = InserirArv(raiz,valor);
            }
            else if(opcaoArvore == 2){
                int valor;
                printf("Digite o valor que deseja remover: ");
                scanf("%d",&valor);
                RemoverArv(raiz,valor);
            }
            else if(opcaoArvore == 3){
                printf("\n");
                ImprimeArv(raiz);
                printf("\n");
            }
            else if(opcaoArvore == 4){
                int valor;
                printf("\nQual valor deseja busca? ");
                scanf("%d", &valor);
                BuscarArv(raiz,valor);
            }
            else if(opcaoArvore == 5){
                printf("\n");
                ImprimirDireitaArv(raiz);
                printf("\n");
            }
            else if(opcaoArvore == 6){
                MaiorArv(raiz);
            }
            else if(opcaoArvore == 7){
                printf("\nPrograma Finalizado");
                break;
            }
            else{
                printf("\nOpcão inválida!\n");
            }
        }    
        else{
            printf("\nOpção inválida.\n");
            printf("Digite novamente: ");
            scanf("%d",&opcao);
        }
    }
}

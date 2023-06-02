#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "funcoes.h"
// 1. (ORDENAÇÃO) Desenvolva um programa em C que tendo um vetor de n posições, imprima esse
// vetor ordenado em ordem crescente. Elabore um menu que escolha duas formas de ordenação:
// Bubble Sort ou InsertionSort. (1,0 ponto)
int main() {
    int n, metodo;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vetor[n];
    for (int i = 0; i < n; i++) {
        printf("Digite o %dº elemento: ", i+1);
        scanf("%d", &vetor[i]);
    }
    printf("\nEscolha o método de ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("Digite a sua escolha: ");
    scanf("%d", &metodo);
    printf("\nVetor antes da ordenação: ");
    imprimir(vetor, n);
    while(true){
        if(metodo == 1){
            bubbleSort(vetor, n);
            printf("\nVetor após a ordenação com Bubble Sort: ");
            imprimir(vetor, n);
            break;
        }
        else if(metodo == 2){
            bubbleSort(vetor, n);
            printf("\nVetor após a ordenação com Bubble Sort: ");
            imprimir(vetor, n);
            break;
        }
        else{
            printf("\nOpção inválida.\n");
            printf("Digite a sua escolha: ");
            scanf("%d", &metodo);
        }
    }
    return 0;
}

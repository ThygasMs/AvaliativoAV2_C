void bubbleSort(int vetor[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void insertionSort(int vetor[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j+1] = vetor[j];
            j = j - 1;
        }
        vetor[j+1] = key;
    }
}

void imprimir(int vetor[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
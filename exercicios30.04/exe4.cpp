// ATIVIDADE 4 - Temos um vetor totalmente invertido: {9, 8, 7, 6, 5, 4, 3, 2, 1}.
// Missão: Em um mesmo programa, passe esse vetor por uma função Bubble Sort e por uma função Selection Sort. Imprima o número de Comparações e Trocas de ambos. Compare os resultados. 
#include <stdio.h>

void mostrarVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


void bubbleSort(int vetor[], int tamanho){
    int comparacoes = 0;
    int trocas = 0;

    for(int i = 0; i < tamanho - 1; i++){
        for(int j = 0; j < tamanho - 1 - i; j++){

            comparacoes++;

            if(vetor[j] > vetor[j+1]){
                int auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
                trocas++;
            }
        }
    }

    printf("\nBubble Sort:");
    printf("\nVetor ordenado: ");
    mostrarVetor(vetor, tamanho);

    printf("Comparacoes: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}


void selectionSort(int vetor[], int tamanho){
    int comparacoes = 0;
    int trocas = 0;

    for(int i = 0; i < tamanho - 1; i++){
        int menorIndice = i;

        for(int j = i + 1; j < tamanho; j++){

            comparacoes++;

            if(vetor[j] < vetor[menorIndice]){
                menorIndice = j;
            }
        }

        if(menorIndice != i){
            int auxiliar = vetor[i];
            vetor[i] = vetor[menorIndice];
            vetor[menorIndice] = auxiliar;
            trocas++;
        }
    }

    printf("\nSelection Sort:");
    printf("\nVetor ordenado: ");
    mostrarVetor(vetor, tamanho);

    printf("Comparacoes: %d\n", comparacoes);
    printf("Trocas: %d\n", trocas);
}

int main(){

    int vetor1[] = {9,8,7,6,5,4,3,2,1};
    int vetor2[] = {9,8,7,6,5,4,3,2,1};

    int tamanho = 9;

    printf("Vetor original: ");
    mostrarVetor(vetor1, tamanho);

    bubbleSort(vetor1, tamanho);
    selectionSort(vetor2, tamanho);

    return 0;
}
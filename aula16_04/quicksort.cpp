#include <stdio.h>

void trocar(int vetor[], int posicao1, int posicao2) {
    int auxiliar = vetor[posicao1];
    vetor[posicao1] = vetor[posicao2];
    vetor[posicao2] = auxiliar;
}

int particionar(int vetor[], int inicio, int fim) {
    
    int pivo = vetor[fim];         
    int posicaoMenores = inicio - 1;

    for (int atual = inicio; atual < fim; atual++) {
        
        if (vetor[atual] < pivo) {
            posicaoMenores++;
            trocar(vetor, posicaoMenores, atual);
        }
    }

  
    trocar(vetor, posicaoMenores + 1, fim);

    return posicaoMenores + 1;
}


void quickSort(int vetor[], int inicio, int fim) {
    
    if (inicio < fim) {
        
        int posicaoPivo = particionar(vetor, inicio, fim);

        
        quickSort(vetor, inicio, posicaoPivo - 1);

        
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

int main() {
    
    int vetor[] = {8, 4, 7, 3, 9, 1, 5};
    int tamanho = 7;

    printf("Vetor original:\n");
    for (int indice = 0; indice < tamanho; indice++) {
        printf("%d ", vetor[indice]);
    }

    quickSort(vetor, 0, tamanho - 1);

    printf("\n\nVetor ordenado:\n");
    for (int indice = 0; indice < tamanho; indice++) {
        printf("%d ", vetor[indice]);
    }

    return 0;
}
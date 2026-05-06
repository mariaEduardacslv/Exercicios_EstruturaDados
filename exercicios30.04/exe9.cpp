// ATIVIDADE 9 - O sistema passou um vetor já ordenado de 10 posições {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} para um Quick Sort que sempre escolhe o último elemento como pivô.
// Missão: Rode o Quick Sort e conte quantas chamadas recursivas e comparações ele faz. Você deve escrever em comentário no código: por que a "Divisão e Conquista" falhou aqui e o algoritmo virou um O(n²)?
#include <stdio.h>

int contadorComparacoes = 0;
int contadorChamadas = 0;

// troca valores
void trocar(int vetor[], int posicao1, int posicao2){
    int auxiliar = vetor[posicao1];
    vetor[posicao1] = vetor[posicao2];
    vetor[posicao2] = auxiliar;
}

// partição
int particionar(int vetor[], int inicio, int fim){

    int pivo = vetor[fim];
    int posicaoMenores = inicio - 1;

    for(int atual = inicio; atual < fim; atual++){

        contadorComparacoes++;

        if(vetor[atual] < pivo){
            posicaoMenores++;
            trocar(vetor, posicaoMenores, atual);
        }
    }

    trocar(vetor, posicaoMenores + 1, fim);

    return posicaoMenores + 1;
}

// quick sort
void quickSort(int vetor[], int inicio, int fim){

    contadorChamadas++;

    if(inicio < fim){

        int posicaoPivo = particionar(vetor, inicio, fim);

        quickSort(vetor, inicio, posicaoPivo - 1);
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

int main(){

    int vetor[] = {1,2,3,4,5,6,7,8,9,10};
    int tamanho = 10;

    quickSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\nChamadas recursivas: %d", contadorChamadas);
    printf("\nComparacoes: %d", contadorComparacoes);

    return 0;
}

/*
Por que Divisão e Conquista falhou?
A divisão falhou porque o vetor já estava em ordem
e o Quick Sort sempre escolheu o último número como pivô.
Como o último número era sempre o maior,
ele ficava no final e não separava o vetor no meio.
*/

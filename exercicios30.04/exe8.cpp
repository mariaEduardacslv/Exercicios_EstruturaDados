// ATIVIDADE 8 - O banco de dados central tem os CPFs (simplificados em 4 dígitos) desordenados: {4321, 1111, 9999, 3333, 7777, 2222, 5555}.
// Missão: Implemente o Quick Sort completo utilizando a função de partição do exercício anterior.
#include <stdio.h>

void trocar(int vetor[], int posicao1, int posicao2){
    int auxiliar = vetor[posicao1];
    vetor[posicao1] = vetor[posicao2];
    vetor[posicao2] = auxiliar;
}


int particionar(int vetor[], int inicio, int fim){

    int pivo = vetor[fim];  
    int posicaoMenores = inicio - 1;

    for(int atual = inicio; atual < fim; atual++){

        if(vetor[atual] < pivo){
            posicaoMenores++;
            trocar(vetor, posicaoMenores, atual);
        }
    }

    trocar(vetor, posicaoMenores + 1, fim);

    return posicaoMenores + 1;
}


void quickSort(int vetor[], int inicio, int fim){

    if(inicio < fim){

        int posicaoPivo = particionar(vetor, inicio, fim);

        // lado esquerdo
        quickSort(vetor, inicio, posicaoPivo - 1);

        // lado direito
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

int main(){

    int cpfs[] = {4321, 1111, 9999, 3333, 7777, 2222, 5555};
    int tamanho = 7;

    printf("CPFs antes da ordenacao:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", cpfs[i]);
    }

    quickSort(cpfs, 0, tamanho - 1);

    printf("\n\nCPFs ordenados:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d ", cpfs[i]);
    }

    return 0;
}
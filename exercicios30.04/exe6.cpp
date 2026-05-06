// ATIVIDADE 6 - O RH do Banrisul precisa ordenar as matrículas de 8 novos servidores: {44, 21, 98, 12, 55, 73, 31, 8}.
// Missão: Junte a função do exercício anterior com a função recursiva de divisão do Merge Sort. Faça o programa imprimir "Dividindo..." sempre que a função for chamada, para provar que ele quebra o vetor até chegar em tamanho 1.
#include <stdio.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    
    int esquerda = inicio;
    int direita = meio + 1;
    int posicaoAux = 0;

    int vetorAux[100];

    while(esquerda <= meio && direita <= fim) {
        
        if(vetor[esquerda] < vetor[direita]) {
            vetorAux[posicaoAux] = vetor[esquerda];
            esquerda++;
        }
        else {
            vetorAux[posicaoAux] = vetor[direita];
            direita++;
        }

        posicaoAux++;
    }

   
    while(esquerda <= meio) {
        vetorAux[posicaoAux] = vetor[esquerda];
        esquerda++;
        posicaoAux++;
    }

    
    while(direita <= fim) {
        vetorAux[posicaoAux] = vetor[direita];
        direita++;
        posicaoAux++;
    }

    for(int i = inicio, j = 0; i <= fim; i++, j++) {
        vetor[i] = vetorAux[j];
    }
}


void mergeSort(int vetor[], int inicio, int fim) {

    printf("Dividindo\n");

    if(inicio < fim) {
        
        int meio = (inicio + fim) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

int main() {

    int matriculas[] = {44, 21, 98, 12, 55, 73, 31, 8};
    int tamanho = 8;

    printf("Vetor original:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", matriculas[i]);
    }

  

    mergeSort(matriculas, 0, tamanho - 1);

    printf("\nVetor ordenado:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", matriculas[i]);
    }

    return 0;
}
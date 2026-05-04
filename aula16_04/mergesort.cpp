#include <stdio.h>

void merge(int lista[], int inicio, int meio, int fim) {
    
    int esquerda = inicio;        // percorre lado esquerdo
    int direita = meio + 1;       // percorre lado direito
    int posicaoAux = 0;

    int listaAuxiliar[100];

    // compara os elementos das duas metades
    while (esquerda <= meio && direita <= fim) {
        
        if (lista[esquerda] < lista[direita]) {
            listaAuxiliar[posicaoAux] = lista[esquerda];
            esquerda++;
        } else {
            listaAuxiliar[posicaoAux] = lista[direita];
            direita++;
        }

        posicaoAux++;
    }

    // copia o restante da esquerda
    while (esquerda <= meio) {
        listaAuxiliar[posicaoAux] = lista[esquerda];
        esquerda++;
        posicaoAux++;
    }

    // copia o restante da direita
    while (direita <= fim) {
        listaAuxiliar[posicaoAux] = lista[direita];
        direita++;
        posicaoAux++;
    }

    for (int indice = inicio, auxiliar = 0; indice <= fim; indice++, auxiliar++) {
        lista[indice] = listaAuxiliar[auxiliar];
    }
}

void mergeSort(int lista[], int inicio, int fim) {
    
    if (inicio < fim) {
        
        int meio = (inicio + fim) / 2;

        mergeSort(lista, inicio, meio);      
        mergeSort(lista, meio + 1, fim);     

        merge(lista, inicio, meio, fim);     
    }
}

int main() {
    
    int lista[] = {8, 3, 1, 7, 0, 10, 2};
    int tamanho = 7;

    printf("Lista original:\n");
    for (int posicao = 0; posicao < tamanho; posicao++) {
        printf("%d ", lista[posicao]);
    }

    mergeSort(lista, 0, tamanho - 1);

    printf("\n\nLista ordenada:\n");
    for (int posicao = 0; posicao < tamanho; posicao++) {
        printf("%d ", lista[posicao]);
    }

    return 0;
}
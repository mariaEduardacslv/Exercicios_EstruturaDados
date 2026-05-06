// ATIVIDADE 10 - Sistemas reais (como o V8 do JavaScript ou o Python) não usam um algoritmo só. Eles misturam os melhores!
// Missão: Crie uma função chamada super_sort(vetor, tamanho).
// Se o tamanho for menor que 10, ela deve chamar o Insertion Sort (porque em arrays minúsculos ele não tem overhead de recursão e é mais rápido).
// Se o tamanho for maior ou igual a 10, ela deve chamar o Quick Sort.
// Desafio extra: Teste com um vetor de 8 posições e um de 15 posições para ver a inteligência do código escolhendo o melhor caminho.

#include <stdio.h>

void insertionSort(int vetor[], int tamanho){

    for(int i = 1; i < tamanho; i++){

        int valorAtual = vetor[i];
        int posicaoAnterior = i - 1;

        while(posicaoAnterior >= 0 && vetor[posicaoAnterior] > valorAtual){
            vetor[posicaoAnterior + 1] = vetor[posicaoAnterior];
            posicaoAnterior--;
        }

        vetor[posicaoAnterior + 1] = valorAtual;
    }
}


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

        quickSort(vetor, inicio, posicaoPivo - 1);
        quickSort(vetor, posicaoPivo + 1, fim);
    }
}

void super_sort(int vetor[], int tamanho){

    if(tamanho < 10){
        printf("\nUsando Insertion Sort...\n");
        insertionSort(vetor, tamanho);
    }
    else{
        printf("\nUsando Quick Sort...\n");
        quickSort(vetor, 0, tamanho - 1);
    }
}

void mostrarVetor(int vetor[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){

    
    int vetorPequeno[] = {8, 3, 7, 1, 9, 2, 5, 4};
    int tamanhoPequeno = 8;

    
    int vetorGrande[] = {15, 2, 9, 20, 7, 11, 3, 18, 1, 14, 6, 10, 5, 8, 4};
    int tamanhoGrande = 15;

    printf("Vetor pequeno antes:\n");
    mostrarVetor(vetorPequeno, tamanhoPequeno);

    super_sort(vetorPequeno, tamanhoPequeno);

    printf("Vetor pequeno depois:\n");
    mostrarVetor(vetorPequeno, tamanhoPequeno);

    printf("\n-------------------------\n");

    printf("Vetor grande antes:\n");
    mostrarVetor(vetorGrande, tamanhoGrande);

    super_sort(vetorGrande, tamanhoGrande);

    printf("Vetor grande depois:\n");
    mostrarVetor(vetorGrande, tamanhoGrande);

    return 0;
}
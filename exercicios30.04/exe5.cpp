// ATIVIDADE 5 - A escola Norte enviou os IDs de seus alunos {20, 40, 60} e a escola Sul enviou {10, 30, 50, 70}. Ambas já estão ordenadas.
// Missão: Sem usar recursividade ainda, escreva apenas a função merge que recebe esses dois pequenos vetores e os junta em um terceiro vetor de 7 posições perfeitamente ordenado.
#include <stdio.h>

void merge(int norte[], int tamanhoNorte,
           int sul[], int tamanhoSul,
           int resultado[]) {

    int posicaoNorte = 0;
    int posicaoSul = 0;
    int posicaoResultado = 0;


    while(posicaoNorte < tamanhoNorte && posicaoSul < tamanhoSul) {

        if(norte[posicaoNorte] < sul[posicaoSul]) {
            resultado[posicaoResultado] = norte[posicaoNorte];
            posicaoNorte++;
        }
        else {
            resultado[posicaoResultado] = sul[posicaoSul];
            posicaoSul++;
        }

        posicaoResultado++;
    }

    while(posicaoNorte < tamanhoNorte) {
        resultado[posicaoResultado] = norte[posicaoNorte];
        posicaoNorte++;
        posicaoResultado++;
    }

    
    while(posicaoSul < tamanhoSul) {
        resultado[posicaoResultado] = sul[posicaoSul];
        posicaoSul++;
        posicaoResultado++;
    }
}

int main() {

    int escolaNorte[] = {20, 40, 60};
    int escolaSul[] = {10, 30, 50, 70};

    int vetorFinal[7];

    merge(escolaNorte, 3, escolaSul, 4, vetorFinal);

    printf("Vetor final ordenado:\n");

    for(int i = 0; i < 7; i++) {
        printf("%d ", vetorFinal[i]);
    }

    return 0;
}
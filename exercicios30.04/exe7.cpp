// ATIVIDADE 7 - Uma fila de subsídios com os valores: {300, 150, 800, 200, 900, 500}.
// Missão: Não faça a recursão do Quick Sort. Escolha o último elemento (500) como Pivô. Escreva apenas o laço for que joga tudo que é menor que 500 para a esquerda e o que é maior para a direita. Imprima o vetor ao final para ver o pivô no seu lugar definitivo.
#include <stdio.h>

void trocar(int vetor[], int posicao1, int posicao2){
    int auxiliar = vetor[posicao1];
    vetor[posicao1] = vetor[posicao2];
    vetor[posicao2] = auxiliar;
}

int main() {

    int subsidios[] = {300, 150, 800, 200, 900, 500};
    int tamanho = 6;

    int pivo = subsidios[tamanho - 1];
    int posicaoMenores = -1;

    
    for(int atual = 0; atual < tamanho - 1; atual++) {

        if(subsidios[atual] < pivo) {
            posicaoMenores++;
            trocar(subsidios, posicaoMenores, atual);
        }
    }

    trocar(subsidios, posicaoMenores + 1, tamanho - 1);

    printf("Vetor após partição:\n");

    for(int i = 0; i < tamanho; i++) {
        printf("%d ", subsidios[i]);
    }

    return 0;
}
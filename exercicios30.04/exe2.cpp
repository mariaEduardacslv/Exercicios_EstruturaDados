// A Secretaria de Trânsito quer ordenar os valores de 6 multas: {500, 130, 880, 195, 290, 880}. O hardware do servidor é antigo e queremos poupar a memória RAM.
// Missão: Implemente o Selection Sort. Crie uma variável contador_trocas. Incremente essa variável apenas quando o comando de troca (swap) for executado. Imprima o total no final. 
#include <stdio.h>

int main() {
    
    int multas[] = {500, 130, 880, 195, 290, 880};
    int tamanho = 6;
    
    int contador_trocas = 0;

    printf("Multas antes da ordenacao:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", multas[i]);
    }

    
    for(int posicaoAtual = 0; posicaoAtual < tamanho - 1; posicaoAtual++) {
        
        int menorIndice = posicaoAtual;

        
        for(int proximaPosicao = posicaoAtual + 1; 
            proximaPosicao < tamanho; 
            proximaPosicao++) {
            
            if(multas[proximaPosicao] < multas[menorIndice]) {
                menorIndice = proximaPosicao;
            }
        }

        
        if(menorIndice != posicaoAtual) {
            int auxiliar = multas[posicaoAtual];
            multas[posicaoAtual] = multas[menorIndice];
            multas[menorIndice] = auxiliar;

            contador_trocas++;
        }
    }

    printf("\nMultas ordenadas:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", multas[i]);
    }

    printf("\n\nTotal de trocas realizadas: %d\n", contador_trocas);

    return 0;
}


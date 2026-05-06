// O lote de pagamentos do banco chegou quase perfeito: {101, 102, 103, 104, 105, 99}. Apenas o protocolo 99 sofreu atraso de rede e caiu no final.
// Missão: Implemente o Insertion Sort com um contador de comparações (quantas vezes o if é testado). Veja como ele resolve esse problema rapidamente, "puxando" o 99 para o início e parando de comparar o resto.
#include <stdio.h>

int main() {
    
    int pagamentos[] = {101, 102, 103, 104, 105, 99};
    int tamanho = 6;
    
    int contadorComparacoes = 0;

    printf("Pagamentos antes da ordenacao:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", pagamentos[i]);
    }

   
    for(int i = 1; i < tamanho; i++) {
        
        int valorAtual = pagamentos[i];
        int posicaoAnterior = i - 1;

        while(posicaoAnterior >= 0) {
            
            contadorComparacoes++; 

            if(pagamentos[posicaoAnterior] > valorAtual) {
                pagamentos[posicaoAnterior + 1] = pagamentos[posicaoAnterior];
                posicaoAnterior--;
            } else {
                break; 
            }
        }

        pagamentos[posicaoAnterior + 1] = valorAtual;
    }

    printf("\nPagamentos ordenados:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", pagamentos[i]);
    }

    printf("\n\nTotal de comparacoes: %d\n", contadorComparacoes);

    return 0;
}
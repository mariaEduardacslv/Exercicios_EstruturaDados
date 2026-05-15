// Exercício 1 - A prefeitura precisa exibir no site todos os números de protocolo de obras que estão na fila de execução. O sistema entregou para você apenas o ponteiro head (o primeiro da fila). Escreva uma função void imprimirObras(struct No *head). Essa função deve varrer a lista encadeada do início ao fim e imprimir o número de cada protocolo na tela. A função deve parar automaticamente quando o ponteiro atingir o NULL.
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado;
    struct No *proximo;
};

void imprimirObras(struct No *head){
    //USAR OUTRA VARIÁVEL PARA PERCORRER(não modifica a corrente principal)
  struct No *atual = head;
  printf("=== PROTOCOLO OBRAS ===\n");

  while(atual != NULL) {
   printf("[PROTOCOLO: %d]->", atual->dado);
   //INDO PARA O PROXIMO
   atual = atual->proximo;
  }
  
}

int main()
{
    // SIMULANDO A CRIAÇÃO DE 3 OBRAS PARA TESTAR
    struct No *obra1 = (struct No*)malloc(sizeof(struct No));
    struct No *obra2 = (struct No*)malloc(sizeof(struct No));
    struct No *obra3 = (struct No*)malloc(sizeof(struct No));

    // INSERINDO VALORES (PAYLOAD)
    obra1->dado = 1045;
    obra2->dado = 2088;
    obra3->dado = 3012;

    //INSERINDO AS CORRENTES (proximo)
    obra1->proximo = obra2;
    obra2->proximo = obra3;
    obra3->proximo = NULL;

    //INICIO DA LISTA
    struct No *inicio_da_lista = obra1;

    //INVOCANDO CHAMADA IMPRESSÃO
    imprimirObras(inicio_da_lista);

    //BOA PRATICA   
    free(obra1);
    free(obra2);
    free(obra3);

    return 0;
}

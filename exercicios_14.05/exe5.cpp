// Um contribuinte acaba de pagar o seu IPTU atrasado. O sistema precisa remover o CPF dele da lista encadeada de Inadimplentes da prefeitura. O problema é que ele pode estar no início, no meio ou no fim da lista. Escreva a função void removerCpf(struct No head, int cpf_alvo). Para remover um nó no meio da lista, você precisará de dois ponteiros de navegação (um atual e um anterior). Quando o atual achar o CPF, a corrente do anterior deve "pular" o nó removido e se conectar ao próximo, isolando o pagador para que você possa usar o free() nele. Lembre-se de tratar o caso onde o pagador é exatamente o primeiro da fila (*head).
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado;
    struct No *proximo;
};

void removerCpf(struct No **head, int cpf_alvo)
{
   
    struct No *atual = *head;
    struct No *anterior = NULL;

    printf("=== REMOVER CPF ===\n");

    
    while (atual != NULL)
    {
        // encontrou o CPF
        if (atual->dado == cpf_alvo)
        {
            
            if (anterior == NULL)
            {
                *head = atual->proximo;
            }
            else
            {
                
                anterior->proximo = atual->proximo;
            }

            printf("CPF %d removido da lista.\n", cpf_alvo);

            
            free(atual);

            return;
        }

        
        anterior = atual;
        atual = atual->proximo;
    }

    printf("CPF nao encontrado.\n");
}

void imprimirLista(struct No *head)
{
    struct No *atual = head;

    printf("Lista de inadimplentes:\n");

    while (atual != NULL)
    {
        printf("[%d] -> ", atual->dado);

        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main()
{
    struct No *cidadao1 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao2 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao3 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao4 = (struct No*)malloc(sizeof(struct No));

  
    cidadao1->dado = 1111;
    cidadao2->dado = 2222;
    cidadao3->dado = 3333;
    cidadao4->dado = 4444;

    
    cidadao1->proximo = cidadao2;
    cidadao2->proximo = cidadao3;
    cidadao3->proximo = cidadao4;
    cidadao4->proximo = NULL;

   
    struct No *inicio_da_lista = cidadao1;

    printf("ANTES DA REMOCAO:\n");
    imprimirLista(inicio_da_lista);

   
    removerCpf(&inicio_da_lista, 3333);

    printf("\nDEPOIS DA REMOCAO:\n");
    imprimirLista(inicio_da_lista);

  
    struct No *atual = inicio_da_lista;

    while (atual != NULL)
    {
        struct No *temp = atual;

        atual = atual->proximo;

        free(temp);
    }

    return 0;
}
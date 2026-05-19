// Exercício 4 - A fila de transplantes do estado é uma lista encadeada. Um novo paciente idoso chegou e tem prioridade por lei. Ele não pode ir para o final da fila, mas também não vai ser o primeiro. Ele deve ser inserido exatamente logo após o paciente de ID 500 (que já estava na fila). Escreva uma função void inserirApos(struct No *head, int id_alvo, int novo_id). A função deve procurar o nó que contém o id_alvo (500). Quando achar, deve criar um nó para o novo_id e plugá-lo na corrente imediatamente após o alvo.
// Atenção: Cuidado com a ordem dos ponteiros! Se você plugar o alvo no novo nó antes de plugar o novo nó no restante da fila, você perde a lista inteira no Limbo da Memória (Memory Leak).
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado;
    struct No *proximo;
};

void inserirApos(struct No *head, int id_alvo, int novo_id)
{
    
    struct No *atual = head;

    printf("=== INSERIR PACIENTE ===\n");

   
    while (atual != NULL)
    {
        
        if (atual->dado == id_alvo)
        {
            
            struct No *novo = (struct No*)malloc(sizeof(struct No));

            
            novo->dado = novo_id;

            
            novo->proximo = atual->proximo;

            
            atual->proximo = novo;

            printf("Paciente %d inserido apos o ID %d\n", novo_id, id_alvo);

            return;
        }

        
        atual = atual->proximo;
    }

    printf("ID alvo nao encontrado.\n");
}

void imprimirLista(struct No *head)
{
    struct No *atual = head;

    printf("Fila: ");

    while (atual != NULL)
    {
        printf("[%d] -> ", atual->dado);

        atual = atual->proximo;
    }

    printf("NULL\n");
}

int main()
{
    struct No *paciente1 = (struct No*)malloc(sizeof(struct No));
    struct No *paciente2 = (struct No*)malloc(sizeof(struct No));
    struct No *paciente3 = (struct No*)malloc(sizeof(struct No));
    struct No *paciente4 = (struct No*)malloc(sizeof(struct No));

    
    paciente1->dado = 100;
    paciente2->dado = 300;
    paciente3->dado = 500;
    paciente4->dado = 700;

    
    paciente1->proximo = paciente2;
    paciente2->proximo = paciente3;
    paciente3->proximo = paciente4;
    paciente4->proximo = NULL;

    
    struct No *inicio_da_lista = paciente1;

    printf("ANTES DA INSERCAO:\n");
    imprimirLista(inicio_da_lista);

   
    inserirApos(inicio_da_lista, 500, 900);

    printf("\nDEPOIS DA INSERCAO:\n");
    imprimirLista(inicio_da_lista);

    free(paciente1);
    free(paciente2);
    free(paciente3);
    free(paciente4);

    return 0;
}
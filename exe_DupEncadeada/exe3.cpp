// Exercício 3 - O servidor da prefeitura andou travando e há suspeitas de que alguns nós perderam a conexão do "retrovisor", quebrando a lista dupla (Memory Leak). Escreva uma função int verificarIntegridade(struct NoDuplo *head). Ela deve varrer a lista e, para cada nó, perguntar: "O retrovisor do meu vizinho da frente aponta pra mim?" (Ou seja: atual->proximo->anterior == atual). Se toda a lista estiver perfeitamente costurada, retorne 1 (Verdadeiro). Se achar qualquer elo quebrado, retorne 0.
#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo
{
    struct NoDuplo *anterior;
    int cpf;
    struct NoDuplo *proximo;
} NoDuplo;

void inserirFim(NoDuplo **head, int cpf)
{

    NoDuplo *novo = (NoDuplo *)malloc(sizeof(NoDuplo));

    novo->cpf = cpf;
    novo->proximo = NULL;

    if (*head == NULL)
    {
        novo->anterior = NULL;
        *head = novo;
        return;
    }

    NoDuplo *atual = *head;

    while (atual->proximo != NULL)
    {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    novo->anterior = atual;
}

int verificarIntegridade(struct NoDuplo *head)
{
    NoDuplo *atual = head;

    while (atual->proximo != NULL)
    {
        if (atual->proximo->anterior != atual)
        {

            
            return 0;
        }

    
        atual = atual->proximo;
    }

    
    return 1;
}

int main()
{
    NoDuplo *servidor = NULL;

    inserirFim(&servidor, 200);
    inserirFim(&servidor, 300);
    inserirFim(&servidor, 400);
    inserirFim(&servidor, 500);
    inserirFim(&servidor, 600);
    inserirFim(&servidor, 700);
    inserirFim(&servidor, 800);

    if (verificarIntegridade(servidor)) {
        printf("Lista perfeitamente costurada\n");
    } else {
        printf("Lista corrompida!\n");
    }

    return 0;
}
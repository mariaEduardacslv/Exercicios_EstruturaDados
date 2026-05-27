// Exercício 5 - Um contribuinte pagou o IPTU e precisa sair da fila de devedores. Na Lista Simples, tínhamos que varrer a lista arrastando um ponteiro anterior para consertar o buraco deixado. Agora, o próprio nó sabe quem está atrás dele! Escreva a função void removerCpf(struct NoDuplo head, int cpf_alvo). Você deve usar apenas um ponteiro de caminhada (atual). Quando achar o alvo, o próprio nó alvo avisa seus vizinhos para darem as mãos (atual->anterior->proximo = atual->proximo e vice-versa), isolando-o da fila antes de você aplicar o free(atual).
#include <stdio.h>
#include <stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;
    int cpf;
    struct NoDuplo *proximo;
} NoDuplo;

void inserirFim(NoDuplo **head, int cpf) {

    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));

    novo->cpf = cpf;
    novo->proximo = NULL;

    if (*head == NULL) {
        novo->anterior = NULL;
        *head = novo;
        return;
    }

    NoDuplo *atual = *head;

    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
    novo->anterior = atual;
}


void imprimirLista(NoDuplo *head) {

    NoDuplo *atual = head;

    while (atual != NULL) {
        printf("[ %d ] ", atual->cpf);
        atual = atual->proximo;
    }

    printf("\n");
}


void removerCpf(NoDuplo **head, int cpf_alvo) {

    NoDuplo *atual = *head;

    while (atual != NULL && atual->cpf != cpf_alvo) {
        atual = atual->proximo;
    }

   
    if (atual == NULL) {
        printf("CPF nao encontrado!\n");
        return;
    }

    //é o primeiro?
    if (atual->anterior == NULL) {

        *head = atual->proximo;

        if (atual->proximo != NULL) {
            atual->proximo->anterior = NULL;
        }

        free(atual);
        return;
    }


    atual->anterior->proximo = atual->proximo;

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }

    free(atual);
}


int main() {

    NoDuplo *fila = NULL;

  
    inserirFim(&fila, 300);
    inserirFim(&fila, 500);
    inserirFim(&fila, 800);
    inserirFim(&fila, 900);

    printf("Lista inicial:\n");
    imprimirLista(fila);

   
    removerCpf(&fila, 500);

    printf("Depois de remover 500:\n");
    imprimirLista(fila);

   
    removerCpf(&fila, 300);

    printf("Depois de remover 300:\n");
    imprimirLista(fila);

    return 0;
}
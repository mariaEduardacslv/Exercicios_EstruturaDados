// Exercício 4 - Na Lista Simples, inserir um nó antes de um alvo era um pesadelo (exigia um ponteiro auxiliar correndo atrás). Na Lista Dupla, é fácil! Um paciente grave chegou e precisa ser inserido exatamente antes do paciente com ID 500. Escreva void inserirAntes(struct NoDuplo head, int id_alvo, int novo_id). Encontre o id_alvo. Crie o novo nó e faça a amarração dos 4 ponteiros para que ele entre antes do alvo. Atenção: Os alunos devem lembrar de atualizar o head caso o id_alvo seja o primeiro da fila!
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


void inserirAntes(NoDuplo **head, int id_alvo, int novo_id) {

    NoDuplo *atual = *head;

    while (atual != NULL && atual->cpf != id_alvo) {
        atual = atual->proximo;
    }

    
    if (atual == NULL) {
        printf("ID nao encontrado!\n");
        return;
    }

   
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));

    novo->cpf = novo_id;

    //é o primeiro?
    if (atual->anterior == NULL) {

        novo->anterior = NULL;
        novo->proximo = atual;

        atual->anterior = novo;

        *head = novo;

        return;
    }


    // novo aponta para frente
    novo->proximo = atual;

    // novo aponta para trás
    novo->anterior = atual->anterior;

    // quem estava atrás do alvo aponta para o novo
    atual->anterior->proximo = novo;

    // alvo aponta para trás para o novo
    atual->anterior = novo;
}


int main() {

    NoDuplo *fila = NULL;

    inserirFim(&fila, 300);
    inserirFim(&fila, 500);
    inserirFim(&fila, 800);

    printf("Lista antes:\n");
    imprimirLista(fila);

    inserirAntes(&fila, 500, 450);

    printf("Lista depois:\n");
    imprimirLista(fila);

    return 0;
}
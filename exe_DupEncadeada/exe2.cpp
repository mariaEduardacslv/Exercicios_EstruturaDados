// Exercício 2 - No CRAS, quando o atendente busca um CPF, o sistema agora precisa mostrar quem está aguardando antes e depois dessa pessoa na fila para evitar fraudes. Escreva void buscarComVizinhos(struct NoDuplo *head, int cpf_alvo). A função deve encontrar o nó alvo e imprimir: "O cidadão [X] está na fila. Na frente dele está o [Y] e atrás dele está o [Z]".
#include<stdio.h>
#include<stdlib.h>

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

void buscarComVizinhos(NoDuplo *head, int cpf_alvo) {

    NoDuplo *atual = head;

    
    while (atual != NULL && atual->cpf != cpf_alvo) {
        atual = atual->proximo;
    }

    
    if (atual == NULL) {
        printf("CPF nao encontrado\n");
        return;
    }

    printf("O cidadao [%d] esta na fila.\n", atual->cpf);

    
    if (atual->proximo != NULL) {
        printf("Na frente dele esta o [%d]\n", atual->proximo->cpf);
    } else {
        printf("Nao tem ninguem na frente dele.\n");
    }

    
    if (atual->anterior != NULL) {
        printf("Atras dele esta o [%d]\n", atual->anterior->cpf);
    } else {
        printf("Nao tem ninguem atras dele.\n");
    }
}


int main() {
    NoDuplo *fila_cras = NULL;

     
    inserirFim(&fila_cras, 300);
    inserirFim(&fila_cras, 500);
    inserirFim(&fila_cras, 800);
    inserirFim(&fila_cras, 900);


    buscarComVizinhos(fila_cras,500);

    return 0;
}
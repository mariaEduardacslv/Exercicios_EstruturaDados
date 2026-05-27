// A prefeitura quer provar que o sistema é transparente e permite auditoria de trás para frente. Você recebeu o ponteiro head da fila de obras. Escreva a função void imprimirIdaEVolta(struct NoDuplo *head). Você deve varrer a fila usando o proximo até chegar ao último nó, imprimindo os valores. Quando bater no último nó (aquele cujo próximo é NULL), você não deve parar. Use o ponteiro anterior para voltar dando "marcha à ré" até o início, imprimindo os valores novamente.
#include<stdio.h>
#include<stdlib.h>

typedef struct NoDuplo {
    struct NoDuplo *anterior;  
    int cpf;                  
    struct NoDuplo *proximo;   
} NoDuplo;

void inserirFim(NoDuplo **head, int cpf){

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

void imprimirIdaEVolta(NoDuplo *head) {
    if (head == NULL) {
        printf("Fila vazia!\n\n");
        return;
    }

    NoDuplo *atual = head;
    NoDuplo *ultimo = NULL;

    printf("\n--- NAVEGANDO PARA FRENTE (Head -> Tail) ---\n");
    
    while (atual != NULL) {
        printf("[ %d ]", atual->cpf);
        if (atual->proximo != NULL) printf(" <==> ");
        
        ultimo = atual; 
        atual = atual->proximo;
    }
    
     printf("\n--- DANDO MARCHA A RE (Tail -> Head) -----\n");
   
    while (ultimo != NULL) {
        printf("[ %d ]", ultimo->cpf);
        if (ultimo->anterior != NULL) printf(" <==> ");
        
        ultimo = ultimo->anterior; 
    }
    printf("\n");
}
int main() {
    NoDuplo *fila_obras = NULL;

     
    inserirFim(&fila_obras, 300);
    inserirFim(&fila_obras, 500);
    inserirFim(&fila_obras, 800);
    inserirFim(&fila_obras, 900);


    imprimirIdaEVolta(fila_obras);

    return 0;
}
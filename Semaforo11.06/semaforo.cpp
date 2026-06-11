#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Semaforo {
    char via[50];
    char status[10]; // VERDE ou VERMELHO
    struct Semaforo *proximo; // prox semaforo
} Semaforo;

// Insere uma via na lista circular
void inserirVia(Semaforo **head, char nome[]) {
    Semaforo *novo = (Semaforo *)malloc(sizeof(Semaforo));

    strcpy(novo->via, nome);
    strcpy(novo->status, "VERMELHO");

    // Primeiro nó
    if (*head == NULL) { //primeiro nó da lista aponta p ele mesmo
        *head = novo;   
        novo->proximo = novo; 
        return;
    }

    // Encontrar último nó
    Semaforo *aux = *head; 
    while (aux->proximo != *head) {
        aux = aux->proximo;   
    }

    aux->proximo = novo;
    novo->proximo = *head; // fecha o circulo 
}

// Atualiza status: apenas um verde por vez
void atualizarStatus(Semaforo *head, Semaforo *verde) {
    Semaforo *aux = head;

    do {
        if (aux == verde)
            strcpy(aux->status, "VERDE");
        else
            strcpy(aux->status, "VERMELHO");

        aux = aux->proximo;
    } while (aux != head);
}

// Avança o semáforo
Semaforo *avancarSemaforo(Semaforo *atual) {
    return atual->proximo;
}

// Mostra todos os semáforos
void mostrarStatus(Semaforo *head) {
    Semaforo *aux = head;

    printf("\nSTATUS DOS SEMAFOROS:\n");

    do {
        printf("[%s] %s\n", aux->status, aux->via);
        aux = aux->proximo;
    } while (aux != head);

    printf("=========================================\n");
}

int main() {
    Semaforo *rotatoria = NULL;

    // Inserção das 4 vias
    inserirVia(&rotatoria, "Avenida Principal");
    inserirVia(&rotatoria, "Rua Norte");
    inserirVia(&rotatoria, "Rua Sul");
    inserirVia(&rotatoria, "Rua Leste");

    // Primeiro semáforo verde
    Semaforo *verde = rotatoria;

    atualizarStatus(rotatoria, verde);

    int opcao;

    do {
        mostrarStatus(rotatoria);

        printf("\nPressione 1 para avancar o semaforo\n");
        printf("Pressione 0 para sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            verde = avancarSemaforo(verde);
            atualizarStatus(rotatoria, verde);
        }

    } while (opcao != 0);

    return 0;
}

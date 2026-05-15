// Exercício 2 - A Secretaria de Educação tem uma lista encadeada de alunos aguardando vaga em creches. O prefeito perguntou: "Quantas crianças estão na fila hoje?". Escreva uma função int contarFila(struct No *head). (Você não pode usar variáveis globais). A função deve percorrer a lista encadeada, contar quantos nós existem e retornar esse valor inteiro.
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado;
    struct No *proximo;
};

int contarFila(struct No *head)
{
    // percorre a lista
    struct No *atual = head;
    int contador = 0;

    while (atual != NULL)
    {
        contador++;

    
        atual = atual->proximo;
    }
    return contador;
}

int main()
{

    struct No *aluno1 = (struct No *)malloc(sizeof(struct No));
    struct No *aluno2 = (struct No *)malloc(sizeof(struct No));
    struct No *aluno3 = (struct No *)malloc(sizeof(struct No));
    struct No *aluno4 = (struct No *)malloc(sizeof(struct No));

   

    // INSERINDO AS CORRENTES (proximo)
    aluno1->proximo = aluno2;
    aluno2->proximo = aluno3;
    aluno3->proximo = aluno4;
    aluno4->proximo = NULL;

    // INICIO DA LISTA
    struct No *inicio_da_lista = aluno1;

    int quantidade = contarFila(inicio_da_lista); //a função é executada e valor retornado é guardado em quantidade

    printf("Quantidade de nós (alunos): %d\n", quantidade); 

    // BOA PRATICA
    free(aluno1);
    free(aluno2);
    free(aluno3);
    free(aluno4);

    return 0;
}
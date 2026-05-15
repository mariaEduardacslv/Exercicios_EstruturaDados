// Exercício 3 - Um cidadão ligou para o CRAS perguntando se o CPF dele está na lista de aprovados para receber a cesta básica. Escreva uma função int buscarCidadão(struct No *head, int cpf_buscado). A função deve percorrer a lista. Se encontrar o CPF, retorna 1 (Verdadeiro). Se percorrer a lista inteira e chegar ao NULL sem encontrar, retorna 0 (Falso).
#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado;
    struct No *proximo;
};

int buscarCidadao( struct No *head, int cpf_buscado){
   struct No *atual = head;
  printf("=== BUSCAR CIDADÃO ===\n");

  while (atual != NULL)
    {
        if (atual->dado == cpf_buscado)
        {
            return 1; 
        }

        atual = atual->proximo;
    }

    return 0; 
}

int main()
{
    
    struct No *cidadao1 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao2 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao3 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao4 = (struct No*)malloc(sizeof(struct No));
    struct No *cidadao5 = (struct No*)malloc(sizeof(struct No));

    // INSERINDO VALORES (PAYLOAD)
    cidadao1->dado = 1234;
    cidadao2->dado = 5678;
    cidadao3->dado = 8901;
    cidadao4->dado = 3469;
    cidadao5->dado = 7024;

    //INSERINDO AS CORRENTES (proximo)
    cidadao1->proximo = cidadao2;
    cidadao2->proximo = cidadao3;
    cidadao3->proximo = cidadao4;
    cidadao4->proximo = cidadao5;
    cidadao5->proximo = NULL;

    //INICIO DA LISTA
    struct No *inicio_da_lista = cidadao1;

  
     int cpf = 8901;

    int resultado = buscarCidadao(inicio_da_lista, cpf);

    if (resultado == 1)
        printf("CPF encontrado\n");
    else
        printf("CPF nao encontrado\n");

      
    free(cidadao1);
    free(cidadao2);
    free(cidadao3);
    free(cidadao4);
    free(cidadao5);


    return 0;
}
#include<stdio.h>
#include<string.h>

struct Processo{
   int numeroProtocolo;
   int status; // 0 = Em análise, 1 = Deferido, 2 = Indeferido
};

void atualizarStatus(struct Processo *p, int novoStatus) {
    p->status = novoStatus;  //-> acessa o campo da struct através do ponteiro.
}

void imprimirStatus( Processo p) 
{
    printf("Protocolo: %d\n", p.numeroProtocolo);
    
    if (p.status == 0)
        printf("Status: Em analise\n");
    else if (p.status == 1)
        printf("Status: Deferido\n");
    else if (p.status == 2)
        printf("Status: Indeferido\n");
    else
        printf("Status: Desconhecido\n");
}

int main()
{
    struct Processo processo;  //Cria uma variável chamada processo do tipo struct Processo, armazenada na stack
    processo.numeroProtocolo = 1234;
    processo.status = 0;

    printf("antes da atualizacao:\n");
    imprimirStatus(processo);

    // Alterando o status para 1 (Deferido)
    atualizarStatus(&processo, 1); //&processo → envia o endereço de memória.

    printf("\ndepois da atualizacao:");
    
    imprimirStatus(processo);

    
}


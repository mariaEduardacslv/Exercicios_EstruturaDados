#include<stdio.h>
#include<string.h>

struct GuiaArrecadacao{
    int numero_documento;
    float valor;
    char status; // P para pago e A para aberto
};

int main()

{
    struct GuiaArrecadacao guias[3];
    int i;

    for(i=0;i<3;i++)
    {
        printf("digite o numero do documento: ");
        scanf("%d",&guias[i].numero_documento);

        printf("digite o valor: ");
        scanf("%f",&guias[i].valor);

        printf("Status (P= PAGO / A= ABERTO): ");
        scanf(" %s",&guias[i].status);
    }
    
}
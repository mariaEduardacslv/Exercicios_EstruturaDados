#include<stdio.h>
#include<string.h>

struct Cidadao
{
int id;
char nome[50];
int idade;
};

 void imprimirCidadao(Cidadao c) {
    printf("id: %d\n", c.id);
    printf("Nome: %s\n", c.nome);
    printf("Idade: %d\n", c.idade);
   
 }

int main()
    {
     struct Cidadao c;

     printf("Digite o id: ");
     scanf("%d", &c.id);

     printf("Digite o nome: ");
     scanf("%s", &c.nome);

     printf("Digite a idade: ");
     scanf("%d",&c.idade);
     
     imprimirCidadao(c);

    }


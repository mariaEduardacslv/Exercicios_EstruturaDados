#include <stdio.h>

int main()
{
    int array[] = {33, 11, 22, 77, 120, 66, 55, 110, 99, 88};
    int tamanho = 10;
    int i, j, menor, aux;

    for(i = 0; i < tamanho - 1; i++)
    {
        menor = i;

        for(j = i + 1; j < tamanho; j++)
        {
            if(array[j] < array[menor])
            {
                menor = j;
            }
        }

        
        aux = array[i];
        array[i] = array[menor];
        array[menor] = aux;
    }

    printf("\narray atualizado é:\n");
    for(i = 0; i < tamanho; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
} 

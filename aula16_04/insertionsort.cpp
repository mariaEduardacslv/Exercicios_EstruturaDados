#include <stdio.h>

int main()
{
    int array[] = {33, 11, 22, 77, 120, 66, 55, 110, 99, 88};
    int tamanho = 10;
    int i, j, x;

    for(i = 1; i < tamanho; i++)
    {
        x = array[i];
        j = i - 1;

        while(j >= 0 && array[j] > x)
        {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = x;
    }
    printf("\narray atualizado é: ");
    for(i = 0; i < tamanho; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
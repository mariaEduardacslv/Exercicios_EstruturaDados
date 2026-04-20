#include<stdio.h>
int main()
{
    int array[] = {33, 11, 22, 77, 120, 66, 55, 110, 99, 88};
    int i, j; 
    int tamanho = 10;
    int aux = 0;

    for(i=0;i<tamanho-1; i++)
    {
     for(int j=0;j<tamanho-1;j++)
     {
       if(array[j] > array[j+1])
       {
        aux = array[j];
        array[j] = array[j+1];
        array[j+1] = aux;
       }
     }
    }
     printf("\array atualizado é: ");
     for(int i=0 ; i<tamanho; i++)
     {
        printf("\n%d",array[i]);
     }
     

}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tamanho 2

void preencher (int vetor[])
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand()%tamanho;
    }
}

void buscaSequencial (int vetor[], int buscado)
{
    int status = 0;
    
    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == buscado)
        {
            status = 1;
        }
    }
    
    if (status == 0)
    {
        printf ("Número [%i] não encontrado!\n", buscado);
    }
    else
    {
        printf ("Número [%i] encontrado!\n", buscado);
    }
}

void buscaBinaria (int vetor[], int buscado, int inicio, int fim)
{
    if (fim < inicio)
    {
        printf ("Número [%i] não foi encontrado!.\n", buscado);
    }
    
    int meio = inicio + ((inicio + fim)/2);
    
    if (vetor[meio] < buscado)
    {
        buscaBinaria (vetor, buscado, meio + 1, tamanho);
    }
    else if (vetor[meio] > buscado)
    {
        buscaBinaria (vetor, buscado, 0, meio - 1);
    }
    else
    {
        printf ("Número [%i] encontrado!\n", buscado);
    }
}

void mostrar (int vetor[])
{
    printf ("[");
    
    for (int i = 0; i < tamanho; i++)
    {
        printf (" %i ", vetor[i]);
    }
    
    printf ("]\n");
}

void bubbleSort (int vetor[])
{
    int aux;
    
    for (int i = tamanho - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void main()
{
    int vetor[100];
    int buscado;
    
    preencher (vetor);
    
    bubbleSort (vetor);
    
    mostrar (vetor);
    
    printf ("Digite um número para buscar: ");
    scanf ("%i", &buscado);
    
    buscaSequencial (vetor, buscado);
    
    buscaBinaria (vetor, buscado, 0, tamanho);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define tamanho 100

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
        printf ("Número [%i] não encontrado! (Busca sequencial)\n", buscado);
    }
    else
    {
        printf ("Número [%i] encontrado! (Busca sequencial)\n", buscado);
    }
}

int buscaBinariaRec(int vetor[], int inicio, int fim, int buscado)
{
    if (fim < inicio)
    {
        printf ("Número [%i] não encontrado! (Busca binaria recursiva)\n", buscado);
        return -1;
    }
    
    int meio = inicio + (fim - inicio)/2;
    
    if (buscado < vetor[meio])
    {
        return buscaBinariaRec(vetor, inicio, meio-1, buscado);
    }
    else if (buscado > vetor[meio])
    {
        return buscaBinariaRec(vetor, meio+1, fim, buscado);
    }
    else
    {
        printf ("Número [%i] encontrado! (Busca binaria recursiva)\n", buscado);
        return meio;
    }
}


int buscaBinariaIte(int vetor[], int inicio, int fim, int buscado)
{
    int meio;
    
    while (inicio <= fim)
    {
        meio = inicio + (fim - inicio)/2;
        
        if (buscado > vetor[meio])
        {
            inicio = meio + 1;
        }
        else if (buscado < vetor[meio])
        {
            fim = meio - 1;
        }
        else
        {
            printf ("Número [%i] encontrado! (Busca binaria iterativa)\n", buscado);
            return meio;
        }
    }
    
    printf ("Número [%i] não encontrado! (Busca binaria iterativa)\n", buscado);
    return -1;
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
    int binaryStatus;
    
    preencher (vetor);
    
    bubbleSort (vetor);
    
    mostrar (vetor);
    
    printf ("Digite um número para buscar: ");
    scanf ("%i", &buscado);
    
    binaryStatus = buscaBinariaIte (vetor, 0, tamanho - 1, buscado);
    
    binaryStatus = buscaBinariaRec (vetor, 0, tamanho - 1, buscado);
    
    buscaSequencial (vetor, buscado);
    
}

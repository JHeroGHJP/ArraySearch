#include <stdio.h>
#include <stdlib.h>

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
        printf ("Número [%i] não encontrado!\n", buscado);
    }
    else
    {
        printf ("Número [%i] encontrado!\n", buscado);
    }
}

void main()
{
    int vetor[100];
    int buscado;
    
    preencher (vetor);
    
    printf ("Digite um número para buscar: ");
    scanf ("%i", &buscado);
    
    buscaSequencial (vetor, buscado);
}

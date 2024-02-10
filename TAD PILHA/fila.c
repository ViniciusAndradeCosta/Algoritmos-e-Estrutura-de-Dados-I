#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fila.h"

void FFVazia(TFila *Fila)
{
    Fila->frente = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int FVazia(TFila Fila)
{
    return(Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item)
{
    TCelula* aux;
    if(!FVazia(*Fila))
    {
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if(Fila->frente->prox = NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

void ImprimirFila(TFila *Fila)
{
    TProduto x;
    TFila F2;
    FFVazia(&F2);

    while(!FVazia(*Fila))
    {
        Desenfileirar(Fila,&x);
        ImprimirProduto(x);
        Enfileirar(x,&F2);
    }

    while(!FVazia(F2))
    {
        Desenfileirar(&F2,&x);
        Enfileirar(x,Fila);
    }

    free(F2.frente);

}

TProduto PesquisarFila(TFila *Fila, TProduto Item)
{
    TProduto x;
    TProduto y;
    y.codigo = -1;
    int TAM = Fila->tamanho;
    for(int i = 0; i < TAM; i++)
    {
        Desenfileirar(Fila,&x);
        if(x.codigo == Item.codigo)
        {
            ImprimirProduto(x);
            y = x;
        }
        Enfileirar(x, Fila);
    }
    if(y.codigo == -1)
        printf("O PRODUTO NÃO FOI ENCONTRADO! VALOR -1 RETORNADO!\n");
    return y;
}

TProduto PesquisarPorNome(TFila *Fila, TProduto Item)
{
    TProduto x;
    TProduto y;
    y.codigo = -1;
    int tam = Fila->tamanho;
    for(int i = 0; i < tam; i++)
    {
        Desenfileirar(Fila, &x);
        if(strcmp(x.nome, Item.nome) == 0)
        {
            ImprimirProduto(x);
            y = x;
        }
        Enfileirar(x, Fila);
    }
    if(y.codigo == -1)
        printf("O PRODUTO NÃO FOI ENCONTRADO!\n");
    return y;
}

void LiberarFila(TFila *Fila)
{
    TProduto x;
    while(!FVazia(*Fila))
    {
        Desenfileirar(Fila, &x);
    }
    free(Fila->frente);
}

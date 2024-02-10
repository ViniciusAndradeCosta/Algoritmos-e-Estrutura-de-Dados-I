#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

typedef struct fila
{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);

int FVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TFila *Fila, TProduto *Item);

void ImprimirFila(TFila *Fila);

TProduto PesquisarFila(TFila *Fila, TProduto x);

TProduto PesquisarFilaPorNome(TFila *Fila, TProduto x);

void LiberarFila(TFila *Fila);

#endif // UTIL_H_INCLUDED


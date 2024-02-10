# ifndef FILA_H_INCLUDED
# define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char nome[50];
    char descricao[250];
    int quantidade;
    float preco;
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct
{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;

void FFVazia(TFila* Fila);

int FVazia(TFila Fila);

void Enfileirar(TProduto x, TFila *Fila);

void Desenfileirar(TProduto *Item, TFila *Fila);

void ImprimirFila(TFila *Fila);

TProduto PesquisarFila(TFila *Fila, TProduto Item);

void LerProduto(TProduto* produto);

void LerNome(TProduto* produto);

void LerCodigo(TProduto* produto);

void ImprimirProduto(TProduto produto);

void LiberarFila(TFila* Fila);

TProduto PesquisarPorNome(TFila *Fila, TProduto Item);

int Comparar(TFila *Fila1, TFila *Fila2);

void Remover(TFila *Fila, int termo);

void Intercessao(TFila *Fila1, TFila *Fila2, TFila *Fila3);

int VerificarElemento(TFila *Fila, TProduto Item);

void Subtracao(TFila *Fila1, TFila *Fila2, TFila *Fila3);

# endif // FILA_H_INCLUDED


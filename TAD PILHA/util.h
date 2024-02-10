# ifndef UTIL_H_INCLUDED
# define UTIL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char nome[50];
    char descricao[150];
    int quantidade;
    float preco;

} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;

} TCelula;

void ImprimirProduto(TProduto x);

void LerNome(TProduto* produto);

void LerCodigo(TProduto* produto);

void LerProduto(TProduto* produto);


# endif

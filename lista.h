#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int quantidade;
    char descricao[200];
    float valor;
    char nome[200];
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula* prox;
}TCelula;

typedef struct {
    TCelula* primeiro;
    TCelula* ultimo;
    int tamanho;
}TLista;

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void FLVazia(TLista *Lista);

int Vazia(TLista Lista);

void Inserir(TProduto x, TLista *Lista);

void ImprimirLista(TLista Lista);

TCelula* PesquisarPorNome(TLista Lista, TProduto Item);

TCelula* Pesquisar(TLista Lista, TProduto Item);

void Excluir(TLista *Lista, TProduto *Item);

TCelula* PesquisarNome(TLista Lista, TProduto Item);

void Atualizar(TLista *Lista, TProduto Item);

void InserirCrescente(TProduto produto, TLista *lista);

void Iguais(TLista *Lista, TLista *Lista2);

void ConcatenaListas(TLista *Lista, TLista *Lista2);

void LiberarLista(TLista *Lista);

void LerProduto(TProduto *Item);

void ImprimirProduto(TProduto Item);

#endif // LISTA_H

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "fila.h"
#include "util.h"

typedef struct{
    TCelula* fundo;
    TCelula* topo;
    int tamanho;
}TPilha;

void FPVazia(TPilha *Pilha);

int PVazia(TPilha Pilha);

void Empilhar(TProduto x, TPilha *Pilha);

void Desempilhar(TPilha *Pilha, TProduto *Item);

void LiberarPilha(TPilha *Pilha);

void ImprimirPilha(TPilha *Pilha);

void PilhaPesquisar(TPilha *Pilha, TProduto x);

void PesquisarPorNomePilha(TPilha *Pilha, TProduto Item);

void InverterElementosUsandoFila(TPilha *pilha);

void InverterElementosUsandoDuasPilhas(TPilha *pilha);

void InverterPilhaComVariaveis(TPilha* Pilha);

void ExpressaoAritmetica(char expressao[]);

int ObterPrioridade(char operador);

void TranformarDeInfixadaParaPosInfixada(char expressao[]);

#endif // PILHA_H_INCLUDED

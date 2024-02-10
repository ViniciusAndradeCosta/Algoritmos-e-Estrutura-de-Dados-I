#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "pilha.h"
#include "fila.h"

void FPVazia(TPilha *Pilha)
{
    Pilha->topo = (TCelula*) malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int PVazia(TPilha Pilha)
{
    return(Pilha.topo == Pilha.fundo);
}

void Empilhar(TProduto x, TPilha *Pilha)
{
    TCelula* Aux;
    Aux = (TCelula*) malloc(sizeof(TCelula));
    Pilha->topo->item = x;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilhar(TPilha *Pilha, TProduto *Item)
{
    TCelula* q;
    if(PVazia(*Pilha))
    {
        printf("ERRO DETECTADO: LISTA VAZIA\n");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}

void LiberarPilha(TPilha *Pilha)
{
    TProduto x;
    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha, &x);
    }
    free(Pilha->topo);
}

void ImprimirPilha(TPilha *Pilha)
{
    TPilha P2;
    FPVazia(&P2);
    TProduto x;

    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        Empilhar(x,&P2);
    }

    while(!PVazia(P2))
    {
        Desempilhar(&P2,&x);
        ImprimirProduto(x);
        Empilhar(x,Pilha);
    }

    free(P2.topo);

}

void PilhaPesquisar(TPilha *Pilha, TProduto produto)
{
    TPilha P2;
    FPVazia (&P2);
    TProduto x;
    TProduto y;
    y.codigo = -1;

    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        if(x.codigo == produto.codigo)
        {
            y = x;
            ImprimirProduto(y);
        }
        Empilhar(x,&P2);
    }
    while(!PVazia (P2))
    {
        Desempilhar(&P2,&x);
        Empilhar(x,Pilha);
    }
    free(P2.topo);
    if(y.codigo == -1)
        printf("O PRODUTO NÃO FOI ENCONTRADO! VALOR -1 RETORNADO!\n");
}

void PesquisarPorNomePilha(TPilha *Pilha, TProduto produto)
{
    TPilha P2;
    FPVazia (&P2);
    TProduto x;
    TProduto y;
    y.codigo = -1;

    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        if(strcmp(produto.nome, x.nome) == 0)
        {
            y = x;
            ImprimirProduto(y);
        }
        Empilhar(x,&P2);
    }
    while(!PVazia (P2))
    {
        Desempilhar(&P2,&x);
        Empilhar(x,Pilha);
    }
    free(P2.topo);
    if(y.codigo == -1)
        printf("O PRODUTO NÃO FOI ENCONTRADO! VALOR -1 RETORNADO!\n");
}

void InverterElementosUsandoFila(TPilha *Pilha)
{
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto x;


    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        Enfileirar(x,&FilaAux);
    }
    while(!FVazia(FilaAux))
    {
        Desenfileirar(&FilaAux,&x);
        Empilhar(x,Pilha);
    }
    printf("A PILHA FOI INVERTIDA COM SUCESSO!\n");
}

void InverterElementosUsandoDuasPilhas(TPilha *Pilha)
{
    TPilha P1;
    FPVazia(&P1);
    TPilha P2;
    FPVazia(&P2);
    TProduto x;

    while(!PVazia(*Pilha))
    {
        Desempilhar(Pilha,&x);
        Empilhar(x,&P1);
    }
    while(!PVazia(P1))
    {
        Desempilhar(&P1,&x);
        Empilhar(x,&P2);
    }
    while(!PVazia(P2))
    {
        Desempilhar(&P2,&x);
        Empilhar(x,Pilha);
    }
    free(P1.topo);
    free(P2.topo);
    printf("A PILHA FOI INVERTIDA COM SUCESSO!\n");
}

void InverterPilhaComVariaveis(TPilha* Pilha)
{
    TPilha PilhaAux;
    FPVazia(&PilhaAux);

    while (!PVazia(*Pilha))
    {
        TProduto produto;
        Desempilhar(Pilha, &produto);
        Empilhar(produto, &PilhaAux);
    }

    Pilha->topo = PilhaAux.topo;
    Pilha->fundo = PilhaAux.fundo;
    Pilha->tamanho = PilhaAux.tamanho;

    FPVazia(&PilhaAux);
    LiberarPilha(&PilhaAux);
    printf("A PILHA FOI INVERTIDA COM SUCESSO!\n");
}

void ExpressaoAritmetica(char expressao[])
{
    TPilha Pilha;
    FPVazia(&Pilha);
    TProduto x;
    char caractere;

    for (int i = 0; expressao[i] != '\0'; i++)
    {
        caractere = expressao[i];

        if (caractere == '(' || caractere == '[' || caractere == '{')
        {
            x.nome[0] = caractere;
            Empilhar(x,&Pilha);
        }
        else if (caractere == ')' || caractere == ']' || caractere == '}')
        {
            if (PVazia(Pilha))
            {
                printf("ERRO: EXPRESSÃO INCORRETA!\n");
                return;
            }

            char topoPilha = Pilha.topo->prox->item.nome[0];

            if ((caractere == ')' && topoPilha == '(') ||
                    (caractere == ']' && topoPilha == '[') ||
                    (caractere == '}' && topoPilha == '{'))
            {
                Desempilhar(&Pilha, &x);
            }
            else
            {
                printf("ERRO: EXPRESSÃO INCORRETA!\n");
                return;
            }
        }
    }

    if (PVazia(Pilha))
    {
        printf("ERRO: EXPRESSÃO INCORRETA!\n");
    }
    else
    {
        printf("ERRO: EXPRESSÃO INCORRETA!\n");
    }

    free(Pilha.topo);
}

int ObterPrioridade(char operador)
{
    if (operador == '*' || operador == '/')
    {
        return 2;
    }
    else if (operador == '+' || operador == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void TranformarDeInfixadaParaPosInfixada(char expressao[])
{
    TPilha Pilha;
    FPVazia(&Pilha);
    TProduto x;
    char posfix[100];
    int pos_posfix = 0;

    for (int i = 0; expressao[i] != '\0'; i++)
    {
        char caractere = expressao[i];

        if (caractere == '(')
        {
            x.nome[0] = caractere;
            Empilhar(x, &Pilha);
        }
        else if (caractere == ')')
        {
            while (!PVazia(Pilha) && Pilha.topo->prox->item.nome[0] != '(')
            {
                Desempilhar(&Pilha, &x);
                posfix[pos_posfix++] = x.nome[0];
            }
            Desempilhar(&Pilha, &x);
        }
        else if (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '/')
        {
            while (!PVazia(Pilha) && ObterPrioridade(Pilha.topo->prox->item.nome[0]) >= ObterPrioridade(caractere))
            {
                Desempilhar(&Pilha, &x);
                posfix[pos_posfix++] = x.nome[0];
            }
            x.nome[0] = caractere;
            Empilhar(x, &Pilha);
        }
        else if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= '0' && caractere <= '9'))
        {
            posfix[pos_posfix++] = caractere;
        }
    }

    while (!PVazia(Pilha))
    {
        Desempilhar(&Pilha, &x);
        posfix[pos_posfix++] = x.nome[0];
    }

    posfix[pos_posfix] = '\0';
    printf("EXPRESSÃO PÓS-FIXADA: %s\n", posfix);
    free(Pilha.topo);
}

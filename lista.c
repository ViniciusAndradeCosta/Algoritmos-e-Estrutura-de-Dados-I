#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista.h"

void FLVazia(TLista *Lista)
{
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

int Vazia(TLista Lista)
{
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista)
{
    Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> ultimo ->prox;
    Lista -> ultimo -> item = x;
    Lista -> ultimo -> prox = NULL;
    Lista -> tamanho++;
}

void ImprimirLista(TLista Lista)
{
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;

    while (Aux != NULL)
    {
        printf("\n---------------------\n");
        printf("\nNome: %s", Aux -> item.nome);
        printf("\nCodigo:%d", Aux -> item.codigo);
        printf("\nQuantidade: %d", Aux -> item.quantidade);
        printf("\nValor: %.2f", Aux -> item.valor);
        printf("\nDescricao: %s\n", Aux -> item.descricao);
        Aux= Aux -> prox;
    }
}

TCelula* PesquisarPorNome(TLista Lista, TProduto Item)
{
    TCelula *Aux;
    Aux = Lista.primeiro->prox;
    while(Aux != NULL)
    {
        if(strcmp(Aux->item.nome, Item.nome) == 0)
        {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

TCelula* Pesquisar(TLista Lista, TProduto Item)
{
    TCelula *Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL)
    {
        if(Aux->prox->item.codigo == Item.codigo)
        {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir(TLista *Lista, TProduto *Item)
{
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);

    if(Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;
        if(Aux1->prox == NULL)
        {
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;

    }
}

TCelula* PesquisarNome(TLista Lista, TProduto Item)
{
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux -> prox != NULL)
    {
        if(Aux -> prox -> item.nome == Item.nome)
        {
            return Aux;
        }
        Aux = Aux -> prox;
    }
    return Aux;
}

void Atualizar(TLista *Lista, TProduto Item)
{
    TCelula* Aux;
    Aux = Lista->primeiro;
    while (Aux->prox != NULL)
    {
        if (strcmp(Aux->prox->item.nome, Item.nome) == 0)
        {
            LerProduto(&Item);
            Aux -> prox -> item = Item;
        }
        //else
        Aux = Aux->prox;
    }
}

void InserirCrescente(TProduto produto, TLista *lista) {
    TCelula *novaCelula = (TCelula *)malloc(sizeof(TCelula));
    novaCelula->item = produto;

    // Se a lista estiver vazia ou o primeiro elemento for maior ou igual ao novo
    if (lista->primeiro == NULL || strcmp(lista->primeiro->item.nome, produto.nome) >= 0) {
        novaCelula->prox = lista->primeiro;
        lista->primeiro = novaCelula;
    } else {
        TCelula *anterior = NULL;
        TCelula *atual = lista->primeiro;

        // Encontrar a posição correta na lista
        while (atual != NULL && strcmp(atual->item.nome, produto.nome) < 0) {
            anterior = atual;
            atual = atual->prox;
        }

        // Inserir a nova célula na posição correta
        novaCelula->prox = atual;
        anterior->prox = novaCelula;
    }

    lista->tamanho++;
}


void Iguais(TLista *Lista, TLista *Lista2)
{
    TCelula *aux1;
    TCelula *aux2;
    aux1 = Lista -> primeiro -> prox;
    aux2 = Lista2 -> primeiro -> prox;
    int cont = 0;

    while(aux1 != NULL && aux2 != NULL) //(!Vazia(*Lista) && !Vazia(*Lista2)){
    {
        if(aux1 -> item.codigo == aux2 -> item.codigo)
        {
            cont++;
        }
        aux1 = aux1 -> prox;
        aux2 = aux2 -> prox;
    }
    if(cont == Lista -> tamanho)
    {
        printf("\nSao iguais!");
    }
    else
        printf("\nNao sao iguais");

}

void ConcatenaListas(TLista *lista, TLista *lista2){
    TProduto x;
    while(!Vazia(*lista2)){
        x = lista2 -> primeiro -> prox -> item;
        Excluir(lista2, &x);
        Inserir(x, lista);

    }
    free(lista2->primeiro);
}

void LiberarLista(TLista *lista)
{
    TProduto x;
    while(!Vazia(*lista))
    {
        x = lista -> primeiro -> prox -> item;
        Excluir(lista, &x);
    }
    free(lista->primeiro);
}


void LerProduto(TProduto *Item)
{

    printf("Digite o nome do produto:\n");
    fflush(stdin);
    fgets(Item->nome, 70, stdin);

    printf("Digite o codigo do produto: \n");
    fflush(stdin);
    scanf("%d", &Item->codigo);

    printf("Digite a descricao do produto:\n");
    fflush(stdin);
    fgets(Item->descricao, 70, stdin);

    printf("Digite a quantidade do produto: \n");
    fflush(stdin);
    scanf("%d", &Item->quantidade);

    printf("Digite o valor do produto: \n");
    fflush(stdin);
    scanf("%f", &Item->valor);

}

void ImprimirProduto(TProduto Item)
{
    printf("Descricao do produto: %s\n", Item.descricao);
    printf("Nome do produto: %s\n", Item.nome);
    printf("Quantidade: %d\n", Item.quantidade);
    printf("Codigo do produto: %d\n", Item.codigo);
    printf("Valor do produto: %f\n", Item.valor);
}





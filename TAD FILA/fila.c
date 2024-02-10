#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "fila.h"

void FFVazia(TFila* Fila)
{
    Fila->frente = (TCelula*)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int FVazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    if(VerificarElemento(Fila, x) == 0)
    {
        Fila->tras->prox = (TCelula*)malloc(sizeof(TCelula));
        Fila->tras = Fila->tras->prox;
        Fila->tras->item = x;
        Fila->tras->prox = NULL;
        Fila->tamanho++;
    }
    else
        printf("NÃO FOI POSSÍVEL ENFILEIRAR! O CÓDIGO INFORMADO JÁ ESTÁ REGISTRADO EM OUTRO PRODUTO NA FILA!\n");

}

void Desenfileirar(TProduto *Item, TFila *Fila)
{
    TCelula *Aux;
    if(!FVazia(*Fila))
    {
        Aux = Fila->frente->prox;
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);
        if(Fila->frente->prox == NULL)
        {
            Fila->tras = Fila->frente;
        }
        Fila->tamanho--;
    }
}

void ImprimirFila(TFila *Fila)
{
    TProduto x;
    int TAM = Fila->tamanho;
    for(int i = 0; i < TAM; i++)
    {
        Desenfileirar(&x, Fila);
        ImprimirProduto(x);
        Enfileirar(x, Fila);
    }
}

TProduto PesquisarFila(TFila *Fila, TProduto Item)
{
    TProduto x;
    TProduto y;
    y.codigo = -1;
    int TAM = Fila->tamanho;
    for(int i = 0; i < TAM; i++)
    {
        Desenfileirar(&x, Fila);
        if(x.codigo == Item.codigo)
        {
            ImprimirProduto(x);
            y = x;
        }
        Enfileirar(x, Fila);
    }
    if(y.codigo == -1)
        printf("O PRODUTO NÃO FOI ENCONTRADO! VALOR -1 RETORNADO\n");
    return y;
}

void LerProduto(TProduto* produto)
{

    printf("Digite o nome do produto:\n");
    fflush(stdin);
    fgets(produto->nome, 20, stdin);

    printf("Digite a descricao do produto:\n");
    fflush(stdin);
    fgets(produto->descricao, 200, stdin);

    printf("Digite o codigo do produto:\n");
    fflush(stdin);
    scanf("%d", &produto->codigo);

    printf("Digite o preco do produto:\n");
    fflush(stdin);
    scanf("%f", &produto->preco);

    printf("Digite a quantidade do produto:\n");
    fflush(stdin);
    scanf("%d", &produto->quantidade);


}

void LerNome(TProduto* produto)
{

    printf("Digite o nome do produto:\n");
    fflush(stdin);
    fgets(produto->nome, 20, stdin);
}

void LerCodigo(TProduto* produto)
{

    printf("Digite o codigo do produto:\n");
    fflush(stdin);
    scanf("%d", &produto->codigo);
}

void ImprimirProduto(TProduto produto)
{
    printf("\n>>>>>> PRODUTO ENCONTRADO <<<<<<\n");
    printf("Nome: %s", produto.nome);
    printf("Descrição: %s", produto.descricao);
    printf("Codigo: %d\n", produto.codigo);
    printf("Preço: %f\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);

}

void LiberarFila(TFila* Fila)
{
    TProduto x;
    while(!FVazia(*Fila))
    {
        Desenfileirar(&x, Fila);
    }
    free(Fila->frente);
}

TProduto PesquisarPorNome(TFila *Fila, TProduto Item)
{
    TProduto x;
    TProduto y;
    y.codigo = -1;
    int tam = Fila->tamanho;
    for(int i = 0; i < tam; i++)
    {
        Desenfileirar(&x, Fila);
        if(strcmp(x.nome, Item.nome) == 0)
        {
            ImprimirProduto(x);
            y = x;
        }
        Enfileirar(x, Fila);
    }
    if(y.codigo == -1)
        printf("PRODUTO NÃO FOI ENCONTRADO.\n");
    return y;
}

int Comparar(TFila *Fila1, TFila *Fila2)
{
    TProduto x1;
    TProduto y;
    int cont = 0;
    int tam1 = Fila1->tamanho;
    int tam2 = Fila2->tamanho;
    if(FVazia(*Fila1) || FVazia(*Fila2))
    {
        printf("ALGUMA FILA ESTA VAZIA!\n");
        return -1;
    }
    else if(Fila1->tamanho == Fila2->tamanho)
    {
        while(tam1 != 0)
        {
            Desenfileirar(&x1, Fila1);
            int tam2_original = tam2;
            while(tam2 != 0)
            {
                Desenfileirar(&y, Fila2);
                if(x1.codigo == y.codigo)
                {
                    cont++;
                }
                Enfileirar(y, Fila2);
                tam2--;
            }
            Enfileirar(x1, Fila1);
            tam2 = tam2_original;
            tam1--;
        }
        if(cont == Fila1->tamanho)
        {
            printf("AS FILAS CONTÉM OS MESMOS ELEMENTOS!\n");
            return 1;
        }
        else
        {
            printf("AS FILAS SÃO DISTINTAS!\n");
            return 0;
        }
    }
    else
    {
        printf("AS FILAS SÃO DISTINTAS\n");
        return 0;
    }
}

void Remover(TFila *Fila, int termo)
{
    TProduto x;
    TFila F2;
    FFVazia(&F2);
    int tam = Fila->tamanho;
    if(termo == 0)
        printf("ATENCA! NÃO PODE REMOVER O TERMO 0\n");
    else if(termo > Fila->tamanho)
    {
        printf("A FILA SELECIONADA NÃO POSSUI ESSE TERMO\n");
    }
    else
    {
        for(int i = 0; i < tam; i++)
        {
            Desenfileirar(&x, Fila);
            if(i+1 == termo)
            {
                Enfileirar(x, &F2);
            }
            else
                Enfileirar(x, Fila);
        }
        Desenfileirar(&x, &F2);
        free(F2.frente);
        printf("TERMO REMOVIDO COM SUCESSO!\n");
    }
}

void Intercessao(TFila *Fila1, TFila *Fila2, TFila *Fila3)
{
    int tam1 = Fila1->tamanho;
    int tam2 = Fila2->tamanho;
    TProduto x1, y;
    if(tam1 == 0 && tam2 == 0)
    {
        printf("AS FILAS ESTÃO VAZIAS.\n");
    }
    while(tam1 != 0)
    {
        Desenfileirar(&x1, Fila1);
        int tam2_original = tam2;
        while(tam2 != 0)
        {
            Desenfileirar(&y, Fila2);
            if(x1.codigo == y.codigo)
            {
                if(VerificarElemento(Fila3, y) == 0)
                    Enfileirar(x1, Fila3);
            }
            Enfileirar(y, Fila2);
            tam2--;
        }
        Enfileirar(x1, Fila1);
        tam2 = tam2_original;
        tam1--;
    }
    printf("A INTERCESSÃO FOI REALIZADA COM SUCESSO!\n");
}

int VerificarElemento(TFila *Fila, TProduto Item)
{
    TProduto x1;
    int presente = 0;
    int tam = Fila->tamanho;
    while (tam > 0 && !presente)
    {
        Desenfileirar(&x1, Fila);
        if (x1.codigo == Item.codigo)
        {
            presente = 1;
        }
        Enfileirar(x1, Fila);
        tam--;
    }
    return presente;
}

void Subtracao(TFila *Fila1, TFila *Fila2, TFila *Fila3)
{
    int tam1 = Fila1->tamanho;
    int tam2 = Fila2->tamanho;
    TProduto x1, y;
    if(tam1 == 0 && tam2 == 0)
    {
        printf("AS FILAS INFORMADAS ESTÃO VAZIAS\n");
    }
    while(tam1 != 0)
    {
        Desenfileirar(&x1, Fila1);
        int tam2_original = tam2;
        while(tam2 != 0)
        {
            Desenfileirar(&y, Fila2);
            if(x1.codigo != y.codigo)
            {
                if(VerificarElemento(Fila3, x1) == 0)
                    Enfileirar(x1, Fila3);
            }
            Enfileirar(y, Fila2);
            tam2--;
        }
        Enfileirar(x1, Fila1);
        tam2 = tam2_original;
        tam1--;
    }
    printf("A SUBTRAÇÃO FOI REALIZADA COM SUCESSO!\n");
}



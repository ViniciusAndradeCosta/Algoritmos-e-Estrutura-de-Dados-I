#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include"util.h"

void ImprimirProduto(TProduto produto)
{
    printf("\n>>>>>> PRODUTO ENCONTRADO <<<<<<\n");
    printf("Nome: %s", produto.nome);
    printf("Descrição: %s", produto.descricao);
    printf("Codigo: %d\n", produto.codigo);
    printf("Preço: %f\n", produto.preco);
    printf("Quantidade: %d\n", produto.quantidade);

}

void LerNome(TProduto* produto)
{
    printf("=======================================================\n");
    printf("DIGITE O NOME DO PRODUTO: ");
    fflush(stdin);
    fgets(produto->nome, 50, stdin);
    printf("=======================================================\n");
}

void LerCodigo(TProduto* produto)
{
    printf("=======================================================\n");
    printf("DIGITE O CÓDIGO DO PRODUTO:\n");
    fflush(stdin);
    scanf("%d", &produto->codigo);
    printf("=======================================================\n");
}

void LerProduto(TProduto* produto)
{

    printf("DIGITE O NOME DO PRODUTO:\n");
    fflush(stdin);
    fgets(produto->nome, 50, stdin);
    printf("=======================================================\n");
    printf("DIGITE A DESCRIÇÃO DO PRODUTO:\n");
    fflush(stdin);
    fgets(produto->descricao, 150, stdin);
    printf("=======================================================\n");

    printf("DIGITE O CÓDIGO DO PRODUTO:\n");
    fflush(stdin);
    scanf("%d", &produto->codigo);
    printf("=======================================================\n");
    printf("DIGITE O PREÇO DO PRODUTO:\n");
    fflush(stdin);
    scanf("%f", &produto->preco);
    printf("=======================================================\n");
    printf("DIGITE A QUANTIDADE DO PRODUTO:\n");
    fflush(stdin);
    scanf("%d", &produto->quantidade);
    printf("=======================================================\n");
}

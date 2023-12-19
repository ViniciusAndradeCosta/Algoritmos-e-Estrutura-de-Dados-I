#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface.h"


void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. ATUALIZAR");
    printf("  \n\t6. INSERIR CRESCENTE");
    printf("  \n\t7. LISTAS CRESCENTES SAO IGUAIS?");
    printf("  \n\t8. JUNTAR LISTAS 1 E 2");
    printf("  \n\t9. SAIR");
}

void MENU(TLista *lista, TLista *lista2)
{
    TProduto produto;
    TCelula *p;
    int opcao = 0;
    int n;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            system("cls");
            /** Código para opção de menu Inserir */
            LerProduto(&produto);
            Inserir(produto, lista);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            /** Código para opção de menu Pesquisar */
            printf("\nDigite o codigo do produto que deseja pesquisar: ");
            fflush(stdin);
            scanf("%d", &produto.codigo);

            p = Pesquisar(*lista, produto);
            if(p != NULL)
            {
                printf("\n MSG: produto encontrado:\n");
                ImprimirProduto(p->prox->item);
            }
            else
            {
                printf("\n MSG: produto nao encontrado...\n");
            }
            system("PAUSE");
            break;
        case 3:



            system("cls");
            /** Código para opção de menu Excluir */
            printf("\nDigite o codigo do produto que deseja excluir: ");
            fflush(stdin);
            scanf("%d", &produto.codigo);

            /** captura quantos elementos tem na lista antes da chamada
            da função excluir */
            n = lista->tamanho;

            Excluir(lista, &produto);

            /** Testa se o tamanho da lista é diferente de n, se for,
            um elemento foi excluído */
            if(lista->tamanho != n)
            {
                printf("\nMSG: Produto excluido: \n");
                ImprimirProduto(produto);
            }
            else
            {
                printf("\nMSG: Produto nao encontrado para exclusao!...");
            }

            system("PAUSE");
            break;

        case 4:
            system("cls");
            /** Código para opção de menu Imprimir */
            ImprimirLista(*lista);
            system("PAUSE");
            break;

        case 5:
            system("cls");
            printf("Digite o nome do produto a ser atualizado: \n");
            fflush(stdin);
            fgets(produto.nome, 50, stdin);
            Atualizar(lista, produto);
            printf("Produto atualizado \n");
            system("PAUSE");
            break;


        case 6:
            system("cls");
            LerProduto(&produto);
            InserirCrescente(produto, lista);
            printf("Produto inserido em ordem crescente.\n");
            system("PAUSE");
            break;


        case 7:
            //LISTAS CRESCENTES SÃO IGUAIS?
            system("cls");
            TLista Lista2;
            FLVazia(&Lista2);
            int aux = 1;

            while(aux != 0)
            {
                system("cls");

                LerProduto(&produto);
                Inserir(produto, &Lista2);

                printf("Digite 1 para inserir produtos na lista 2, e 0 para parar: \n");
                scanf("%d", &aux);

            }
            printf("\n************\n");

            Iguais(lista, &Lista2);
            system("PAUSE");

            break;

        case 8:

            //CONCATENAR LISTAS 1 E 2
            system("cls");
            FLVazia(&lista2);
            int aux1 = 1;

            while(aux1 != 0)
            {
                system("cls");

                LerProduto(&produto);
                Inserir(produto, &lista2);

                printf("Digite 1 para inserir produtos na lista 2, e 0 para parar: \n");
                scanf("%d", &aux1);

            }
            printf("\n************\n");
            ConcatenaListas(lista, &lista2);
            ImprimirLista(*lista);
            system("PAUSE");

            break;

        case 9:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<\n\n\n\t");
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            system("PAUSE");
        } // fim do bloco switch
    }
    while(opcao != 9);
}

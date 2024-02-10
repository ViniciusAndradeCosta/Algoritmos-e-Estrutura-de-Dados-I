#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "interface.h"
#include "fila.h"

void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPÇÕES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. PESQUISAR PRODUTO(CÓDIGO OU NOME)");
    printf("  \n\t3. DESENFILEIRAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. COMPARAR DUAS FILAS");
    printf("  \n\t6. REMOCAO DO I-ESIMO TERMO");
    printf("  \n\t7. INTERCESSÃO DE FILAS");
    printf("  \n\t8. SUBTRAÇÃO DE FILAS");
    printf("  \n\t9. SAIR");
}

void MSG_FILA()
{
    printf(">>>>>> ESCOLHA UMA FILA <<<<<<");
    printf("\n\n\t1. FILA 1");
    printf("\n\t2. FILA 2");
    printf("\n\t3. FILA 3");
}

void MSG_PESQUISAR()
{
    printf(">>>>>> ESCOLHA COMO DESEJA PESQUISAR O PRODUTO<<<<<<");
    printf("\n\n 1 - CÓDIDGO");
    printf("\n 2 - NOME");
    printf("\n\n=======================================================");

}

void MENU(TFila *fila1, TFila *fila2, TFila *fila3)
{
    TProduto produto;
    int opcao=0;
    int opcaoFila=0;
    int metodo=0;
    do
    {
        MSG_MENU();
        printf("\n=======================================================");
        printf("\nDIGITE UMA OPÇÃO: ");
        fflush(stdin);
        scanf("%d", &opcao);
        printf("\n\n=======================================================");
        switch(opcao)
        {
        case 1:

            MSG_FILA();
            printf("\n\nDIGITE UMA OOÇÃO: ");
            fflush(stdin);
            scanf("%d", &opcaoFila);
            switch(opcaoFila)
            {
            case 1:
                LerProduto(&produto);
                Enfileirar(produto, fila1);
                break;
            case 2:
                LerProduto(&produto);
                Enfileirar(produto, fila2);
                break;
            case 3:
                LerProduto(&produto);
                Enfileirar(produto, fila3);
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            }
            system("PAUSE");

            break;


        case 2:

            MSG_PESQUISAR();
            metodo=0;
            printf("\n\nDIGITE UMA OPÇÃO: ");
            fflush(stdin);
            scanf("%d", &metodo);
            switch(metodo)
            {
            case 1:
                LerCodigo(&produto);
                PesquisarFila(fila1, produto);
                break;
            case 2:
                LerNome(&produto);
                PesquisarPorNome(fila1, produto);
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            }
            system("PAUSE");

            break;

        case 3:

            MSG_FILA();
            opcaoFila=0;
            printf("\n\nDIGITE UMA OPÇÃO: ");
            fflush(stdin);
            scanf("%d", &opcaoFila);
            switch(opcaoFila)
            {
            case 1:
                Desenfileirar(&produto, fila1);
                printf("O PRODUTO FOI DESENFILEIRADO COM SUCESSO\n");
                break;
            case 2:
                Desenfileirar(&produto, fila2);
                printf("O PRODUTO FOI DESENFILEIRADO COM SUCESSO\n");
                break;
            case 3:
                Desenfileirar(&produto, fila3);
                printf("O PRODUTO FOI DESENFILEIRADO COM SUCESSO\n");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            }
            system("PAUSE");

            break;

        case 4:

            MSG_FILA();
            opcaoFila=0;
            printf("\n\nDIGITE UMA OPÇÃO: ");
            fflush(stdin);
            scanf("%d", &opcaoFila);
            switch(opcaoFila)
            {
            case 1:
                ImprimirFila(fila1);
                printf("\nIMPRESSÃO REALIZADA COM SUCESSO!\n");
                break;
            case 2:
                ImprimirFila(fila2);
                printf("\nIMPRESSÃO REALIZADA COM SUCESSO!\n");
                break;
            case 3:
                ImprimirFila(fila3);
                printf("\nIMPRESSÃO REALIZADA COM SUCESSO!\n");
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            }
            system("PAUSE");

            break;

        case 5:

            Comparar(fila1, fila2);
            system("PAUSE");

            break;

        case 6:

            printf("INFORME O NÚMERO DO TERMO QUE VOCÊ DESEJA EXCLUIR:\n");
            int termo = 0;
            fflush(stdin);
            scanf("%d", &termo);
            Remover(fila1, termo);
            system("PAUSE");

            break;

        case 7:

            Intercessao(fila1, fila2, fila3);
            system("PAUSE");

            break;

        case 8:

            Subtracao(fila1, fila2, fila3);
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
        }
    }
    while(opcao != 9);
}


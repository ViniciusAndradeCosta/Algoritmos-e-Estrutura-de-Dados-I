#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "interface.h"

void MSG_MENU( )
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. EMPILHAR");
    printf("  \n\t2. PESQUISAR PRODUTO(CÓDIGO OU NOME)");
    printf("  \n\t3. DESEMPILHAR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. INVERTER PILHA(ESCOLHA O METODO QUE DESEJA UTILIZAR)");
    printf("  \n\t6. EXPRESSAO ARITMETICA");
    printf("  \n\t7. TRANSF. INFIXADA EM POS-FIXADA");
    printf("  \n\t8. SAIR");
}

void MSG_PESQUISAR()
{
    printf(">>>>>> ESCOLHA COMO DESEJA PESQUISAR O PRODUTO<<<<<<");
    printf("\n\n 1 - CODIDGO");
    printf("\n 2 - NOME");
    printf("\n\n=======================================================");
}

void MSG_INVERTER()
{
    printf(">>>>>> ESCOLHA COMO DESEJA INVERTER A PILHA<<<<<<");
    printf("\n\n 1 - USANDO FILA AUXILIAR");
    printf("\n 2 - USANDO DUAS PILHAS AUXILIARES");
    printf("\n 3 - USANDO UMA PILHA AUXILIAR E VARIAVEIS AUXILIARES");
}

void MENU(TPilha *Pilha)
{
    TProduto produto;
    int opcao=0;
    char expressao[100];
    char expressao1[100];
    int metodo=0;
    int metodo1=0;
    do
    {
        MSG_MENU();
        printf("\n=======================================================");
        printf("\nDIGITE UMA OPÇÃO: ");
        fflush(stdin);
        scanf("%d", &opcao);
        printf("=======================================================\n");

        switch(opcao)
        {
        case 1:
            LerProduto(&produto);
            Empilhar(produto, Pilha);
            system("PAUSE");
            break;

        case 2:

            MSG_PESQUISAR();
            metodo=0;
            printf("\nDIGITE UMA OPCÃO: ");
            fflush(stdin);
            scanf("%d", &metodo);
            switch(metodo)
            {
            case 1:
                LerCodigo(&produto);
                PilhaPesquisar(Pilha, produto);
                break;
            case 2:
                LerNome(&produto);
                PesquisarPorNomePilha(Pilha, produto);
                break;
            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            }
            system("PAUSE");

            break;


        case 3:
            Desempilhar(Pilha, &produto);
            printf("PRODUTO DESENFILEIRADO!o\n");
            system("PAUSE");
            break;
        case 4:
            ImprimirPilha(Pilha);
            printf("\nIMPRESSÃO DA PILHA REALIZADA COM SUCESSO!\n");
            system("PAUSE");
            break;

        case 5:
            MSG_INVERTER();
            metodo1=0;
            printf("\n\nDIGITE UMA OPÇÃO: ");
            fflush(stdin);
            scanf("%d", &metodo1);
            switch(metodo1)
            {
            case 1:
                InverterElementosUsandoFila(Pilha);

                break;
            case 2:
                InverterElementosUsandoDuasPilhas(Pilha);

                break;
            case 3:
                InverterPilhaComVariaveis(Pilha);

                break;

            default:
                system("cls");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            }

            system("PAUSE");
            break;
        case 6:

            printf("DIGITE A EXPRESSÃO ARITMÉTICA: \n");
            fflush(stdin);
            fgets(expressao, sizeof(expressao), stdin);
            ExpressaoAritmetica(expressao);
            system("PAUSE");
            break;
        case 7:

            printf("DIGITE A EXPRESSÃO ARITMÉTICA: \n");
            fflush(stdin);
            fgets(expressao1, sizeof(expressao1), stdin);
            TranformarDeInfixadaParaPosInfixada(expressao1);
            system("PAUSE");
            break;
        case 8:
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
    while(opcao != 8);
}

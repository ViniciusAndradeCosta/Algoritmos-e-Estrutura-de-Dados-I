#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "interface.h"

int main()
{

    setlocale(LC_ALL, "Portuguese");
    TPilha pilha1;
    FPVazia(&pilha1);

    MENU(&pilha1);

    LiberarPilha(&pilha1);

    return 0;
}

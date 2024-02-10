#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "interface.h"
#include "fila.h"

int main()
{

    setlocale(LC_ALL, "Portuguese");

    TFila fila1;
    FFVazia(&fila1);

    TFila fila2;
    FFVazia(&fila2);

    TFila fila3;
    FFVazia(&fila3);

    MENU(&fila1, &fila2, &fila3);

    LiberarFila(&fila1);
    LiberarFila(&fila2);
    LiberarFila(&fila3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "interface.h"

int main() {
    //TLista lista;
    TLista lista2;

    TLista lista;
    FLVazia(&lista);


    //FLVazia(&lista);
    FLVazia(&lista2);

    MENU(&lista, &lista2);

    LiberarLista(&lista);
    LiberarLista(&lista2);

    return 0;
}

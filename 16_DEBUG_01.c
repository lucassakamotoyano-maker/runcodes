#include <stdio.h>

#include "debug.h"
#include "soma.h"

int main(void) 
{   DEBUG("Início do programa");

    int x = 10;
    int y = 20;

    DEBUG("Antes de chamar a função soma");

    int resultado = soma(x, y);

    printf("Resultado: %d\n", resultado);

    DEBUG("Fim do programa");

    return 0;
}


//-E expande o código, substituindo a macro pelo seu conteúdo, incluindo os argumentos fornecidos.

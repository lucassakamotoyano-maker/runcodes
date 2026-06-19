#include "debug.h"
#include "soma.h"

int soma(int a, int b)
{
    DEBUG("Entrou na função soma");

    int resultado = a + b;

    DEBUG("Calculou o resultado da soma");

    return resultado;
}

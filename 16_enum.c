#include <stdio.h>

enum DiaSemana
{
    DOMINGO,
    SEGUNDA,
    TERÇA,
    QUARTA,
    QUINTA,
    SEXTA,
    SÁBADO
};

int main(void)
{
    enum DiaSemana hoje = SEXTA;
    
    if (hoje == SEXTA) //hoje == 5
    {
        printf("Sextou!\n");
    }
    switch (hoje)
    {
        case SEGUNDA: printf("Segunda!"); break;
        case SÁBADO: printf("Sábado!"); break;
        default: printf("Outro dia!"); break;
    }
    return 0;
    
}
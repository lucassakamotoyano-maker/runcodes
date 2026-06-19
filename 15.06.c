#include "avaliador.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome_arquivo[256];
    unsigned long long numero_linha = 1;
    int caractere;
    int inicio_linha = 1;

    if (fgets(nome_arquivo, sizeof(nome_arquivo), stdin) == NULL)
    {
        return 1;
    }

    nome_arquivo[strcspn(nome_arquivo, "\r\n")] = '\0';

    FILE *entrada = fopen(nome_arquivo, "r");
    if (entrada == NULL)
    {
        return 1;
    }

    FILE *saida = fopen("poema_numerado.txt", "w");
    if (saida == NULL)
    {
        fclose(entrada);
        return 1;
    }

    while ((caractere = fgetc(entrada)) != EOF)
    {
        if (inicio_linha)
        {
            fprintf(saida, "%03llu: ", numero_linha);
            inicio_linha = 0;
        }

        fputc(caractere, saida);

        if (caractere == '\n')
        {
            numero_linha++;
            inicio_linha = 1;
        }
    }

    fclose(entrada);
    fclose(saida);

    arquivo_finalizado("poema_numerado.txt");

    return 0;
}

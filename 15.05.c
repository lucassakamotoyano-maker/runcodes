#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avaliador.h"

static char *ler_linha(FILE *arquivo)
{
    size_t capacidade = 128;
    size_t tamanho = 0;
    char *linha = malloc(capacidade);
    int caractere;

    if (linha == NULL)
    {
        return NULL;
    }

    while ((caractere = fgetc(arquivo)) != EOF)
    {
        if (tamanho + 1 >= capacidade)
        {
            char *linha_maior;

            capacidade *= 2;
            linha_maior = realloc(linha, capacidade);
            if (linha_maior == NULL)
            {
                free(linha);
                return NULL;
            }
            linha = linha_maior;
        }

        linha[tamanho++] = (char)caractere;
        if (caractere == '\n')
        {
            break;
        }
    }

    if (tamanho == 0 && caractere == EOF)
    {
        free(linha);
        return NULL;
    }

    linha[tamanho] = '\0';
    return linha;
}

static int contem_sem_diferenciar_maiusculas(const char *linha, const char *palavra)
{
    size_t tamanho_linha = strlen(linha);
    size_t tamanho_palavra = strlen(palavra);
    size_t i;
    size_t j;

    if (tamanho_palavra == 0)
    {
        return 1;
    }

    for (i = 0; i + tamanho_palavra <= tamanho_linha; i++)
    {
        for (j = 0; j < tamanho_palavra; j++)
        {
            unsigned char caractere_linha = (unsigned char)linha[i + j];
            unsigned char caractere_palavra = (unsigned char)palavra[j];

            if (tolower(caractere_linha) != tolower(caractere_palavra))
            {
                break;
            }
        }

        if (j == tamanho_palavra)
        {
            return 1;
        }
    }

    return 0;
}

int main(void)
{
    char nome_entrada[256];
    char nome_saida[256];
    char palavra[256];
    FILE *entrada;
    FILE *saida;
    char *linha;

    if (scanf("%255s %255s %255s", nome_entrada, nome_saida, palavra) != 3)
    {
        return 1;
    }

    entrada = fopen(nome_entrada, "r");
    if (entrada == NULL)
    {
        return 1;
    }

    saida = fopen(nome_saida, "w");
    if (saida == NULL)
    {
        fclose(entrada);
        return 1;
    }

    while ((linha = ler_linha(entrada)) != NULL)
    {
        if (contem_sem_diferenciar_maiusculas(linha, palavra))
        {
            fputs(linha, saida);
        }
        free(linha);
    }

    fclose(entrada);
    fclose(saida);
    arquivo_finalizado(nome_saida);
    return 0;
}

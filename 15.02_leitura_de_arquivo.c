#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome_arquivo[256];
    char linha[1024];

    if (fgets(nome_arquivo, sizeof(nome_arquivo), stdin) == NULL)
    {
        return 1;
    }

    nome_arquivo[strcspn(nome_arquivo, "\r\n")] = '\0';

    FILE *arquivo = fopen(nome_arquivo, "r");
    
    if (arquivo == NULL)
    {
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        fputs(linha, stdout); //imprime a linha lida do arquivo na saída padrão
    }

    fclose(arquivo);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char nome_arquivo[256];
    unsigned long long quantidade = 0;//variável para contar a quantidade de caracteres
    //long long permite armazenar números grandes, como um arquivo com muito caracteres

    if (fgets(nome_arquivo, sizeof(nome_arquivo), stdin) == NULL)
    {
        return 1;
    }

    nome_arquivo[strcspn(nome_arquivo, "\r\n")] = '\0';

    FILE *arquivo = fopen(nome_arquivo, "rb");

    if (arquivo == NULL)
    {
        return 1;
    }

    while (fgetc(arquivo) != EOF)//fgetc lê um caractere do arquivo e retorna EOF quando chega ao final
    {
        quantidade++;
    }

    fclose(arquivo);
    printf("%llu\n", quantidade);

    return 0;
}

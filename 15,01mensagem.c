#include <stdio.h>
#include "avaliador.h"
int main()
{
    char mensagem[101];

    //mensagem[10] -> *(mensagem + 10) -> &mensagem[10]

    scanf("%s", mensagem);

    FILE *arquivo;//ponteiro para o arquivo

    // abre o arquivo para escrita
    arquivo = fopen("mensagem.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //escreve a mensagem no arquivo
    fprintf(arquivo, "%s\n", mensagem);
    fclose(arquivo);

    arquivo_finalizado("mensagem.txt");
    return 0;
}
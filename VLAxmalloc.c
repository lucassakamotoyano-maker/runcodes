#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    size_t n;

    if(scanf("%zu", &n) != 1 || n == 0)
    {
        printf("tamanho invalido.\n");
        return 1;
    }

    int *vetor = calloc(n, sizeof*vetor);//já inicializa todos com 0

    if(vetor == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    free(vetor);

    return 0;
}
#include <stdio.h>

int main()
{
    printf("Arquivo: %s\n", __FILE__);
    printf("Linha: %d\n", __LINE__);
    printf("Data da compilação: %s\n", __DATE__);
    printf("Hora da compilação: %s\n", __TIME__);
    printf("Função atual: %s\n", __func__);

    return 0;
}

#include <stdio.h>

int main()
{
    char nome[101];
    FILE *file;
    scanf("%s", nome); 
    file = fopen(nome, "rb");

    if (file == NULL)
    {
        printf("Erro: arquivo %s não existe.\n", nome);
        return 1;
    }

    int byte = 0; 
    int count = 0;
    while (1) //while(!feof(file)) imprimi o último byte duas vezes
    {
        fread(&byte, 1, 1, file);
        if (feof(file)) // Verifica se chegou ao final do arquivo
        {
            break;
        }
        count++;
        printf("%02x ", byte); // Imprime o byte em formato hexadecimal
        if(count % 16 == 0)
        {
            printf("\n"); // Quebra de linha a cada 16 bytes para melhor visualização
        }
    }

    
    fclose(file);

    return 0;
}
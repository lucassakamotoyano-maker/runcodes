#include <stdio.h>
int main()
{
    FILE *arquivo;

    arquivo = fopen("exemplo.txt", "w+");//w+ é como o w, mas permite leitura
    //r para leitura apenas, w para escrita apenas (sobrescreve o arquivo se ele já existir), a para escrita apenas (adiciona ao final do arquivo se ele já existir)
    //r+ para leitura e escrita, assim como o a+ em relação ao a
    if (arquivo == NULL)    // Se o arquivo não existir ou não haver memória suficiente para abrir o arquivo, fopen retorna NULL
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // escreve os dados no arquivo
    for(int i = 0; i<5; i++)
    {
        char nome[20];
        int idade;
        float salario;

        printf("Digite o nome, idade e salario da pessoa %d: ", i+1);
        scanf("%s %d %f", nome, &idade, &salario);

        fprintf(arquivo, "%s %d %.2f\n", nome, idade, salario); // Escreve os dados no arquivo
    }

    fclose(arquivo);// Fechando o arquivo após o uso
    return 0;
}
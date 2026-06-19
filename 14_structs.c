#include <stdio.h>

int main()
{
    struct dados_pessoa
    {
        char nome[100];
        int idade;
        float altura;
        char CPF[15];
    };

    struct dados_pessoa pessoa, *pp; //declaration of two variables of type struct dados_pessoa

    pp = &pessoa; //pp is a pointer to the variable pessoa

    printf("Digite o nome da pessoa: ");
    scanf("%99s", pp->nome); //we use %99s to prevent buffer overflow, as the maximum size of the name is 100 characters including the null terminator

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pp->idade);

    printf("Digite a altura da pessoa: ");
    scanf("%f", &pp->altura);

    printf("Digite o CPF da pessoa: ");
    scanf("%14s", pp->CPF);

    printf("Nome: %s\n", pp->nome); //pessoa.nome is equivalent to (*pp).nome, as pp is a pointer to pessoa
    printf("Idade: %d\n", pp->idade);//(*pp).idade is equivalent to pp->idade
    printf("Altura: %.2f\n", pp->altura);
    printf("CPF: %s\n", pp->CPF);

    return 0;
}
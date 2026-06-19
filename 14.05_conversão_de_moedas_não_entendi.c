#include <stdio.h>
#include <string.h>
//fuga do ponto flutuante, usando centavos (inteiros) para evitar erros de precisão
typedef struct
{
    long long int centavos;
    char codigo[4];
} ValorMonetario;

typedef struct
{
    char codigo[4];
    long long int numerador;
    long long int denominador;
} Moeda;

// função para encontrar o índice de uma moeda no vetor de moedas
int encontrar_moeda(Moeda moedas[], int quantidade, const char codigo[]);

int main(void)
{
    int quantidade_moedas;
    Moeda moedas[10];

    scanf("%d", &quantidade_moedas);

    for (int i = 0; i < quantidade_moedas; i++)
    {
        scanf("%3s %lld %lld",
              moedas[i].codigo,
              &moedas[i].numerador,
              &moedas[i].denominador);
    }

    int quantidade_consultas; 
    scanf("%d", &quantidade_consultas);

    for (int i = 0; i < quantidade_consultas; i++)
    {
        ValorMonetario origem;
        ValorMonetario destino;

        scanf("%lld %3s %3s",
              &origem.centavos,
              origem.codigo,
              destino.codigo);

        int indice_origem =
            encontrar_moeda(moedas, quantidade_moedas, origem.codigo);
        int indice_destino =
            encontrar_moeda(moedas, quantidade_moedas, destino.codigo);

        destino.centavos = //conversão da origem para USD e depois de USD para destino
            (origem.centavos *
             moedas[indice_origem].numerador *
             moedas[indice_destino].denominador) /
            (moedas[indice_origem].denominador *
             moedas[indice_destino].numerador);

        printf("%lld.%02lld\n", //simular um número quebrado
               destino.centavos / 100,
               destino.centavos % 100); // %02lld para garantir que 1005 seja impresso como 10.05, não 10.5
    }

    return 0;
}

//linear search
int encontrar_moeda(Moeda moedas[], int quantidade, const char codigo[])
{
    for (int i = 0; i < quantidade; i++)
    {
        if (strcmp(moedas[i].codigo, codigo) == 0) //se for igual, retorna 0, ou seja, encontrou a moeda
        {
            return i;//retorna o índice (gaveta) onde a moeda foi encontrada
        }
    }

    return -1;
}
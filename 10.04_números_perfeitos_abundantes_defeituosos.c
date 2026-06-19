#include <stdio.h>

// prototype functions
int classifica(char t, int n);

int main(void)
{
    int num;
    scanf("%d", &num);

    int defeituosos = 0, perfeitos = 0, abundantes = 0;

    for (int i = 1; i <= num; i++)
    {
        defeituosos += classifica('<', i);
        perfeitos += classifica('=', i);
        abundantes += classifica('>', i);
    }

    printf("%d\n", defeituosos);
    printf("%d\n", perfeitos);
    printf("%d\n", abundantes);

    return 0;
}

int classifica(char t, int n)
{
    int soma_divisores = 0;

    for (int divisor = 1; divisor <= n / 2; divisor++)
    {
        if (n % divisor == 0)
        {
            soma_divisores += divisor;
        }
    }

    switch (t)
    {
        case '<':
            return soma_divisores < n; //returns 1 if true, 0 if false
        case '=':
            return soma_divisores == n; 
        case '>':
            return soma_divisores > n;
        default:
            return 0; //Invalid type
    }

    return 0;
}

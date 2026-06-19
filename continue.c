#include <stdio.h>

int main()
{
    int i = 0;
    int soma = 0;

    while (i<5)
    {
        i++;
        if (i == 3) // Quando i for igual a 3, o loop irá pular para a próxima iteração, ou seja, não irá somar o valor de i na variável soma.
        {
            continue;
        }
        soma += i;
    }
    printf("Soma: %d\n", soma);
    return 0;

}
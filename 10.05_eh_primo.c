#include <stdio.h>
#include <stdbool.h>
//prototype functions
bool eh_primo(int num);

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++)
    {
        if(eh_primo(i))
        {
            printf("%d ", i);
        }
    }

    return 0;
}

bool eh_primo(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
#include <stdio.h>


int main()
{
    char s[1001];
    scanf("%s", s);

    char letra;
    scanf(" %c", &letra); // Note the space before %c to consume any leftover newline character

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != letra)
        {
            printf("%c", s[i]);
        }
    }

    return 0;
}
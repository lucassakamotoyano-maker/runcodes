#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[10001];
    fgets(str, sizeof(str), stdin);

    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isspace(str[i]))
        {
            if (!in_word)
            {
                count++;
                in_word = 1;
            }
        }
        else
        {
            in_word = 0;
        }
    }
    printf("%d\n", count);
    return 0;
}
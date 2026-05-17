#include <stdio.h>
#include <string.h>

int main()
{
    char string[1001];
    fgets(string, 1001, stdin);
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 'a' + 'A';// Convert to uppercase
        }
    }
    printf("%s", string);
    return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
    char split_symbol;
    scanf(" %c ", &split_symbol);
    
    char string[1001];
    fgets(string, 1001, stdin);
    string[strcspn(string, "\n")] = '\0'; // Remove the newline character from the input string read by fgets
    int len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        if (string[i] == split_symbol)
        {
            printf("\n");
        }
        else
        {
            printf("%c", string[i]);
        }
    }
    printf("\n");
    return 0;
}
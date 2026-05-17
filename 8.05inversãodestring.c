#include <stdio.h>
#include <string.h>

int main()
{
    char string[1001], inverted[1001];
    fgets(string, 1001, stdin);
    string[strcspn(string, "\n")] = '\0'; // Remove newline character

    for (int i = 0; i < strlen(string); i++)
    {
        inverted[i] = string[strlen(string) - 1 - i];
    }
    inverted[strlen(string)] = '\0'; // Add null terminator
    printf("%s", inverted);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main()
{ 
    char string[1001], inverted[1001];
    fgets(string, 1001, stdin);

    int length = strlen(string);
    string[strcspn(string, "\n")] = '\0'; // Remove newline character

    for (int i = length - 1; i >= 0; i--)
    {
        inverted[length - 1 - i] = string[i];
    }
    inverted[length] = '\0'; // Add null terminator
    if (strcmp(string, inverted) == 0)
    {
        printf("SIM");
    } 
    else
    {
        printf("NAO");
    }
    return 0;
}
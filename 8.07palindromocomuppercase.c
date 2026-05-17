#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
int main()
{
    char string[1001];
    fgets(string, 1001, stdin);

    string[strcspn(string, "\n")] = '\0'; // Remove newline character
    int length = strlen(string); // Update length after removing newline

    bool is_palindrome = true;
    for (int i = 0; i < length / 2; i++)
    {
        char c1 = string[i];
        char c2 = string[length - 1 - i];
        // Convert both to lowercase if uppercase
        if (c1 >= 'A' && c1 <= 'Z') 
        {
            c1 += 'a' - 'A';
        }
        if (c2 >= 'A' && c2 <= 'Z') 
        {
            c2 += 'a' - 'A'; //'a' - 'A' = 32
        }
        if (c1 != c2)
        {
            is_palindrome = false;
            break;
        }
    }
    if (is_palindrome)
    {        
        printf("SIM");
    }
    else
    {        
        printf("NAO");
    }
    printf("\n");
    return 0;
}

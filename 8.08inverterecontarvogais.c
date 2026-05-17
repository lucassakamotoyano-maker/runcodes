#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[101];
    fgets(str, 101, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character
    
    int n = strlen(str);
    int vowels = 0;
    
    // Count vowels
    for (int i = 0; i < n; i++)
    {
        char c = tolower(str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels++;
        }
    }

    // Reverse the each word in the string
    int i = 0;
    while (i < n)
    {
        int begin = i;

        // Move to the end of the current word
        while (i < n && str[i] != ' ')
        {
            i++;
        }
        int end = i - 1;

        // Reverse the current word
        while (begin < end)
        {
            char temp = str[begin];
            str[begin] = str[end];
            str[end] = temp;
            begin++;
            end--;
        }

        // Move to the next word
        i++;
    }

    printf("String with reversed words: %s\n", str);
    printf("Number of vowels: %d\n", vowels);

    return 0;
}

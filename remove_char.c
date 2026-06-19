#include <stdio.h>

void remove_char(char string[], char c)
{
    int i, j = 0;
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != c)
        {
            string[j++] = string[i];
        }
    }
   string[j] = '\0'; // Null-terminate the modified string
}
int main()
{
    char text[] = "banana";
    remove_char(text, 'a');
    printf("%s\n", text); 
    return 0;
}
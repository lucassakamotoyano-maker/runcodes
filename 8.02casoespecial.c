#include <stdio.h>
#include <string.h>

int main(void) 
{
    char s[1002];
    char remove;
    int i, j = 0;

    fgets(s, sizeof(s), stdin);

    s[strcspn(s, "\n")] = '\0'; // Remove newline character

    scanf("%c", &remove);

    for(i = 0; s[i] != '\0'; i++) 
    {
        if(s[i] != remove && s[i] != '\n') 
        {
            s[j] = s[i];
            j++;
        }
    }

    s[j] = '\0'; // Null-terminate the modified string

    if(s[0] != '\0')
    {
        printf("%s", s);
    }   

    return 0;
}
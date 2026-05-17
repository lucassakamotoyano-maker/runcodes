#include <stdio.h>
#include <string.h>
int main() 
{
    char str1[] = "Hello"; // H + e + l + l + o + \0, namely 6 characters
    char str2[20] = "World";
    char str3[40];
    // Concatenate str1 and str2 into str3  
    strcat(str3, str1);
    strcat(str3, " ");
    strcat(str3, str2);
    printf("Concatenated String: %s\n", str3);
    
    printf("Length of str3: %lu\n", strlen(str3)); // strlen() does not count the null terminator

    strcmp(str1, str2) == 0 ? printf("str1 and str2 are equal\n") : printf("str1 and str2 are not equal\n");
    strcmp(str1, str2) < 0? printf("str1 is less than str2\n") : printf("str1 is not less than str2\n");
    //H is less than W in ASCII, so str1 is less than str2
    
    return 0;
}
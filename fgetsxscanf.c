#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);//"abc" is read a + b + c + \n + \0, namely 5 characters
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character

    printf("Enter second string: ");
    scanf("%s", str2); // "abc" is read a + b + c + \0, namely 4 characters

    if (strcmp(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
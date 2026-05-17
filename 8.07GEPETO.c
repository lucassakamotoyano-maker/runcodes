#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1001];

    scanf("%s", s);

    int i = 0;
    int j = strlen(s) - 1;
    int palindromo = 1;

    while (i < j) {
        if (tolower(s[i]) != tolower(s[j])) {
            palindromo = 0;
            break;
        }
        i++;
        j--;
    }

    if (palindromo) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }

    return 0;
}   
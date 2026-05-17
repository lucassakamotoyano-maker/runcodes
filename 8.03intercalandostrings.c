#include <stdio.h>
#include <string.h>

int main() {
    char A[1001], B[1001];

    scanf("%s", A);
    scanf("%s", B);

    int i = 0;

    // enquanto ambas têm caracteres
    while (A[i] != '\0' && B[i] != '\0') {
        printf("%c%c", A[i], B[i]);
        i++;
    }

    // se A ainda tem caracteres
    while (A[i] != '\0') {
        printf("%c", A[i]);
        i++;
    }

    // se B ainda tem caracteres
    while (B[i] != '\0') {
        printf("%c", B[i]);
        i++;
    }

    printf("\n");

    return 0;
}
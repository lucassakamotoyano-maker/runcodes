#include <stdio.h>
#include <string.h>

int main() {
    char A[1001], B[1001];

    scanf("%s", A);
    scanf("%s", B);

    if (strstr(A, B) != NULL) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char A[1001], B[1001];

    fgets(A, 1001, stdin); // Read the first string, including spaces
    fgets(B, 1001, stdin); // Read the second string, including spaces
    
    if (strstr(A, B) != NULL) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    

    return 0;
}
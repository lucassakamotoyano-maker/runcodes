#include <stdio.h>

int main() {
    char A[1000], B[1000];
    int i, j, encontrou = 0;

    // Lendo as duas strings
    // Usamos %[^\n] para ler a linha inteira incluindo espaços, se necessário
    scanf(" %[^\n]", A);
    scanf(" %[^\n]", B);

    // Percorre a string A
    for (i = 0; A[i] != '\0'; i++) {
        // Para cada posição de A, tenta comparar com B
        j = 0;
        while (B[j] != '\0' && A[i + j] != '\0' && A[i + j] == B[j]) {
            j++;
        }

        // Se chegamos ao fim de B, significa que todos os caracteres bateram
        if (B[j] == '\0') {
            encontrou = 1;
            break; // Já encontramos, podemos parar
        }
    }

    // Saída conforme o enunciado (1 ou 0)
    printf("%d\n", encontrou);

    return 0;
}
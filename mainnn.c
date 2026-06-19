#include<stdio.h>
#include<string.h>

#include "manipula_string.h"
int main()
{
    char string[100];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0';
    int tamanho = tamanho_strring(string);
    printf("O tamanho da string é: %d\n", tamanho);
    return 0;
}
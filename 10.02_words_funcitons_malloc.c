#include <stdio.h>
#include <stdlib.h>

//function prototypes
int tamanho_str(char palavra[]);
int eh_vogal(char c);
int eh_letra(char c);
int contar_vogais(char palavra[]);
int contar_consoantes(char palavra[]);
void inverter(char palavra[], char invertida[]);
int eh_palindromo(char palavra[]);
char * para_maiusculas(char palavra[]);


int main()
{
    char palavra[101], invertida[101], *p_maiuscula;
    int i = 0;
    
    scanf("%100s", palavra);

    if (eh_palindromo(palavra))
    {
        printf("Palindromo: SIM\n");
    }
    else
    {
        printf("Palindromo: NAO\n");
    }

    printf("Vogais: %d | Consoantes: %d\n", contar_vogais(palavra), contar_consoantes(palavra));

    p_maiuscula = para_maiusculas(palavra);

    printf("Maiuscula: %s\n", p_maiuscula);

    inverter(palavra, invertida);

    printf("Invertida: %s\n", invertida);

    free(p_maiuscula);
    
    return 0;
}

int tamanho_str(char palavra[])
{
    int tam = 0;

    while (palavra[tam] != '\0')
    {
        tam++;  
    }

    return tam;
}

int eh_vogal(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c = c + 32;
    }

    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int eh_letra(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int contar_vogais(char palavra[])
{
    int cont = 0;

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (eh_vogal(palavra[i]))
        {
            cont++;
        }
    }

    return cont;
}

int contar_consoantes(char palavra[])
{
    int cont = 0;

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (eh_letra(palavra[i]) && !eh_vogal(palavra[i]))
        {
            cont++;
        }
    }

    return cont;
}

void inverter(char palavra[], char invertida[])
{
    int tamanho = tamanho_str(palavra);

    for (int i = tamanho - 1; i >= 0; i--)
    {
        invertida[tamanho - i - 1] = palavra[i];
    }

    invertida[tamanho] = '\0';
}

int eh_palindromo(char palavra[])
{
    int tamanho = tamanho_str(palavra);

    for (int i = 0; i < tamanho / 2; i++)
    {
        if (palavra[i] != palavra[tamanho - i - 1])
        {
            return 0;
        }
    }

    return 1;
}

char * para_maiusculas(char palavra[])
{
    int tam = tamanho_str(palavra);
    
    char * resultado = (char*) malloc( (tam+1) * sizeof(char) );
    
    for (int i = 0; i < tam; i++)
    {
        if (palavra[i] >= 'a' && palavra[i] <= 'z')
        {
            resultado[i] = palavra[i] - 32;
        }
        else
        {
            resultado[i] = palavra[i];
        }
    }

    resultado[tam] = '\0';
    return resultado;
}


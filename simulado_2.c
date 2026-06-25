/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int pontos;
    int gols_marcados;
    int gols_sofridos;
} Time;

int main()
{
    Time times[100];
    int n, i, q;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", times[i].nome);
        scanf("%d", &times[i].pontos);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }
    
    scanf("%d", &q);
    char nome2[50], atribut[30];
    int saldo, j;
    
    for(i = 0; i < q; i++) {
        scanf("%s %s", nome2, atribut);
        for(j = 0; j < n; j++) {
            if(strcmp(times[j].nome, nome2) == 0) {
                if(strcmp(atribut, "pontos") == 0) {
                    printf("%d\n", times[j].pontos);
                }
                if(strcmp(atribut, "gols_sofridos") == 0) {
                    printf("%d\n", times[j].gols_sofridos);
                }
                if(strcmp(atribut, "gols_marcados") == 0) {
                    printf("%d\n", times[j].gols_marcados);
                }
                if(strcmp(atribut, "saldo") == 0) {
                    saldo = times[j].gols_marcados - times[j].gols_sofridos;
                    printf("%d\n", saldo);
                }
            }
            saldo = 0;
        }
    }

    return 0;
}
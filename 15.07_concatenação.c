#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    
    FILE *arquivo1 = fopen("notas1.txt", "a"); //append
    FILE *arquivo2 = fopen("notas2.txt", "r"); //read
    
    char caractere;
    
    while ((caractere = fgetc(arquivo2)) != EOF) 
    {
        fputc(caractere, arquivo1); 
    }

    int indice_desejado;
    scanf("%d", &indice_desejado);

    FILE *arquivo_unificado = fopen("notas1.txt", "r");
   
    char nome[55]; 
    float nota1, nota2;
    int indice_atual = 0;
    int encontrou = false; 

    while (true)
    {
        int leituras = fscanf(
            arquivo_unificado,
            " %54[^,],%f,%f",
            nome,
            &nota1,
            &nota2
        );

        if (leituras != 3)
        {
            break;
        }

        if (indice_atual == indice_desejado)
        {
            float media = (nota1 + nota2) / 2.0;
            printf("%s - %.2f\n", nome, media);
            encontrou = true;
            break;
        }

        indice_atual++;
    }


    if (encontrou == false) 
    {
        printf("Indice fora da lista de alunos.\n");
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivo_unificado);

    return 0;
}
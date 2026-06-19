#include <stdio.h>

int main()
{
    struct Aluno
    {
        char nome[50];
        float nota;
    };
    struct Aluno turma[100]; //declaration of an array of 100 structs of type Aluno

    strcpy(turma[0].nome, "Joao"); //we can access the members of the struct using the dot operator
    turma[0].nota = 8.5;

    printf("Nome: %s\n", turma[0].nome);
    printf("Nota: %.2f\n", turma[0].nota);
    return 0;
}
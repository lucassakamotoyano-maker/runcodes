#include <stdio.h>

typedef struct {
    int id;
    float nota;
} Aluno;

int main()
{
	FILE *fp;
	fp = fopen("dados.bin", "rb"); // Leitura binária (Read Binary)
	
	if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

	Aluno a2;

	fread(&a2, sizeof(Aluno), 1, fp);

	printf("ID: %d, Nota: %.2f\n", a2.id, a2.nota);	
	
	fclose(fp);

	return 0;	
}

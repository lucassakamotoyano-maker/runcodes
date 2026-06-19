#include <stdio.h>

typedef struct
{
    int ID;
    float nota;
} Aluno;

int main()
{
	FILE *fp;
	fp = fopen("dados.bin", "wb"); // Escrita binário (Write Binary) - cira o arquivo, se não existir, ou sobrescreve, caso exista
	//rb - leitura binária (abre o arquivo para leitura, falha se ele não existir)
	//ab - escrita binária no final (anexar), cria o arquivo se não existir
    if (fp == NULL)
	{
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}

    Aluno aluno1 = {17907934, 8.5}; //inicializando a struct 
	
    fwrite(&aluno1, sizeof(Aluno), 1, fp); // Escreve os dados da struct no arquivo binário
	fclose(fp);

	return 0;	
}
  
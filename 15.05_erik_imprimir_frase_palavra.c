/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "avaliador.h"

int main()
{
	FILE *entrada, *saida;
	char file1[100], file2[100], palavra[100];
	char linhas1[100], linhas2[100];

	scanf("%s %s %s", file1, file2, palavra);

	entrada = fopen(file1, "r");
	saida = fopen(file2, "w");

	while(fgets(linhas1, sizeof(linhas1), entrada) != NULL) 
	{
		if(strcasestr(linhas1, palavra) != NULL) // if the word is not found, strcasestr returns NULL
		{
			fprintf(saida, "%s", linhas1);
		}
	}

	fclose(entrada);
	fclose(saida);

	arquivo_finalizado(file2);

	return 0;
}
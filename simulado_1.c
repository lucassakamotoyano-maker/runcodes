/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int cedulas[6] = {200, 100, 50, 10, 2, 1};

int decomponha(int dinheiro, int cedula);
int funcao_resto(int dinheiro, int cedula);


int main()
{
    int N;
    scanf("%d", &N);
    
    int resto = N;
    
    for (int i = 0; i < 6; i++)
    {
        int qtd_cedulas = decomponha(resto, cedulas[i]);
        resto = funcao_resto(resto, cedulas[i]);
        if (qtd_cedulas == 0)
        {
            continue;
        }
        else
        {
            printf("%d nota(s)/moeda(s) de R$%d", qtd_cedulas, cedulas[i]);
            printf("\n");
        }
        
    }

    return 0;
}

int decomponha(int dinheiro, int cedula)
{

    return dinheiro / cedula;
}
int funcao_resto(int dinheiro, int cedula)
{
    return dinheiro % cedula;
}
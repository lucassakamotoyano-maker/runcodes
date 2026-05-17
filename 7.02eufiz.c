#include<stdio.h>
//Geralmente, o valor 0 é tratado como false, enquanto qualquer número diferente de zero é tratado como true.
int main()
{
    int N;
    scanf("%d",&N);

    int A[N],B[N];

    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++)
    {
       scanf("%d",&B[i]);
    }

    for(int i=0;i<N;i++)
    {   
        int found = 0; // Variável para indicar se o número já foi encontrado

        for(int j=0;j<N;j++)
        {
            
            if(A[i] == B[j])
            {
                found = 1;
                break; // Sai do loop interno se o número for encontrado
            }
        }
        if(!found)
            {
                printf("0\n");
                return 0; // Encerra o programa se um número não for encontrado
            }
    }
    printf("1\n");
    return 0;
}
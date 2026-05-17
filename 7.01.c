#include<stdio.h>
int main()
{
    int maior_num, j;
    scanf("%d", &maior_num);
    int num[8];
    j = 0;
    num[0] = maior_num;
    for(int i=1; i<8; i++)
    {
        scanf("%d", &num[i]);
        if(num[i] > maior_num)
        {
            maior_num = num[i];
            j = i;
        }

    }
    for(int i=0; i<8; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n%d\n%d\n", num[j], j);
    return 0; 
}
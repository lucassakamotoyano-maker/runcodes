#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int maior = n;
    int menor = n;

    do {    
        if (n > maior) {
            maior = n;
        }
        if (n < menor) {
            menor = n;
        }
        scanf("%d",&n);

    } while (n>0);
    printf("%d %d",maior,menor);

    return 0;
}
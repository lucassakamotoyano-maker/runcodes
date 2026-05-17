#include <stdio.h>

void funcPorValor(int a)
{
    a=1;
}
void funcPorReferencia(int *a)
{
    *a=1;
}
void funcPorRefer(int*b)
{
    *b = 2;
}
int main()
{
    int x = 0, y = 0;
    funcPorValor(x);
    printf("%d\n",x);
    funcPorReferencia(&x);
    printf("%d\n",x);

    funcPorValor(y);
    printf("%d%d\n",y,x);
    funcPorRefer(&y);
    printf("%d%d\n",y,x);

    return 0;
}
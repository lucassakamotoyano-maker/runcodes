#include <stdio.h>
int main()
{
    int x = 10;
    int *pi,*pj;

    pi = &x;
    pj = pi;
    (*pi)++;
    (*pj)++;
    printf("%d\n",x);
    return 0;
}
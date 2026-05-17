#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int *p = &a; // p é um ponteiro para a variável a
    printf("Valor de a: %d\n", a);
    printf("Endereço de a: %p\n", (void*)&a);
    printf("Valor do ponteiro p: %p\n", (void*)p);
    printf("Valor apontado pelo ponteiro p: %d\n", *p);

    printf("&a = %p, &b = %p, &c = %p\n", (void*)&a, (void*)&b, (void*)&c);
    return 0;
}
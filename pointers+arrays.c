#include <stdio.h>

int main()
{
    float m[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float *p = &m[2]; // p aponta para o terceiro elemento de m
    printf("%f\n", *p); // imprime o valor apontado por p (3.0)
    p++; // avança o ponteiro para o próximo elemento
    printf("%f\n", *p); // imprime o valor apontado por p (4.0)
    printf("%f\n", p[1]); // imprime o valor do elemento seguinte ao apontado por p (5.0)
    //p[1] <=> *(p + 1) <=>(p + 1)[0] <=>(m[4]) <=>(5.0)
    return 0;
}
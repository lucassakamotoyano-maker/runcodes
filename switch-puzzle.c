#include <stdio.h>

int main()
{
    int op = 2;

    switch(op)
    {
        case 1:
            printf("A ");
        case 2:
            printf("B "); //como não há break, o código continua a execução
        case 3:
            printf("C "); 
            break;
        default:
            printf("D ");
    }
    return 0;
}
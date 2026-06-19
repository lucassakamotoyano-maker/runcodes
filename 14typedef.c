#include <stdio.h>

int main()
{
    typedef unsigned int uint; //we can use uint as an alias for unsigned int
    uint n = 10; //Equivalent to unsigned int n = 10;

    typedef float real;
    real pi = 3.14; //Equivalent to float pi = 3.14;
    typedef float space;
    typedef float time;
    space s = 45.6;
    time t = 12.3;

    float velocity = s / t;
    printf("Velocidade: %.2f\n", velocity);

    typedef struct
    {
        char marca[21];
        char modelo[21];
        int ano;
        float preco;
    } Carro; //we can use Carro as an alias for the struct
    Carro carro1; //Equivalent to struct Carro carro1;
    strcpy(carro1.marca, "Toyota");
    strcpy(carro1.modelo, "Corolla");
    carro1.ano = 2020;
    carro1.preco = 20000.0;
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

int main()
{
    typedef struct Wagen //
    {
        char marca[16];
        char modelo[16];
        int ano;
        float preco;
        
    } Carro;//we can use Carro as an alias for struct Wagen
 
    Carro carros[5];

    for (int i = 0; i < 5; i++)
    {
        scanf(" %s", carros[i].marca); //strings don't require the & operator, as the name of the array is already a pointer to the first element
        scanf(" %s", carros[i].modelo);
        scanf(" %d", &carros[i].ano);
        scanf(" %f", &carros[i].preco);
    }

    float preco_máximo;
    scanf("%f", &preco_máximo);

    bool encontrou = 0;

    for (int i = 0; i < 5; i++)
    {
        if (carros[i].preco < preco_máximo)
        {
            printf("%s %s %d %.2f\n", carros[i].marca, carros[i].modelo, carros[i].ano, carros[i].preco);
            encontrou = true;
        }
    }
    
    if (encontrou == false)
    {
        printf("Nenhum veiculo encontrado\n");
    }

    return 0;
}
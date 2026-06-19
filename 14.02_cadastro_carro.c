 #include <stdio.h>
#include <stdbool.h>

int main()
{
    typedef struct Wagen //
    {
        char marca[21];
        char modelo[21];
        int ano;
        char cor[21];
        float preco;
            
    } Carro;

    Carro car;
    
    scanf(" %s", car.marca); 
    scanf(" %s", car.modelo);
    scanf(" %d", &car.ano);
    scanf(" %s", car.cor);
    scanf(" %f", &car.preco);
    
        
    int ID;
    scanf(" %d", &ID); 

    switch(ID)
    {
        case 1:
            scanf(" %s", car.marca);
            break;
        case 2:
            scanf(" %s", car.modelo);
            break;
        case 3:
            scanf(" %d", &car.ano);
            break;
        case 4:
            scanf(" %s", car.cor);
            break;
        case 5:
            scanf(" %f", &car.preco);
            break;
    }
    
    printf("%s\n%s\n%d\n%s\n%.2f\n", car.marca, car.modelo, car.ano, car.cor, car.preco);
    return 0;
}
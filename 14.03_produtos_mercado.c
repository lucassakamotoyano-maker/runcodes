#include <stdio.h>

typedef struct 
    {
        int ID; 
        float price;
        float weight;
        int day;
        int month;
        int year;
    }product;

void printProduct(product p);

int main()
{
    

    int N;
    scanf("%d", &N);
    if (N <= 0)
        {
            return 0;
        }
    product produto[N];   

    for (int i = 0; i < N; i++)
    {
        scanf(" %d %f %f %d %d %d", 
            &produto[i].ID,
            &produto[i].price, 
            &produto[i].weight, 
            &produto[i].day, 
            &produto[i].month, 
            &produto[i].year);
    }

    //inicializando os índices dos maiores valores
    int maiorID = 0, 
        maiorPreco = 0, 
        maiorPeso = 0, 
        maiorData = 0,
        melhorData =
            produto[maiorData].year * 10000 +
            produto[maiorData].month * 100 +
            produto[maiorData].day;

    for(int i = 1; i < N; i++)
    {
        if(produto[i].ID > produto[maiorID].ID)
            maiorID = i;

        if(produto[i].price > produto[maiorPreco].price)
            maiorPreco = i;

        if(produto[i].weight > produto[maiorPeso].weight)
            maiorPeso = i;

        // comparação de datas
        int dataAtual =
            produto[i].year * 10000 +
            produto[i].month * 100 +
            produto[i].day;

        if(dataAtual > melhorData)
        {
            maiorData = i;
            melhorData = dataAtual;
        }
    }
    
    printProduct(produto[maiorID]);
    printProduct(produto[maiorPreco]);
    printProduct(produto[maiorPeso]);
    printProduct(produto[maiorData]);

    return 0;
}

void printProduct(product p)
{
    printf("%d - %.2f - %.1f - %02d/%02d/%04d\n", 
        p.ID, 
        p.price, 
        p.weight, 
        p.day, 
        p.month, 
        p.year);
}
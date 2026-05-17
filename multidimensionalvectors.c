#include <stdio.h>

#define ALTURA 3
#define LARGURA 2
#define CANAIS 3

int main()
{
    int IMAGEM[ALTURA][LARGURA][CANAIS] = 
    {
        { {255, 0, 0}, {0, 255, 0} },// Red and Green
        { {0, 0, 255}, {255, 255, 0} },// Blue and Yellow
        { {255, 0, 255}, {0, 255, 255} }// Magenta and Cyan
    };

    for(int i = 0; i < ALTURA; i++)
    {
        printf("Row %d:\n", i + 1);
        for(int j = 0; j < LARGURA; j++)
        {
            printf("(%3d, %3d, %3d) ", IMAGEM[i][j][0], IMAGEM[i][j][1], IMAGEM[i][j][2]);
        }
        printf("\n");
    }
    return 0;
}
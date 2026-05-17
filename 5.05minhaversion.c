#include<stdio.h>
int main()
{
    int movimentos;
    scanf("%d", &movimentos);

    int frontal, esquerda, direita; //sensores

    int x = 0, y = 0;
    // posição inicial do robô é (0,0)

    int direcao = 0;
    // direcao: 0 oeste, 1 sul, 2 leste, 3 norte

    for(int i = 0; i < movimentos; i++)
    {   
        scanf("%d %d %d", &frontal, &esquerda, &direita);
        
        switch (direcao)
        {
        case 0:
            if (frontal==0)
            {
                x++;    
            }
            else if(direita==1 && esquerda==0)
            {
                direcao = 3;
            }          
            else
            {
                direcao = 1;
            }
            break;
        case 1:
            if (frontal==0)
            {
                y--;
            }
            else if(direita==1 && esquerda==0)
                {
                    direcao = 0;
                }          
                else
                {
                    direcao = 2;
                }
            break;
        case 2:
            if (frontal==0)
            {
                x--;
            }
            else if(direita==1 && esquerda==0)
                {
                    direcao = 1;
                }          
                else
                {
                    direcao = 3;
                }
            break;
        case 3:
            if (frontal==0)
            {
                y++;
            }
            else if(direita==1 && esquerda==0)
                {
                    direcao = 2; 
                }          
            else
                {
                    direcao = 0;
                }
            break;
        }
    }
    printf("%d %d\n", x, y);
    return 0;
}
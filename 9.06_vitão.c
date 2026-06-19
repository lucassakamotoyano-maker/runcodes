#include <stdio.h>
#include <string.h>

int main()
{
    int tabuleiro[8][8];
    char podem_capturar[1000]="", bloqueadas[1000]="", podem_mover[1000]="", coordenada[7]="";
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            scanf("%d",&tabuleiro[i][j]);
            if(tabuleiro[i][j]==-1)
            {
                if(i!=0 && ((tabuleiro[i-1][j-1]==1 && tabuleiro[i-2][j-2]==0 && j>1)||(tabuleiro[i-1][j+1]==1 && tabuleiro[i-2][j+2]==0 && j<6)) )//condi�ao de captura
                {
                    sprintf(coordenada, "(%d,%d) ", i, j);
                    strcat(podem_capturar, coordenada);
                }
                else if(i!=0 && (tabuleiro[i-1][j-1]==0||tabuleiro[i-1][j+1]==0))//condi��o para se mover
                {
                    sprintf(podem_mover+strlen(podem_mover), "(%d,%d) ", i, j);
                }
                else
                {
                    sprintf(bloqueadas+strlen(bloqueadas), "(%d,%d) ", i, j);
                }
            }

        }
    }
    if(podem_capturar[0]=='\0')
    {
        printf("None\n");
    }
    else printf("%s\n",podem_capturar);

    if(podem_mover[0]=='\0')
    {
        printf("None\n");
    }
    else printf("%s\n",podem_mover);

    if(bloqueadas[0]=='\0')
    {
        printf("None\n");
    }
    else printf("%s",bloqueadas);
}
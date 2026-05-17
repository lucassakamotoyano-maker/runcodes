#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
     
    int x = 0, y = 0;
    int dir = 0; // começa em Leste
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for (int i = 0; i < N; i++) 
    {
        int F, E, D;
        scanf("%d %d %d", &F, &E, &D);
        if (F == 0)
        //anda para frente
        {
            x += dx[dir];
            y += dy[dir];
        }
        else
        {
            if (D == 1 && E == 0)
            //vira à esquerda
            {
                dir = (dir + 1) % 4;
            }
            else 
            {
                dir = (dir + 3) % 4;
            }
        }
    }

    printf("%d %d\n", x, y);

    return 0;
}
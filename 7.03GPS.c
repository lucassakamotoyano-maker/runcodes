#include<stdio.h>
#include<math.h>

int main()
    {
    int N;
    scanf("%d",&N);

    int x,y;
    scanf("%d %d",&x,&y);

    float distance = 0.0f;

    for(int i=0;i<N-1;i++)
    {
        int auxx,auxy;
        scanf("%d %d",&auxx,&auxy);
        distance += sqrt(pow(auxx - x, 2) + pow(auxy - y, 2));
        x = auxx;
        y = auxy;


    }
    printf("%.4f\n", distance);
    return 0;
}
#include <stdio.h>
#include <math.h>

int main(){

    int N;
    float distancia = 0.0f;

    scanf("%d", &N);

    int x[N], y[N];

    for (int i = 0; i < N; i++){
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 1; i < N; i++){
        distancia += sqrt( pow(x[i] - x[i - 1], 2) + pow(y[i] - y[i -1], 2));
    }
    printf("%.4f", distancia);



    return 0;
}
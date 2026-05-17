#include <stdio.h>

int main(){

    int soma, matriz[4][5];
    for (int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    for (int j = 0; j < 5; j++){
        soma = 0;
        for (int i =0; i < 4; i++){
            soma += matriz[i][j];
        }
        printf("%d ", soma);
    }

    return 0;
}
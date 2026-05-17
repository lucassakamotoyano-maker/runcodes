#include <stdio.h>

int main() {

    int mat[5][5];
    int mat_3_trans[5][5];

    for(int i=0; i<5; i++) {
        scanf("%d%d%d%d%d", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4]);
    }
    for(int i=0; i<5; i++) {

        for(int j=0; j<5; j++) {
           if(i!=2 && j!=2) {
                mat_3_trans[i][j] = mat[i][j];
           }else {
                mat_3_trans[i][j] = mat[j][i];
           }
           printf("%d ", mat_3_trans[i][j]);
        }
        printf("\n");
    }

return 0;
}
#include <stdio.h>

int main(){

    int mov_totais=0, mov=0, F=0, E=0, D=0, direcao=0, direcao_atual=0, x=0, y=0;
    scanf("%d", &mov_totais);
// leste = 0, sul = 1, oeste = 2, norte = 3

    while(mov<mov_totais) {

        direcao_atual = direcao%4;
        scanf("%d%d%d", &F, &E, &D);

        switch(direcao_atual) {
        case 0:
            if(F==0){
                x ++;
            }else if(F==1 && D==1 && E==0){
                direcao --;
                if(direcao== -1) {
                    direcao = 3;
                }
            }else {
                direcao ++;
            }
            break;
        case 1:
            if(F==0){
                y --;
            }else if(F==1 && D==1 && E==0){
                direcao --;
                if(direcao== -1) {
                    direcao = 0;
                }
            }else {
                direcao ++;
            }
            break;
        case 2:
            if(F==0){
                x --;
            }else if(F==1 && D==1 && E==0){
                direcao --;
                if(direcao== -1) {
                    direcao = 1;
                }
            }else {
                direcao ++;
            }
            break;
        case 3:
            if(F==0){
                y ++;
            }else if(F==1 && D==1 && E==0){
                direcao --;
                if(direcao== -1) {
                    direcao = 2;
                }
            }else {
                direcao ++;
            }
            break;
        }
        mov ++;
    }

    printf("%d %d", x, y);

return 0;
}

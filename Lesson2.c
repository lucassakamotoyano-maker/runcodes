#include <stdio.h>

int main(){

    int num1 = 1;
    int num2 = 10;
    int num3 = 100;
    int num4 = -1;

    printf("%3d\n", num1);
    printf("%-4da\n", num2);
    printf("%04d\n", num3);
    printf("%+d\n", num4);

    float price = 19.99;
    float debt = -100.00;
    printf("%7.1f\n", price);
    printf("%+7.2f\n", debt);


    
    return 0;
}
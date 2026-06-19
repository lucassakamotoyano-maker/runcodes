#include <stdio.h>

int main(){

    int x = 2;
    int y = 3; 
    int z = 1; 
    float h = 3.74;

    //z = x + y;
    //z = x - y; 
    //z = x * y;
    //z = x / y; 0 se for int e  0.666667 se z y forem float
    z = x % y; //%2 indica se é par ou não (modulo)

    //Increment or decrement
    //z++;
    //z--;

    //augmented assigment operators
    //z = z + 2; or z+=2;
    //z-=2;
    //z*=2;
    //z/=2;
    printf("%d\n", x / y);
    printf("%f\n", h - z);

    return 0;   
}

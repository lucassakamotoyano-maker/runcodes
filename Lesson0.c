#include <stdio.h>
#include <stdbool.h> // standard boolean header file

// % format specifier

int main() {
  
    int age = 25;
    float gpa = 2.5;
    double pi = 3.14159265359;
    char grade = 'A';
    char name[] = "Bro Code";
    bool is_Online = true;

    printf("You are %d years old\n", age);
    printf("Your gpa is %.2f\n", gpa);
    printf("The number of pi is approximately %.11lf\n", pi);
    printf("Your grade is %c\n", grade);
    printf("Hello %s\n", name);
    if(!is_Online){
        printf("You are online %d", is_Online);
    }
    else {
        printf("You are offline %d", is_Online);
    }
    

    return 0;
}
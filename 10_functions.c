#include <stdio.h>
int sum(int a, int b);
int factorial(int n);
int square(int x);
void print_message(const char *message);

//prototype declarations 
#define ROWS 3
#define COLUMNS 4
int num1 = 7, num2 = 3; // Global variables
//when calling a function with int or float as parameters,
//the values are passed by value, meaning that a copy of the variable is created and used within the function.
int matrix[ROWS][COLUMNS] = {
    {-1, -2, -3, -4},
    {-5, -6, -7, -8},
    {-9, -10, -11, -12}
};//vectors and matrices, on the other hand, are altered 
//by reference, so we can modify the global matrix directly in the print_matrix procedure



int main()
{
    int num1 = 5, num2 = 10; // Local variables that shadow the global variables
    int result = sum(num1, num2); // Call the sum function
    printf("The sum of %d and %d is %d\n", num1, num2, result);
    
    int n = 5;
    printf("Factorial of %d is %d\n", n, factorial(n)); // Call the factorial function
    
    int x = 4;
    printf("The square of %d is %d\n", x, square(x)); // Call the square function
    
    print_message("Hello, World!"); // Call the print_message procedure
    
    int matrix[ROWS][COLUMNS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("Matrix:\n");
    print_matrix(matrix); // Call the print_matrix procedure
    return 0;
}



int sum(int a, int b)
{
    return a + b; //predicate function to calculate the sum of two integers
}

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1); // Recursive function to calculate factorial
}

int square(int x) //function signature
{
    int resultado;
    resultado = x * x; // Calculate the square of x
    return resultado; // Return the result
}

void print_message(const char *message) //procedure function to print a message to the console
{
    printf("%s\n", message); 
}

void print_matrix(int matrix[][COLUMNS]) //first dimension can be left unspecified
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
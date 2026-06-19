#include <stdio.h>

int main()
{
    //int matrix[][] or matrix[3[] are not valid in C, we need to specify the size of the second dimension
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // This is also valid in C
    int matrix[3][3];// This is valid, but we need to initialize the values later

    char string[] = "Hello, World!"; // This is a valid way to initialize a string in C
    char string2[4] = {'H', 'e', 'l', 'o'}; // This is also valid, but we need to add a null terminator at the end
    //char complete-name = 'a'; // This is not valid, we cannot use a hyphen in variable names

    return 0;
}
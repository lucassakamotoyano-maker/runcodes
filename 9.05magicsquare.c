#include <stdio.h>
#include <stdbool.h>

int main()
{
    size_t n;
    scanf(" %zu", &n); // Read the size of the magic square
    
    int **magicSquare = malloc(n * sizeof(int *)); // Dynamically allocate memory for the magic square, ** because it's a pointer to a pointer (2D array)
    int *sumrows = malloc(n * sizeof(int)); // Dynamically allocate memory for the sum of rows, * because it's a pointer (1D array)
    int *sumcolumns = malloc(n * sizeof(int)); // Dynamically allocate memory for the sum of columns, * because it's a pointer (1D array)
    int sumdiagonal1 = 0, sumdiagonal2 = 0;

    for (size_t i = 0; i < n; i++)
    {
        magicSquare[i] = malloc(n * sizeof(int));
    }

    for (size_t j = 0; j < n; j++)
    {
        sumcolumns[j] = 0; // Initialize sum of columns to 0 before calculating
    }

    for (size_t i = 0; i < n; i++)
    {
        sumrows[i] = 0; // Initialize sum of rows to 0 before calculating
        for (size_t j = 0; j < n; j++)
        {
            scanf(" %d", &magicSquare[i][j]);

            sumrows[i] += magicSquare[i][j];// Accumulate sum of rows

            sumcolumns[j] += magicSquare[i][j]; // Accumulate sum of columns

            if (i == j)
            {
                sumdiagonal1 += magicSquare[i][j]; // Accumulate sum of the main diagonal
            }
            if (i + j == n -1)
            {
                sumdiagonal2 += magicSquare[i][j]; // Accumulate sum of the secondary diagonal
            }
        }
        
    }
    

    if (sumdiagonal1 != sumdiagonal2) // If the sums of the diagonals are not equal, it's not a magic square
    {
        printf("NAO\n");
        // Free dynamically allocated memory

        for (size_t i = 0; i < n; i++)
        {
            free(magicSquare[i]);
        }

        free(magicSquare);
        free(sumrows);
        free(sumcolumns);
    
        return 0;
    }

    bool is_square = true; // Assume it's a magic square until proven otherwise

    for (size_t i = 0; i < n; i++)
    {
        if (sumrows[i] != sumdiagonal1 || sumcolumns[i] != sumdiagonal1)
        {
            is_square = false; // If any row or column doesn't match the diagonal sum, it's not a magic square
            break;
        }
    }

    if (is_square) // if the condition is true, then it's a magic square
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }
    
    return 0;
}
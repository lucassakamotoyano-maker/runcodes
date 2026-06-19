#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    scanf(" %d", &n); // Read the size of the magic square
    
    int magicSquare[n][n];
    int sumrows[n];
    int sumcolumns[n];
    int sumdiagonal1 = 0, sumdiagonal2 = 0;

    for (int j = 0; j < n; j++)
    {
        sumcolumns[j] = 0; // Initialize sum of columns to 0 before calculating
    }

    for (int i = 0; i < n; i++)
    {
        sumrows[i] = 0; // Initialize sum of rows to 0 before calculating
        for (int j = 0; j < n; j++)
        {
            scanf(" %d", &magicSquare[i][j]);

            sumrows[i] += magicSquare[i][j];// Accumulate sum of rows

            sumcolumns[j] += magicSquare[i][j]; // Accumulate sum of columns

            if (i == j)
            {
                sumdiagonal1 += magicSquare[i][j]; // Accumulate sum of the main diagonal
            }
            if (i + j == n -1) // If the sum of the indices equals n-1, it's on the secondary diagonal
            {
                sumdiagonal2 += magicSquare[i][j]; // Accumulate sum of the secondary diagonal
            }
        }
        
    }
    

    if (sumdiagonal1 != sumdiagonal2) // If the sums of the diagonals are not equal, it's not a magic square
    {
        printf("NAO\n");
        return 0;
    }

    int sumdiagonal = sumdiagonal1;//alternatevely: sumdiagonal2

    bool is_square = true; // Assume it's a magic square until proven otherwise

    for (int i = 0; i < n; i++)
    {
        if (sumrows[i] != sumdiagonal || sumcolumns[i] != sumdiagonal)
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
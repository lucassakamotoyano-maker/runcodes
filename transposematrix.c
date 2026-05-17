#include <stdio.h>

int main()
{
    int row, column, matrix[5][5], transpose[5][5];
    printf("Enter the elements of the 5x5 matrix:\n");
    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5; column++)
        {
            printf("Element [%d][%d]: ", row + 1, column + 1);
            scanf("%d", &matrix[row][column]);
        }
    }
    // Creating the transpose
    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5; column++)
        {
            transpose[column][row] = matrix[row][column];
        }
    }
    printf("Transposed matrix:\n");
    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5; column++)
        {
            printf("%d ", transpose[row][column]);
        }
        printf("\n");
    }
    return 0;
}
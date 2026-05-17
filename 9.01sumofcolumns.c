#include <stdio.h>

int main()
{
    int row, column, matrix[4][5], sum[5] = {0};
    printf("Enter the elements of the 4x5 matrix:\n");
    for (row = 0; row < 4; row++)
    {
        for (column = 0; column < 5; column++)
        {
            printf("Element [%d][%d]: ", row + 1, column + 1);
            scanf("%d", &matrix[row][column]);
            sum[column] += matrix[row][column];
        }
    }
    printf("Sum of each column:\n");
    for (column = 0; column < 5; column++)
    {
        printf("Column %d: %d\n", column + 1, sum[column]);
    }
    return 0;
}
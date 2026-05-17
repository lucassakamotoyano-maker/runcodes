#include <stdio.h>

int main()
{
    int row, column, matrix[2][2], determinant;
    printf("Enter the elements of the 2x2 matrix:\n");

    for (row = 0; row < 2; row++)
    {
        for (column = 0; column < 2; column++)
        {
            printf("Element [%d][%d]: ", row + 1, column + 1);
            scanf("%d", &matrix[row][column]);
        }
    }
    
    determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    printf("The determinant of the 2x2 matrix is: %d\n", determinant);

    
    return 0;

}
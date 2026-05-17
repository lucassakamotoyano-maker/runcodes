#include <stdio.h>

int main()
{
    int row, column, matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };

    for (row = 0; row < 2; row++)
    {
        for (column = 0; column < 3; column++)
        {
            printf("\t%d", matrix[row][column]);
        }
        printf("\n");
    }
}
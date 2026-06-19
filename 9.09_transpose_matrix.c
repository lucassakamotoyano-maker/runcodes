#include <stdio.h>

int main()
{
    int row, column;
    scanf("%d %d", &row, &column);

    int matrix[row][column], transpose[column][row];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Creating the transpose
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    

    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}
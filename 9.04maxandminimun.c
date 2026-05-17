#include <stdio.h>

int main()
{
    int row, column, matrix[5][5];

    // Removed redundant initial prompt

    int max, row_max = 0, column_max = 0;

    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5 ; column++)
        {
            
            scanf("%d", &matrix[row][column]);
            if (row == 0 && column == 0) {
                max = matrix[0][0];
                row_max = 0;
                column_max = 0;
            }
            int currentElement = matrix[row][column];
            if (currentElement > max) {
                max = currentElement; 
                row_max = row;
                column_max = column;
            }
        }
    }

    printf("Maximum element: %d at position [%d][%d]\n", max, row_max + 1, column_max + 1);
    return 0;
}
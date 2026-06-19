#include <stdio.h>

int main()
{
    int row, column, matrix[5][5];

    // Removed redundant initial prompt

    int max, row_max, column_max;
    int min, row_min, column_min;

    for (row = 0; row < 5; row++)
    {
        for (column = 0; column < 5 ; column++)
        {
            
            scanf("%d", &matrix[row][column]);
            if (row == 0 && column == 0) {
                max = matrix[0][0];
                row_max = 0;
                column_max = 0;
                min = matrix[0][0];
                row_min = 0;
                column_min = 0;
            }
            int currentElement = matrix[row][column];
            if (currentElement > max) {
                max = currentElement; 
                row_max = row;
                column_max = column;
            }
            if (currentElement < min) 
            {
                min = currentElement; 
                row_min = row;
                column_min = column;
            }
        }
    }

    printf("%d %d %d\n", max, row_max, column_max);
    printf("%d %d %d\n", min, row_min, column_min);
    return 0;
}
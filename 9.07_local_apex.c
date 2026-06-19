#include <stdio.h>
#include <stdbool.h>
#define ROW 0
#define COLUMN 1

bool inside_board(int row, int column, int N)
{
    return row >= 0 && row < N && column >= 0 && column < N;
}

int main()
{
    int N;
    scanf("%d", &N);
    int matrix[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }


    int const board_size = N*N;
    int is_local_apex[board_size][2]; //two coordinates for each local apex
    int local_apex_count = 0;
    int row_direction[4] = {-1, 1, 0, 0};
    int column_direction[4] = {0, 0, -1, 1};
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool local_apex = true;

            for (int direction = 0; direction < 4; direction++)
            {
                int neighbor_row = i + row_direction[direction];
                int neighbor_column = j + column_direction[direction];

                if (inside_board(neighbor_row, neighbor_column, N) &&
                    matrix[i][j] <= matrix[neighbor_row][neighbor_column])
                {
                    local_apex = false;
                    break;
                }
            }

            if (local_apex)
            {
                is_local_apex[local_apex_count][ROW] = i;
                is_local_apex[local_apex_count][COLUMN] = j;
                local_apex_count++;
            }
        }
    }
    for (int i = 0; i < local_apex_count; i++)
    {
        printf("Pico encontrado em [%d][%d]: %d\n", 
            is_local_apex[i][ROW], 
            is_local_apex[i][COLUMN], 
            matrix[is_local_apex[i][ROW]][is_local_apex[i][COLUMN]]);
    }
    return 0;
}

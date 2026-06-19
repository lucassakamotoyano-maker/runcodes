#include <stdio.h>
#include <stdbool.h>

//MACROS for better readability, maintainability and to avoid magic numbers in the code
#define MAX_PIECES 64
#define ROW 0
#define COLUMN 1
#define COORDINATES 2  

void print_positions(int positions[MAX_PIECES][COORDINATES], int count)
{
    if (count == 0)
    {
        printf("None\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("(%d,%d)", positions[i][0], positions[i][1]);
    }
    printf("\n");
}

bool inside_board(int i, int j)
{
    return i >= 0 && i < 8 && j >= 0 && j < 8;
}

int main() 
{
    int matrix[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            scanf(" %d", &matrix[i][j]);
        }
    }

    int can_capture[MAX_PIECES][COORDINATES];
    int can_move[MAX_PIECES][COORDINATES];
    int cannot_move[MAX_PIECES][COORDINATES];
    int capture_count = 0;
    int move_count = 0;
    int blocked_count = 0;

    int directions[2] = {-1, 1};
    
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (matrix[i][j] == -1)
            {
                bool captures = false;
                bool moves = false;

                for (int d = 0; d < 2; d++)
                {
                    int next_i = i - 1;
                    int next_j = j + directions[d];
                    int after_i = i - 2;
                    int after_j = j + 2 * directions[d];

                    if (inside_board(next_i, next_j) && matrix[next_i][next_j] == 0)
                    {
                        moves = true;
                    }

                    if (inside_board(next_i, next_j) &&
                        inside_board(after_i, after_j) &&
                        matrix[next_i][next_j] == 1 &&
                        matrix[after_i][after_j] == 0)
                    {
                        captures = true;
                    }
                }

                if (captures)
                {
                    can_capture[capture_count][ROW] = i;
                    can_capture[capture_count][COLUMN] = j;
                    capture_count++;
                }
                else if (moves)
                {
                    can_move[move_count][ROW] = i;
                    can_move[move_count][COLUMN] = j;
                    move_count++;
                }
                else
                {
                    cannot_move[blocked_count][ROW] = i;
                    cannot_move[blocked_count][COLUMN] = j;
                    blocked_count++;
                }
            }
        }
    }

    print_positions(can_capture, capture_count);
    print_positions(can_move, move_count);
    print_positions(cannot_move, blocked_count);

    return 0;
}

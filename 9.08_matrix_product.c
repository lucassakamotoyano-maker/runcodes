#include <stdio.h>

int main()
{
    int rowsA, columnsA, rowsB, columnsB;
    scanf("%d %d", &rowsA, &columnsA);
    scanf("%d %d", &rowsB, &columnsB);

    int matrixA[rowsA][columnsA];
    int matrixB[rowsB][columnsB];

    if(columnsA != rowsB)
    {
        printf("Produto inexistente");
        return 0;
    }

    int intermediate = columnsA; //alternatevely: intermediate = rowsB;

    //receiving elements of matrix A
    for(int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < columnsA; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }

    //receiving elements of matrix B
    for(int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < columnsB; j++)
        {
            scanf("%d", &matrixB[i][j]);
        }
    }

    //initializing the product matrix to prevent undefined behaviour
    int A_times_B[rowsA][columnsB];

    for(int i = 0; i < rowsA; i++) 
    {
        for (int j = 0; j < columnsB; j++)
        {
            A_times_B[i][j] = 0;
        }
    }

    //computing the product matrix
    for(int i = 0; i < rowsA; i++)  //for every row in A
    {
        for (int j = 0; j < columnsB; j++) //for every column in B
        {
            for (int k = 0; k < intermediate; k++) 
            {
                A_times_B[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    
    //printing the product matrix
    for(int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < columnsB; j++)
        {
            printf("%d ", A_times_B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
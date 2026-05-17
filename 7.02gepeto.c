#include <stdio.h>

int main()
{   
    int N;
    scanf("%d", &N);

    int A[N], B[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }
    for (int i = 0; i < N; i++)
    {
        int found = 0;

        for (int j = 0; j < N; j++)
        {
            if (A[i] == B[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
        {
            printf("0\n");
            return 0;
        }
    }

    printf("1\n");

    return 0;
}
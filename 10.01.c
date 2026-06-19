#include <stdio.h>

// standard boolean header file
#include <stdbool.h>

//function prototypes for the functions defined in functions.c, which will be used in main.c
int max_and_min(int vector[], int N, int *max, int *min);
bool is_even(int number);
double average(int vector[], int N);
int above_average(int vector[], double average, int N);


//main code
int main()
{
    int N;
    scanf("%d", &N);

    int vector[N];

    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &vector[i]);
    }

    int pares = 0, impares = 0;
    for(int i = 0; i < N; i++)
    {
        if(is_even(vector[i]))
        {
            pares++;
        }
        else
        {
            impares++;
        }
    }
    printf("Pares: %d | Impares: %d\n", pares, impares);

    int max, min;
    max_and_min(vector, N, &max, &min);
    printf("Maior: %d | Menor: %d\n", max, min);

    double avg = average(vector, N);
    printf("Media: %.2f\n", avg);
    printf("Acima da media: %d\n", above_average(vector, avg, N));
    
    return 0;
}


int max_and_min(int vector[], int N, int *max, int *min)
{
    *max = vector[0];
    *min = vector[0];
    for (int i = 1; i < N; i++)
    {
        if (vector[i] > *max)
        {
            *max = vector[i];
        }
        if (vector[i] < *min)
        {
            *min = vector[i];
        }
    }
    return 0; // function to find the maximum and minimum values in an array of integers
}

bool is_even(int number)
{
    return number % 2 ==0; //predicate function to check if a number is even
}

double average(int vector[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += vector[i];
    }
    double q = N; // convert N to float to avoid integer division
    return sum / q; // function to calculate the average of an array of integers
}

int above_average(int vector[], double average, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (vector[i] > average)
        {
            count++;
        }
    }
    return count; // function to count how many numbers in an array are above the average
}

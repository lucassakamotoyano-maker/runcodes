#include <stdio.h>

// Function prototypes
float square(float x);
float square_root(float x);
float sum(const float vector[], int n);
float average(const float vector[], int n);
float std_deviation(const float vector[], int n);

int main()
{
    int N;
    scanf("%d", &N);

    if (N <= 0)
    {
        return 0;
    }

    float vetor[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &vetor[i]);
    }

    float soma = sum(vetor, N);
    float media = average(vetor, N);
    float desvio = std_deviation(vetor, N);

    printf("Soma: %.2f\nMedia: %.2f\nDesvio: %.2f\n", soma, media, desvio);

    return 0;
}

float square(float x)
{
    return x * x;
}

float square_root(float x)
{
    if (x == 0)
    {
        return 0;
    }

    float approximation = x > 1 ? x : 1.0f;

    for (int i = 0; i < 100; i++)
    {
        float next_approximation = (approximation + x / approximation) / 2;

        if (next_approximation == approximation)
        {
            break;
        }

        approximation = next_approximation;
    }

    return approximation;
}

float sum(const float vector[], int n)
{
    float total = 0;

    for (int i = 0; i < n; i++)
    {
        total += vector[i];
    }

    return total;
}

float average(const float vector[], int n)
{
    return sum(vector, n) / n;
}

float std_deviation(const float vector[], int n)
{
    float vector_average = average(vector, n);
    float sum_of_squares = 0;

    for (int i = 0; i < n; i++)
    {
        sum_of_squares += square(vector[i] - vector_average);
    }

    return square_root(sum_of_squares / n);
}

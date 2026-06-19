#include <stdio.h>

//MACROS 
#define PI 3.14159
#define AREA_CIRCLE(r) (PI * (r) * (r))
#define DOUBLE(x) ((x) * 2)
// DOUBLE(x) x * 2 would compute 5 + 3 * 2 = 11



int main()
{
    double radius = 2.0;
    double area = AREA_CIRCLE(radius);
    printf("Area: %lf\n", area);

    int result = DOUBLE(5 + 3); // (5 + 3) * 2 = 16
    printf("Double: %d\n", result);

    #ifdef _WIN32
        printf("Running on Windows\n");
    #elif __linux__
        printf("Running on Linux\n");
    #elif __APPLE__
        printf("Running on macOS\n");
    #endif
    return 0;
}

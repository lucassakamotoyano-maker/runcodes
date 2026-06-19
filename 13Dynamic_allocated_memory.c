#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *v;
    v = (int*)malloc(10*sizeof(int));//cast operation is optional in c but mandatory in c++

    //v = (void*)malloc(10*sizeof(int)); is also valid but it is not recommended to use void* in c as it can lead to type safety issues
    //v = (int*)calloc(10,sizeof(int)); is equivalent to above line but it initializes all the elements to 0
    if(v==NULL) //if there is no memory available, malloc returns NULL
    {        
        printf("Memory not allocated\n");
        exit(0);
    }

    for(int i=0;i<10;i++)
    {        
        v[i] = i+1;
    }    
    
    printf("The elements of the array are: ");

    for(int i=0;i<10;i++)
    {        
        printf("%d ",v[i]);
    }   
    printf("\n");
    
    free(v);//deallocating the memory

    int n;
    printf("What size of memory is allocated for the array?");
    scanf("%d", &n);
    
    v = (int*)malloc(n*sizeof(int)); //allocating memory for n integers
    
    //int v[n]; is not valid in c as the size of the array must be a constant expression
    
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &v[i]);
    }

    printf("The elements of the array are: ");

    for(int i=0;i<n;i++)
    {
        printf("%d ", v[i]);
    }

    free(v); //memory leak occurs if we do not free the allocated memory

    return 0;
}
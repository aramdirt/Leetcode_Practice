#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARR_SIZE 10
#define RANGE    50

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void selection_sort(int *arr, int size)
{
    int i, j, min;
    for (i=0; i<size-1; i++)
    {
        min = i;
        for (j=i+1; j<size; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(&arr[min], &arr[i]);
    }
    return;
}

void print_array(int *arr, int arr_size)
{
    int i;

    for (i=0; i<arr_size; i++)
        printf("%d\n", arr[i]);

    return;
}

int main()
{
    int i;
    int *array = malloc(sizeof(int)*ARR_SIZE);

    srand(time(NULL));
    for (i=0; i<ARR_SIZE; i++)
        array[i] = rand()%RANGE;

    printf("Before sorting\n");
    print_array(array, ARR_SIZE);

    selection_sort(array, ARR_SIZE);

    printf("After sorting\n");
    print_array(array, ARR_SIZE);

    free(array);
    return 0;
}
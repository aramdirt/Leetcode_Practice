#include <stdio.h>
#include <stdlib.h>
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

void bubble_sort(int *arr, int size)
{
    int i, j, swap_flag;
    for (i=0; i<size-1; i++)
    {
        swap_flag = 0;
        for (j=0; j<size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swap_flag = 1;
            }
        }
        if (!swap_flag)
            break;
    }
    return;
}

int main()
{
    int i;
    int *array = malloc(sizeof(int)*ARR_SIZE);

    srand(time(NULL));
    for (i=0; i<ARR_SIZE; i++)
        array[i] = rand()%RANGE;

    bubble_sort(array, ARR_SIZE);

    for (i=0; i<ARR_SIZE; i++)
        printf("%d\n", array[i]);

    free(array);
    return 0;
}
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

int partition(int *arr, int low, int high)
{
    int i, j, pivot;
    pivot = arr[high];
    j = low - 1;

    for (i=low; i<high; i++)
    {
        if (arr[i] < pivot)
            swap(&arr[i], &arr[++j]);
    }
    swap(&arr[++j], &arr[high]);
    return j;
}

void quick_sort(int *arr, int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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

    quick_sort(array, 0, ARR_SIZE-1);

    printf("After sorting\n");
    print_array(array, ARR_SIZE);

    free(array);
    return 0;
}
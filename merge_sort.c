#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARR_SIZE 10
#define RANGE    50

void merge(int *arr, int low, int mid, int high)
{
    int i, j ,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1];
    int R[n2];

    for (i=0; i<n1; i++)
        L[i] = arr[low + i];

    for (i=0; i<n2; i++)
        R[i] = arr[mid + 1 + i];

    i = j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return;
}

void merge_sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (high - low)/2 + low;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
    
        merge(arr, low, mid, high);
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

    merge_sort(array, 0, ARR_SIZE-1);

    printf("After sorting\n");
    print_array(array, ARR_SIZE);

    free(array);
    return 0;
}
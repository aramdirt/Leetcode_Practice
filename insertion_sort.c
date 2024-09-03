#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARR_SIZE 10
#define RANGE    50

void insert_sort(int *arr, int size)
{
    int i, j, key;

    for (i=1; i<size; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insert_sort(array, ARR_SIZE);

    for (i=0; i<ARR_SIZE; i++)
        printf("%d\n", array[i]);

    free(array);
    return 0;
}
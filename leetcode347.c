#define SIZE 1000

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int arr[SIZE] = {0};
    int i, j, x, y;
    int *result = malloc(sizeof(int) * k);

    for (i = 0; i < numsSize; i++)
        arr[nums[i]] += 1;

    *returnSize = k;
    for (i = 0; i < k; i++)
    {
        x = 0;
        y = 0;
        for (j = 0; j < SIZE; j++)
        {
            if (arr[j] > x)
            {
                x = arr[j];
                y = j;
            }
        }
        result[i] = y;
        arr[y] = 0;
    }

    return result;
}
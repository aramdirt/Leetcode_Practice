int subarraySum(int* nums, int numsSize, int k) {
    int *arr = malloc(sizeof(int) * numsSize);
    int i, j, result;

    memset(arr, 0x0, sizeof(int) * numsSize);
    arr[0] = nums[0];
    for (i = 1; i < numsSize; i++)
        arr[i] = nums[i] + arr[i-1];

    result = 0;
    for (i = numsSize - 1; i >= 0; i--)
    {
        if (arr[i] == k)
            result++;

        for (j = 0; j < i; j++)
        {
            if (arr[i] - arr[j] == k)
                result++;
        }
    }

    free(arr);
    return result;
}
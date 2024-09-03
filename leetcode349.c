int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arr = malloc(sizeof(int) * 1000);
    int *result = malloc(sizeof(int) * 1000);
    int i, j, cnt;


    memset(arr, 0, sizeof(int) * 1000);
    for (i = 0; i < nums1Size; i++)
    {
        for (j = 0; j < nums2Size; j++)
        {
            if (nums1[i] == nums2[j])
                arr[nums1[i]] = 1;
        }
    }

    cnt = 0;
    for (i = 0; i < 1000; i++)
    {
        if (arr[i])
            result[cnt++] = i;
    }

    *returnSize = cnt;
    result = realloc(result, sizeof(int) * (*returnSize));
    free(arr);
    return result;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(sizeof(int) * 2);
    int i, j;

    *returnSize = 2;
    for (i = 0; i < numsSize - 1; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                break;
            }
        }
    }

    return result;
}
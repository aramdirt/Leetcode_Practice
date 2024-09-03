int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int sum = 0;
    int cnt;

    for (cnt = 0; cnt < numsSize; cnt++)
    {
        sum += nums[cnt];
        max = max > sum ? max : sum;
        if (sum < 0)
            sum = 0;
    }

    return max;
}
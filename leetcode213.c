int rob(int* nums, int numsSize) {
    int dp1[numsSize - 1];
    int dp2[numsSize - 1];
    int cnt;

    dp1[0] = nums[0];
    dp1[1] = nums[1];

    for (cnt = 2; cnt < numsSize - 1; cnt++)
        dp1[cnt] = (dp1[cnt - 2] + nums[cnt]) > dp1[cnt - 1] ? (dp1[cnt - 2] + nums[cnt]) : dp1[cnt - 1];

    dp2[0] = nums[1];
    dp2[1] = nums[2];

    for (cnt = 3; cnt < numsSize; cnt++)
        dp2[cnt - 1] = (dp2[cnt - 3] + nums[cnt]) > dp2[cnt - 2] ? (dp2[cnt - 3] + nums[cnt]) : dp2[cnt - 2];

    return dp1[numsSize - 2] > dp2[numsSize - 2] ? dp1[numsSize - 2] : dp2[numsSize - 2];
}
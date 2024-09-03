int rob(int* nums, int numsSize) {
    int dp[numsSize];
    int cnt;

    dp[0] = nums[0];
    dp[1] = nums[1];

    for (cnt = 2; cnt < numsSize; cnt++)
        dp[cnt] = (dp[cnt - 2] + nums[cnt]) > dp[cnt - 1] ? (dp[cnt - 2] + nums[cnt]) : dp[cnt - 1];

    return dp[numsSize - 1];
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    int x = obstacleGridSize;
    int y = obstacleGridColSize[0];
    int i, j, flag, dp[i][j];

    flag = 0;
    for (i = 0; i < x; i++)
    {
        if (obstacleGrid[i][0] == 1)
            flag = 1;

        if (flag)
            dp[i][0] = 0;
        else
            dp[i][0] = 1;
    }

    for (j = 0; j < y; j++)
    {
        if (obstacleGrid[0][j] == 1)
            flag = 1;

        if (flag)
            dp[0][j] = 0;
        else
            dp[0][j] = 1;
    }

    for (i = 1; i < x; i++)
    {
        for (j = 1; j < y; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[i][j];
}
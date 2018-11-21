int dp[105][105];

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
	int i, j;
	for (i=0; i<obstacleGridColSize; i++)
	{
		if (obstacleGrid[0][i])
		{
			break;
		}
		dp[0][i] = 1;
	}
	for (; i<obstacleGridColSize; i++)
	{
		dp[0][i] = 0;
	}
	for (i=1; i<obstacleGridRowSize; i++)
	{
		dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i-1][0];
		for (j=1; j<obstacleGridColSize; j++)
		{
			dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j] + dp[i][j-1];
		}
	}
	return dp[obstacleGridRowSize-1][obstacleGridColSize-1];
}

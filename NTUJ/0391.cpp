#include <stdio.h>

int dp[105][105];

int main()
{
	int count, n, m, i, j;
	dp[0][0] = 1;
	for(i=1; i<100; i++)
	{
		dp[i][0] = 1;
		for(j=1; j<100; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		printf("%d %d => %d, %d => %d\n", n, m, dp[n][m], dp[n][m-1], (long long)dp[n][m] * dp[n][m-1] / n);
	}
	return 0;
}

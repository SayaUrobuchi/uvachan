#include <stdio.h>

const int M = 1001113;

int dp[128][128][128];

int main()
{
	int cas, count, n, m, i, j, k;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &cas, &n, &m);
		for (i=0; i<=n; i++)
		{
			dp[0][i][0] = 1;
		}
		for (i=1; i<=n; i++)
		{
			for (j=0; j<=n-i; j++)
			{
				for (k=0; k<=m; k++)
				{
					dp[i][j][k] = dp[i-1][j][k];
					if (j)
					{
						dp[i][j][k] += dp[i][j-1][k];
					}
					if (k && n-(i-1) >= j)
					{
						dp[i][j][k] += (dp[i-1][n-(i-1)][k-1] + M - dp[i-1][j][k-1]) % M;
					}
					dp[i][j][k] %= M;
					//printf(".. %d %d %d => %d\n", i, j, k, dp[i][j][k]);
				}
			}
		}
		printf("%d %d\n", cas, dp[n][0][m]);
	}
	return 0;
}

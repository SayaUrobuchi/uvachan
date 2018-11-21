#include <stdio.h>
#include <string.h>

unsigned long long dp[91][16];

int main()
{
	int n, m, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(i=1; i<=m; i++)
		{
			for(j=0; j<=n; j++)
			{
				dp[i][0] += dp[i-1][j];
			}
			for(j=1; j<=n; j++)
			{
				dp[i][j] = dp[i-1][j-1];
			}
		}
		for(i=1; i<=n; i++)
		{
			dp[m][i] += dp[m][i-1];
		}
		printf("%I64u\n", dp[m][n]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int dp[71][71];

int main()
{
	int count, n, m, o, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memset(dp, 0, sizeof(dp));
		for(i=o; i<=m; i++)
		{
			dp[1][i] = 1;
		}
		for(i=2; i<=n; i++)
		{
			for(j=m; j>-1; j--)
			{
				for(k=o; k<=j; k++)
				{
					dp[i][j] += dp[i-1][j-k];
				}
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

long long dp[1005][1005], tbl[1005][1005];

int main()
{
	int cas, count, n, m, o, i, j;
	cas = 0;
	dp[0][0] = 1;
	for(i=1; i<=1000; i++)
	{
		for(j=0; j<=i; j++)
		{
			dp[i][j] = dp[i-1][j] * (i-1-j) + dp[i-1][j+1] * (j+1);
			if(j)
			{
				dp[i][j] += dp[i-1][j-1];
			}
			if(dp[i][j] >= 1000000007)
			{
				dp[i][j] %= 1000000007;
			}
			/*printf("%d %d: %d\n", i, j, (int)dp[i][j]);*/
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memcpy(tbl[m], dp[m], sizeof(dp[0]));
		for(i=m+1; i<=n; i++)
		{
			for(j=o; j<=i; j++)
			{
				tbl[i][j] = tbl[i-1][j] * (i-j) + tbl[i-1][j+1] * (j+1);
				if(tbl[i][j] >= 1000000007)
				{
					tbl[i][j] %= 1000000007;
				}
				/*printf("%d %d: %d\n", i, j, (int)dp[i][j]);*/
			}
		}
		printf("Case %d: %d\n", ++cas, (int)tbl[n][o]);
	}
	return 0;
}

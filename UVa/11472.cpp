#include <stdio.h>
#include <string.h>

#define MN 1000000007

int dp[105][11][11][11];

int main()
{
	int count, n, m, i, j, p, q, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(dp, 0, sizeof(dp));
		for(i=1; i<n; i++)
		{
			dp[1][i][i][i] = 1;
		}
		for(i=2, ans=0; i<=m; i++)
		{
			for(j=0; j<n; j++)
			{
				for(p=j; p<n; p++)
				{
					for(q=j; q>=0; q--)
					{
						dp[i][q][p][j] = ((j>0?dp[i-1][q][p][j-1]:0) + (j<n-1?dp[i-1][q][p][j+1]:0)) % MN;
						dp[i][q][p][j] += ((j>0&&p==j?dp[i-1][q][p-1][j-1]:0) + (j<n-1&&q==j?dp[i-1][q+1][p][j+1]:0)) % MN;
						dp[i][q][p][j] %= MN;
					}
				}
				ans = (ans + dp[i][0][n-1][j]) % MN;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

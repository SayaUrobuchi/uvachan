#include <iostream>

int dp[1024][1024];
char buf[1024];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &n, &m) == 2)
	{
		dp[0][1] = 1;
		for (i=1; i<=n; i++)
		{
			scanf("%s", buf+1);
			for (j=1; j<=m; j++)
			{
				if (buf[j] == '#')
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000007;
				}
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}

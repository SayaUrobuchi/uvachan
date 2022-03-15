#include <iostream>
using namespace std;

long long dp[512][512];

int main()
{
	int n, m, i, j, k, a, b, c;
	long long ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=n; j++)
			{
				if (i == j)
				{
					dp[i][j] = 0;
				}
				else
				{
					dp[i][j] = -1;
				}
			}
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			dp[a][b] = c;
		}
		for (k=1, ans=0; k<=n; k++)
		{
			for (i=1; i<=n; i++)
			{
				for (j=1; j<=n; j++)
				{
					if (dp[i][k] != -1 && dp[k][j] != -1)
					{
						if (dp[i][j] == -1 || dp[i][j] > dp[i][k] + dp[k][j])
						{
							dp[i][j] = dp[i][k] + dp[k][j];
						}
					}
					if (dp[i][j] != -1)
					{
						ans += dp[i][j];
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include <iostream>
using namespace std;

const int M = 1000000007;

int dp[128][131072];

int main()
{
	int n, m, i, j, t;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<=m; i++)
		{
			dp[0][i] = 1;
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &t);
			for (j=0; j<=m; j++)
			{
				dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % M;
				if (j-t-1 >= 0)
				{
					dp[i][j] = (dp[i][j] + M - dp[i-1][j-t-1]) % M;
				}
				//printf("%d %d: %d\n", i, j, dp[i][j]);
			}
		}
		printf("%d\n", (dp[n][m]+M-dp[n][m-1])%M);
	}
	return 0;
}

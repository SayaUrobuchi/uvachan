#include <iostream>

const int M = 998244353;

int dp[3005][3005];

int main()
{
	int n, m, i, j, k;
	while (scanf("%d%d", &n, &m) == 2)
	{
		// dp[i][j] different ways of collecting total value j with i things
		// dp[i][j] = dp[i][j*2] + dp[i-1][j*2-1*2] + ... + dp[0][j*2-i*2]
		dp[0][0] = 1;
		for (i=1; i<=n; i++)
		{
			dp[i][0] = 0;
			for (j=i; j>=1; j--)
			{
				// i-k >= 2j-2k
				// => k >= 2j-i
				k = j+j - i;
				if (k < 0)
				{
					k = 0;
				}
				dp[i][j] = dp[i-k][j+j-k-k];
				if (j-2 >= 0)
				{
					dp[i][j] = (dp[i][j] + dp[i-1][j-2]) % M;
				}
			}
		}
		printf("%d\n", (dp[n][m]+M-dp[n-1][m-2])%M);
	}
	return 0;
}

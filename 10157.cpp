#include <stdio.h>

int dp[301][151];

int main()
{
	int n, m, i, j, k;
	for(i=0; i<151; i++)
	{
		dp[0][i] = 1;
	}
	for(n=2; n<301; n+=2)
	{
		for(i=1; i<151; i++)
		{
			for(j=2; j<=n; j+=2)
			{
				dp[n][i] += dp[j-2][i-1] * dp[n-j][i];
			}
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		printf("%d\n", dp[n][m]-dp[n][m-1]);
	}
	return 0;
}

#include <stdio.h>

#define N 10005

long long sum[N];
long long dp[N][N];

int main()
{
	int n, i, j, k, l, t;
	long long a;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &t);
			sum[i] = sum[i-1] + t;
			dp[i][i] = t*t;
		}
		for (l=1; l<n; l++)
		{
			for (i=1, j=i+l; j<=n; i++, j++)
			{
				dp[i][j] = (sum[j]-sum[i-1]) * (sum[j]-sum[i-1]);
				for (k=i; k<j; k++)
				{
					if (dp[i][k]+dp[k+1][j] < dp[i][j])
					{
						dp[i][j] = dp[i][k] + dp[k+1][j];
					}
					else if (dp[i][k]+dp[k+1][j] == dp[i][j])
					{
						break;
					}
				}
			}
		}
		printf("%lld\n", dp[1][n]);
	}
	return 0;
}

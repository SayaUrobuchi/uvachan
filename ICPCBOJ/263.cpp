#include <stdio.h>

const int N = 100005;

int hand[N], cost[N];
long long dp[N][3];

long long max(long long p, long long q)
{
	return p>q ? p : q;
}

int main()
{
	int n, m, i, j, a;
	m = 0;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &a);
		scanf("%d%d", &hand[a], &cost[a]);
		if (a > m)
		{
			m = a;
		}
	}
	for (i=1; i<=m; i++)
	{
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
		if (cost[i])
		{
			if (hand[i] == 0)
			{
				dp[i][0] += cost[i];
			}
			else
			{
				for (j=1; j<=2; j++)
				{
					if (hand[i] & j)
					{
						dp[i][j] = max(dp[i-1][0], dp[i-1][3-j]) + cost[i];
					}
				}
			}
		}
	}
	printf("%lld\n", max(dp[m][0], max(dp[m][1], dp[m][2])));
	return 0;
}

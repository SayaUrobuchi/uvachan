#include <iostream>

long long dp[128];

int main()
{
	int count, cas, n, m, o, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d", &cas, &n, &m, &o);
		dp[0] = 1;
		for (i=1; i<=n; i++)
		{
			dp[i] = 0;
			for (j=1; j<=i; j++)
			{
				if (j%o == m)
				{
					continue;
				}
				dp[i] += dp[i-j];
			}
		}
		printf("%d %lld\n", cas, dp[n]);
	}
	return 0;
}

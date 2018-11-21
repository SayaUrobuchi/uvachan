#include <stdio.h>

int ary[10005];
long long dp[10005];

int main()
{
	int n, i, j;
	long long t;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			dp[i] = 1e18;
			for (j=i, t=ary[i]; j>=1; j--, t+=ary[j])
			{
				if (dp[j-1] + t*t < dp[i])
				{
					dp[i] = dp[j-1] + t*t;
				}
			}
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

long long dp[1001];

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for(i=1; i<=n; i++)
		{
			for(j=1000; j>=i; j--)
			{
				dp[j] += dp[j-i];
			}
		}
		printf("%lld\n", (n*(n+1)/2%2)?0:dp[n*(n+1)/4]/2);
	}
	return 0;
}

#include <stdio.h>

long long dp[21], dp2[21][21];

int main()
{
	int n, m, i, j;
	long long ans;
	dp[0] = 1;
	for(i=1; i<21; i++)
	{
		dp[i] = dp[i-1] * (i) + 1 - 2 * (i%2);
	}
	dp2[0][0] = 1;
	for(i=1; i<21; i++)
	{
		dp2[i][0] = 1;
		for(j=1; j<21; j++)
		{
			dp2[i][j] = dp2[i-1][j] + dp2[i-1][j-1];
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(ans=0, i=0; i<=m; i++)
		{
			ans += dp2[n][i] * dp[n-i];
			/*printf("%I64d %I64d\n", dp2[n][i], dp[n-i]);*/
		}
		printf("%lld\n", ans);
	}
	return 0;
}

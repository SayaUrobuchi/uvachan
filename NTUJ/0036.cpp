#include <stdio.h>

long long dp[30];

int main()
{
	int n, i, j;
	dp[1] = 1;
	for(i=2; i<=25; i++)
	{
		dp[i] = dp[i-1] * (4*i-2) / (i+1);
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%lld\n", dp[n]);
	}
	return 0;
}

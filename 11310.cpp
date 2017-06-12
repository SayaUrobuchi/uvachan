#include <stdio.h>

long long dp[41];

int main()
{
	int count, i, n;
	dp[0] = dp[1] = 1;
	dp[2] = 5;
	for(i=3; i<41; i++)
	{
		dp[i] = dp[i-1] + dp[i-2] * 4 + dp[i-3] + dp[i-3];
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}

#include <stdio.h>

long long dp[1000005];

int main()
{
	int n, i;
	dp[3] = 0;
	for(i=4; i<=1000000; i++)
	{
		dp[i] = dp[i-1] + (long long)(i-1)*(i-2)/2 - (long long)((i+1)/2)*((i+1)/2-1)/2 - (long long)(i/2)*(i/2-1)/2;
	}
	while(scanf("%d", &n) == 1)
	{
		if(n < 3)
		{
			break;
		}
		printf("%lld\n", dp[n]);
	}
	return 0;
}

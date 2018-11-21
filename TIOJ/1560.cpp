#include <stdio.h>

long long dp[55][5];

int main()
{
	int i, n;
	dp[0][0] = dp[0][1] = 1;
	for(i=1; i<=50; i++)
	{
		dp[i][0] += dp[i-1][1];
		dp[i][1] += dp[i-1][0] + dp[i-1][1];
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		/*if(n == 1)
		{
			printf("1\n");
			continue;
		}*/
		printf("%I64d\n", dp[n-1][0]+dp[n-1][1]);
	}
	return 0;
}

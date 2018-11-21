#include <stdio.h>

int dp[105];

int main()
{
	int n, i;
	dp[1] = 1;
	for(i=2; i<=100; i++)
	{
		dp[i] = dp[i-1]+i*i;
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}

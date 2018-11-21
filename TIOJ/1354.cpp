#include <stdio.h>

int dp[1000001][4];

int main()
{
	int count, n, i;
	dp[0][0] = 1;
	dp[0][1] = dp[0][2] = dp[0][3] = 0;
	for(i=1; i<=1000000; i++)
	{
		dp[i][0] = dp[i-1][1] + dp[i-1][2] + dp[i-1][3];
		dp[i][1] = dp[i-1][0] + dp[i-1][2] + dp[i-1][3];
		dp[i][2] = dp[i-1][0] + dp[i-1][1] + dp[i-1][3];
		dp[i][3] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n][0]);
	}
	return 0;
}

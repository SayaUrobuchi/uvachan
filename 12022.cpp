#include <stdio.h>

int dp[15][15];

int main()
{
	int count, n, i, j, sum;
	dp[1][1] = 1;
	for(i=2; i<=12; i++)
	{
		for(j=1; j<=i; j++)
		{
			dp[i][j] = (dp[i-1][j]+dp[i-1][j-1])*j;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		sum = 0;
		for(i=1; i<=n; i++)
		{
			sum += dp[n][i];
		}
		printf("%d\n", sum);
	}
	return 0;
}

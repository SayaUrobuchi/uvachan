#include <stdio.h>

long long c[205][205], dp[205];

int main()
{
	int cas, count, n, i, j, k;
	long long r;
	cas = 0;
	c[0][0] = 1;
	for(i=1; i<=200; i++)
	{
		c[i][0] = 1;
		for(j=1; j<=200; j++)
		{
			c[i][j] = c[i-1][j-1] + c[i-1][j];
		}
	}
	dp[0] = 1;
	for(i=1; i<=100; i++)
	{
		for(j=1; j<=i; j++)
		{
			dp[i] += c[i][j] * dp[i-j];
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		printf("%d %d %I64d\n", ++cas, n, (dp[n]<<1)-1);
	}
	return 0;
}

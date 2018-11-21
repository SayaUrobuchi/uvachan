#include <stdio.h>

int dp[10005];

int main()
{
	int n, i, c, money;
	for(i=1, c=0, money=1; i<=10000; i++)
	{
		dp[i] = dp[i-1] + money;
		if(++c == money)
		{
			money++;
			c = 0;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		printf("%d %d\n", n, dp[n]);
	}
	return 0;
}

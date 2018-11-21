#include <stdio.h>

int dp[1005][1005];

int main()
{
	int count, n, i, j, sum, cas;
	cas = 0;
	dp[1][1] = 1;
	for(i=2; i<=1002; i++)
	{
		for(j=1; j<=i; j++)
		{
			dp[i][j] = ((dp[i-1][j]+dp[i-1][j-1])*j)%10056;
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
		printf("Case %d: %d\n", ++cas, sum%10056);
	}
	return 0;
}

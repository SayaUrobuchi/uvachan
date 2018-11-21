#include <stdio.h>

int dp[1005][1005];

int main()
{
	int count, n, i, j, ans;
	dp[0][0] = 1;
	for(i=1; i<=1000; i++)
	{
		dp[i][0] = 0;
		for(j=1; j<=i; j++)
		{
			dp[i][j] = ((dp[i-1][j]+dp[i-1][j-1])*j)%10056;
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, ans=0; i<=n; i++)
		{
			ans = (ans+dp[n][i]) % 10056;
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <stdio.h>

int used[20][20], dp[20][20][2];

void calc(int n, int k)
{
	if(used[n][k])
	{
		return;
	}
	used[n][k] = 1;
	if(n == 1)
	{
		dp[n][k][0] = 0;
		dp[n][k][1] = k-1;
		return;
	}
	calc(n-1, k);
	dp[n][k][0] = dp[n-1][k][1];
	dp[n][k][1] = (dp[n-1][k][0] + dp[n-1][k][1]) * (k-1);
}

int main()
{
	int n, k;
	while(scanf("%d%d", &n, &k) == 2)
	{
		calc(n, k);
		printf("%d\n", dp[n][k][0]+dp[n][k][1]);
	}
	return 0;
}

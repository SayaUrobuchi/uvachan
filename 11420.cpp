#include <stdio.h>

long long dp[70][70][2];

int main()
{
	int i, j, n, m;
	dp[0][0][0] = 1;
	for(i=1; i<66; i++)
	{
		for(j=0; j<66; j++)
		{
			dp[i][j][0] = (j ? dp[i-1][j-1][0] : 0) + dp[i-1][j][1];
			dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j][1];
		}
	}
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n < 0 && m < 0)
		{
			break;
		}
		printf("%lld\n", dp[n][m][0]+dp[n][m][1]);
	}
	return 0;
}

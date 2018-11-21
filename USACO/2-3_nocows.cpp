/*
	ID: sa072682
	LANG: C
	TASK: nocows
*/
#include <stdio.h>

int dp[201][101];

int main()
{
	int n, m, i, j, k, l;
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	scanf("%d%d", &n, &m);
	dp[1][1] = 1;
	for(i=3; i<=n; i+=2)
	{
		for(j=2; j<=m; j++)
		{
			for(k=1; k<i; k+=2)
			{
				for(l=1; l+1<j; l++)
				{
					dp[i][j] += dp[k][j-1] * dp[i-k-1][l] * 2;
					dp[i][j] %= 9901;
				}
				dp[i][j] += dp[k][j-1] * dp[i-k-1][j-1];
				dp[i][j] %= 9901;
			}
		}
	}
	printf("%d\n", dp[n][m]);
	scanf(" ");
	return 0;
}

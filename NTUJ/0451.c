#include <stdio.h>

int dp[30005][5], dp2[30005][5];

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int n, i, j, k, t;
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &t);
			for(j=1; j<=3; j++)
			{
				dp[i][j] = dp[i-1][j] + (t!=j);
				for(k=1; k<j; k++)
				{
					dp[i][j] = min(dp[i][j], dp[i-1][k]+(t!=j));
				}
				dp2[i][j] = dp2[i-1][j] + (4-t!=j);
				for(k=1; k<j; k++)
				{
					dp2[i][j] = min(dp2[i][j], dp2[i-1][k]+(4-t!=j));
				}
			}
		}
		printf("%d\n", min(dp[n][1], min(dp[n][2], min(dp[n][3], min(dp2[n][1], min(dp2[n][2], dp2[n][3]))))));
	}
	return 0;
}

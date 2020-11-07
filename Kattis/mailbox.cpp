#include <iostream>

int dp[16][128][128];

int main()
{
	int count, n, m, i, j, k, l, t;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (j=1; j<=m; j++)
		{
			for (k=j; k<=m; k++)
			{
				dp[1][j][k] = (j+k)*(k-j+1)/2;
			}
		}
		for (i=2; i<=n; i++)
		{
			for (j=m; j>=1; j--)
			{
				for (k=j; k<=m; k++)
				{
					dp[i][j][k] = m*m;
					for (l=j; l<=k; l++)
					{
						t = std::max(dp[i-1][j][l-1], dp[i][l+1][k]) + l;
						if (t < dp[i][j][k])
						{
							dp[i][j][k] = t;
						}
					}
				}
			}
		}
		printf("%d\n", dp[n][1][m]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int cycle[10][10], price[10][10][30], dp[10][1001];

int main()
{
	int cas, n, m, i, j, k, l;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(i != j)
				{
					scanf("%d", &cycle[i][j]);
					for(k=0, l=cycle[i][j]; k<l; k++)
					{
						scanf("%d", &price[i][j][k]);
					}
				}
			}
		}
		dp[0][0] = 1;
		for(i=1; i<=m; i++)
		{
			for(j=0; j<n; j++)
			{
				dp[j][i] = 0;
				for(k=0; k<n; k++)
				{
					if(j != k)
					{
						if(dp[k][i-1] && price[k][j][(i-1)%cycle[k][j]])
						{
							if(!dp[j][i] || dp[k][i-1] + price[k][j][(i-1)%cycle[k][j]] < dp[j][i])
							{
								dp[j][i] = dp[k][i-1] + price[k][j][(i-1)%cycle[k][j]];
							}
						}
					}
				}
			}
		}
		if(dp[n-1][m])
		{
			printf("Scenario #%d\nThe best flight costs %d.\n\n", ++cas, dp[n-1][m]-1);
		}
		else
		{
			printf("Scenario #%d\nNo flight possible.\n\n", ++cas);
		}
	}
	return 0;
}

#include <stdio.h>

int dp[2][41][21][21][22];

int main()
{
	int n, m, o, i, j, k, l;
	for(i=0; i<=20; i++)
	{
		dp[1][1][0][i][1] = 1;  /* up/down, xdis, mountain, maxhei, nowhei */
	}
	for(i=2; i<=40; i++)
	{
		for(j=0; j<=20; j++)
		{
			for(k=0; k<=20; k++)
			{
				for(l=0; l<=20; l++)
				{
					if(l)
					{
						dp[1][i][j][k][l] += dp[0][i-1][j][k][l-1] + dp[1][i-1][j][k][l-1];
						dp[0][i][j][k][l] += dp[0][i-1][j][k][l+1];
						if(j)
						{
							if(k == l + 1)
							{
								dp[0][i][j][k][l] += dp[1][i-1][j-1][k][l+1];
							}
							else
							{
								dp[0][i][j][k][l] += dp[1][i-1][j][k][l+1];
							}
						}
						else
						{
							if(k != l + 1)
							{
								dp[0][i][j][k][l] += dp[1][i-1][j][k][l+1];
							}
						}
					}
					else
					{
						dp[0][i][j][k][l] += dp[0][i-1][j][k][l+1];
						if(j)
						{
							if(k == l + 1)
							{
								dp[0][i][j][k][l] += dp[1][i-1][j-1][k][l+1];
							}
							else
							{
								dp[0][i][j][k][l] += dp[1][i-1][j][k][l+1];
							}
						}
						else
						{
							if(k != l + 1)
							{
								dp[0][i][j][k][l] += dp[1][i-1][j][k][l+1];
							}
						}
					}
				}
			}
		}
	}
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		printf("%d\n", dp[0][n+n][m][o][0]);
	}
	return 0;
}

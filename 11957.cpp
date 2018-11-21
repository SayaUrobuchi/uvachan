#include <stdio.h>
#include <string.h>

#define M 1000007

int dp[128][128];
char board[128][128];

int main()
{
	int count, i, j, n, dir, tx, ty, ans, cas;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<n; j++)
			{
				if (board[i][j] == 'W')
				{
					dp[i][j] = 1;
				}
			}
		}
		for (i=n-2; i>=0; i--)
		{
			for (j=0; j<n; j++)
			{
				if (board[i][j] != 'B')
				{
					for (dir=-1; dir<=1; dir+=2)
					{
						tx = i+1;
						ty = j+dir;
						if (ty >= 0 && ty < n)
						{
							if (board[tx][ty] == 'B')
							{
								++tx;
								ty += dir;
								if (tx < n && ty >= 0 && ty < n)
								{
									dp[i][j] = (dp[i][j]+dp[tx][ty]) % M;
								}
							}
							else
							{
								dp[i][j] = (dp[i][j]+dp[tx][ty]) % M;
							}
						}
					}
				}
			}
		}
		ans = 0;
		for (i=0; i<n; i++)
		{
			ans = (ans+dp[0][i]) % M;
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}

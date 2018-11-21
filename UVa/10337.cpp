#include <stdio.h>
#include <string.h>

int wind[1005][1005], dp[1005][1005];

int main()
{
	int count, h, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &h);
		h /= 100;
		for(i=9; i>=0; i--)
		{
			for(j=0; j<h; j++)
			{
				scanf("%d", &wind[j][i]);
			}
		}
		memset(dp, 0x7F, sizeof(dp));
		dp[0][0] = 0;
		for(i=0; i<h; i++)
		{
			for(j=0; j<=9; j++)
			{
				if(j > 0)
				{
					if(dp[i][j]+20-wind[i][j] < dp[i+1][j-1])
					{
						dp[i+1][j-1] = dp[i][j]+20-wind[i][j];
					}
				}
				if(dp[i][j]+30-wind[i][j] < dp[i+1][j])
				{
					dp[i+1][j] = dp[i][j]+30-wind[i][j];
				}
				if(j < 9)
				{
					if(dp[i][j]+60-wind[i][j] < dp[i+1][j+1])
					{
						dp[i+1][j+1] = dp[i][j]+60-wind[i][j];
					}
				}
			}
		}
		printf("%d\n\n", dp[h][0]);
	}
	return 0;
}

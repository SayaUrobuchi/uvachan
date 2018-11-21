#include <stdio.h>
#include <string.h>

int map[100][100], dp[2][100];

int main()
{
	int c, s, e, t, i, j, k, ans;
	while(scanf("%d%d%d%d", &c, &s, &e, &t) == 4)
	{
		if(!(c + s + e + t))
		{
			break;
		}
		for(i=0; i<c; i++)
		{
			for(j=0; j<c; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		s--;
		for(i=0; i<c; i++)
		{
			dp[0][i] = map[s][i];
		}
		for(i=1; i<t; i++)
		{
			for(j=0; j<c; j++)
			{
				dp[1][j] = map[0][j] + dp[0][0];
			}
			for(j=1; j<c; j++)
			{
				for(k=0; k<c; k++)
				{
					if(dp[0][j] + map[j][k] > dp[1][k])
					{
						dp[1][k] = dp[0][j] + map[j][k];
					}
				}
			}
			memcpy(dp[0], dp[1], sizeof(dp[0]));
		}
		for(i=0, ans=0; i<e; i++)
		{
			scanf("%d", &j);
			if(dp[0][--j] > ans)
			{
				ans = dp[0][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int dp[25][205];

int main()
{
	int count, m, c, i, j, temp, pri;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &c);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for(i=1; i<=c; i++)
		{
			scanf("%d", &temp);
			while(temp--)
			{
				scanf("%d", &pri);
				for(j=pri; j<=m; j++)
				{
					dp[i][j] |= dp[i-1][j-pri];
				}
			}
		}
		for(i=m; i>=0; i--)
		{
			if(dp[c][i])
			{
				break;
			}
		}
		if(i < 0)
		{
			printf("no solution\n");
		}
		else
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

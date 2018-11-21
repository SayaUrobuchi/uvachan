#include <stdio.h>

int map[205][205], dp[205][205];

int main()
{
	int n, m, i, j, k, l, area, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(i=n-1, ans=0; i>=0; i--)
		{
			for(j=m-1; j>=0; j--)
			{
				if(map[i][j])
				{
					dp[i][j] = (i==n-1 ? 1 : dp[i+1][j] + 1);
				}
				else
				{
					dp[i][j] = 0;
				}
				for(k=j, l=dp[i][j]; k<m; k++)
				{
					if(l > dp[i][k])
					{
						l = dp[i][k];
					}
					if(l == 0)
					{
						break;
					}
					if((area=(k-j+1)*l) > ans)
					{
						ans = area;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

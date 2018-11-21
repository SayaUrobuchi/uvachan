#include <stdio.h>
#include <string.h>

int ary[150][150], dp[150][150];

int max(int p, int q)
{
	return p>q ? p : q;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int n, i, j, ans, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<=i; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		ans = -1;
		memset(dp, 1, sizeof(dp));
		dp[0][0] = ary[0][0];
		for(i=0; i<n-1; i++)
		{
			for(j=0; j<=i; j++)
			{
				if(dp[i][j] > ans)
				{
					ans = dp[i][j];
				}
				dp[i+1][j] = min(dp[i+1][j], max(dp[i][j], ary[i+1][j])+1);
				dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], ary[i+1][j+1])+1);
			}
		}
		for(j=0; j<=i; j++)
		{
			if(dp[i][j] > ans)
			{
				ans = dp[i][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

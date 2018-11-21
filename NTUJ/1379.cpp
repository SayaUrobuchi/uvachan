#include <stdio.h>
#include <string.h>

int dp[1005][1005], tim[1005], pri[1005];

int main()
{
	int n, i, j, k, mx;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(dp, -1, sizeof(dp));
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &tim[i], &pri[i]);
		}
		dp[0][0] = 0;
		for(i=1; i<=n+n; i++)
		{
			for(j=0, mx=0; j<n; j++)
			{
				for(k=-1; k<=0; k++)
				{
					if(j+k >= 0 && j+k < n && dp[i-1][j+k] >= 0)
					{
						if(dp[i-1][j+k] > dp[i][j])
						{
							dp[i][j] = dp[i-1][j+k];
						}
					}
				}
				if(dp[i][j] >= 0 && tim[j] == i)
				{
					dp[i][j] += pri[j];
				}
				if(dp[i][j] > mx)
				{
					mx = dp[i][j];
				}
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}

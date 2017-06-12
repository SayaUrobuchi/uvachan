#include <stdio.h>
#include <string.h>

int dp[301][301];

int main()
{
	int count, n, m, i, j, v1, v2, temp, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		while(m--)
		{
			scanf("%d%d", &v1, &v2);
			for(i=0; i+v1<=n; i++)
			{
				for(j=0; j+v2<=n; j++)
				{
					if(dp[i][j])
					{
						if(!dp[i+v1][j+v2] || dp[i][j] + 1 < dp[i+v1][j+v2])
						{
							dp[i+v1][j+v2] = dp[i][j] + 1;
						}
					}
				}
			}
		}
		for(i=0, ans=2147483647, temp=n*n; i<=n; i++)
		{
			for(j=0; j<=n; j++)
			{
				if(dp[i][j] && i*i+j*j == temp)
				{
					if(dp[i][j] < ans)
					{
						ans = dp[i][j];
					}
				}
			}
		}
		if(ans == 2147483647)
		{
			printf("not possible\n");
		}
		else
		{
			printf("%d\n", ans-1);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int dp[10201];

int main()
{
	int n, m, i, j, p, q, ans, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(dp, 0, sizeof(dp));
		if((temp = n) > 1800)
		{
			n += 200;
		}
		for(i=0, ans=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			for(j=n; j>p; j--)
			{
				if(dp[j-p])
				{
					if(dp[j-p] + q > dp[j])
					{
						dp[j] = dp[j-p] + q;
						if(temp > 1800 && temp < 2000)
						{
							if(j > 2000)
							{
                                if(dp[j] > ans)
								{
									ans = dp[j];
								}
							}
						}
						else
						{
							if(dp[j] > ans)
							{
								ans = dp[j];
							}
						}
					}
				}
			}
			if(j == p && dp[j] < q)
			{
				dp[j] = q;
				if(temp > 1800 && temp < 2000)
				{
					if(j > 2000)
					{
                        if(dp[j] > ans)
						{
							ans = dp[j];
						}
					}
				}
				else
				{
					if(dp[j] > ans)
					{
						ans = dp[j];
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

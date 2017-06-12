#include <stdio.h>
#include <string.h>

char map[501];
short dp[500][2], dp2[500][3];

int main()
{
	int n, i, j, k, l, ans, min;
	while(scanf("%d", &n) == 1)
	{
		ans = 0;
		memset(dp, 0, sizeof(dp));
		memset(dp2, 0, sizeof(dp2));
		for(i=0; i<n; i++)
		{
			scanf("%s", map);
			for(j=0; j<n; j++)
			{
				min = 0;
				if(map[j] == 'x')
				{
					if(i && j)
					{
						min = dp[j-1][0];
						if(dp[j-1][1] < min)
						{
							min = dp[j-1][1];
						}
						if(dp[j][0] < min)
						{
							min = dp[j][0];
						}
						min++;
						if(min > 1)
						{
							ans += min - 1;
						}
						dp[j][1] = min;
						min = 1;
						if(dp2[j][1])
						{
							if(j && j < n - 1)
							{
								min = dp2[j-1][1];
								if(dp2[j][0] < min)
								{
									min = dp2[j][0];
								}
								if(dp2[j+1][1] < min)
								{
									min = dp2[j+1][1];
								}
								ans += min++;
							}
						}
						dp2[j][2] = min;
					}
					else
					{
						dp[j][1] = 1;
						dp2[j][2] = 1;
					}
				}
				else
				{
					dp[j][1] = 0;
					dp2[j][2] = 0;
				}
				if(j)
				{
					dp[j-1][0] = dp[j-1][1];
					dp2[j-1][0] = dp2[j-1][1];
					dp2[j-1][1] = dp2[j-1][2];
				}
			}
			dp[j-1][0] = dp[j-1][1];
			dp2[j-1][0] = dp2[j-1][1];
			dp2[j-1][1] = dp2[j-1][2];
		}
		printf("%d\n", ans);
	}
	return 0;
}

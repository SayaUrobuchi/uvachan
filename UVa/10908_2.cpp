#include <stdio.h>

char map[100][101], dp[100][101];

int main()
{
	int count, n, m, c, i, j, k, p, q, ans;
	char buf[10];
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &c);
		printf("%d %d %d\n", n, m, c);
		gets(buf);
		for(i=0; i<n; i++)
		{
			gets(map[i]);
			for(j=0; j<m; j++)
			{
				if(!j)
				{
					dp[i][j] = 1;
				}
				else
				{
					if(map[i][j-1] != map[i][j] || !i)
					{
						dp[i][j] = 1;
					}
					else
					{
						if(map[i-1][j] != map[i][j] || map[i-1][j-1] != map[i][j])
						{
							dp[i][j] = 1;
						}
						else
						{
							dp[i][j] = dp[i][j-1];
							if(dp[i-1][j] < dp[i][j])
							{
								dp[i][j] = dp[i-1][j];
							}
							if(dp[i-1][j-1] < dp[i][j])
							{
								dp[i][j] = dp[i-1][j-1];
							}
							dp[i][j]++;
						}
					}
				}
			}
		}
		/*for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				printf("%2d", dp[i][j]);
			}
			printf("\n");
		}*/
		while(c--)
		{
			scanf("%d%d", &p, &q);
			ans = 1;
			for(i=p+1, j=q+1, k=3; i<n && j<m; i++, j++, k+=2)
			{
				if(dp[i][j] < k)
				{
					break;
				}
				ans = k;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

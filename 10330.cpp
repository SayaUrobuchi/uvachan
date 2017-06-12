#include <stdio.h>
#include <string.h>

int path[102][102];

int main()
{
	int n, i, j, k, tmp, tmp2, max, ans, dis[102], back[102], dp[102];
	while(scanf("%d", &n) == 1)
	{
		for(i=1, n++; i<n; i++)
		{
			memset(path[i], 0, n * 4 + 4);
			scanf("%d", &path[i][i]);
		}
		memset(path, 0, n * 4 + 4);
		path[0][0] = 2147483647;
		path[n][n] = 2147483647;
		scanf("%d", &tmp);
		while(tmp--)
		{
			scanf("%d%d%d", &i, &j, &k);
			path[i][j] = k;
		}
		scanf("%d%d", &j, &k);
		for(i=0; i<j; i++)
		{
			scanf("%d", &tmp);
			path[0][tmp] = 2147483647;
		}
		for(i=0; i<k; i++)
		{
			scanf("%d", &tmp);
			path[tmp][n] = 2147483647;
		}
		ans = 0;
		n++;
		while(1)
		{
			for(i=1; i<n; i++)
			{
				dis[i] = path[0][i] < path[i][i] ? path[0][i] : path[i][i];
				back[i] = -1;
			}
			dis[0] = -1;
			while(1)
			{
				for(i=1, max=0, tmp2=1; i<n; i++)
				{
					if(dis[i] > max)
					{
						max = dis[i];
						tmp = i;
						tmp2 = 0;
					}
				}
				if(tmp2) break;
				dp[tmp] = dis[tmp];
				dis[tmp] = -1;
				if(tmp == n - 1) break;
				for(i=1; i<n; i++)
				{
					if(dis[i] != -1)
					{
						tmp2 = path[tmp][i] < path[i][i] ? path[tmp][i] : path[i][i];
						tmp2 = tmp2 < dp[tmp] ? tmp2 : dp[tmp];
						if(dis[i] < tmp2)
						{
							dis[i] = tmp2;
							back[i] = tmp;
						}
					}
				}
			}
			if(dis[n-1] != -1) break;
			tmp = dp[n-1];
			ans += tmp;
			path[n-1][n-1] -= tmp;
			for(i=back[n-1]; back[i]!=-1; i=back[i])
			{
				path[i][i] -= tmp;
				path[back[i]][i] -= tmp;
				path[i][back[i]] += tmp;
			}
			path[i][i] -= tmp;
		}
		printf("%d\n", ans);
	}
	return 0;
}

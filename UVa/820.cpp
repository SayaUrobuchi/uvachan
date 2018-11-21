#include <stdio.h>
#include <string.h>

int path[100][100];

int main()
{
	int n, cas, start, target, pathnum, i, j, tmp, tmp2, ans, dis[100], dp[100], pre[100], max;
	char bline;
	cas = 0;
	bline = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		scanf("%d%d%d", &start, &target, &pathnum);
		start--;
		target--;
		for(i=0; i<n; i++) memset(path[i], 0, n * 4);
		while(pathnum--)
		{
			scanf("%d%d%d", &i, &j, &tmp);
			path[--i][--j] += tmp;
			path[j][i] += tmp;
		}
		ans = 0;
		while(1)
		{
			for(i=0; i<n; i++)
			{
				dis[i] = path[start][i];
				pre[i] = start;
			}
			dis[start] = -1;
			pre[start] = -1;
			while(1)
			{
				for(i=0, max=0, tmp=-1; i<n; i++)
				{
					if(dis[i] > max)
					{
						max = dis[i];
						tmp = i;
					}
				}
				if(tmp == -1) break;
				dp[tmp] = dis[tmp];
				dis[tmp] = -1;
				if(tmp == target) break;
				for(i=0; i<n; i++)
				{
					tmp2 = path[tmp][i] < dp[tmp] ? path[tmp][i] : dp[tmp];
					if(dis[i] != -1 && dis[i] < tmp2)
					{
						dis[i] = tmp2;
						pre[i] = tmp;
					}
				}
			}
			if(tmp == -1) break;
			tmp2 = dp[tmp];
			ans += tmp2;
			for(i=tmp; pre[i] != -1; i=pre[i])
			{
				path[pre[i]][i] -= tmp2;
				path[i][pre[i]] += tmp2;
			}
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", ++cas, ans);
	}
	return 0;
}

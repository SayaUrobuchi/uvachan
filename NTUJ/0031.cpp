#include <stdio.h>
#include <string.h>

int dis[5005], map[5005][5005], used[5005];

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int n, m, i, j, k, s, e, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		memset(map, 0, sizeof(map));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][j] = map[i][j] ? min(map[i][j], k) : k;
		}
		scanf("%d%d", &s, &e);
		for(i=1; i<=n; i++)
		{
			dis[i] = 2147483647;
			used[i] = 0;
		}
		dis[s] = 0;
		for(; ; )
		{
			for(i=1, j=2147483647; i<=n; i++)
			{
				if(used[i] == 0 && dis[i] < j)
				{
					j = dis[i];
					temp = i;
				}
			}
			if(j == 2147483647)
			{
				break;
			}
			used[temp] = 1;
			if(temp == e)
			{
				break;
			}
			for(i=1; i<=n; i++)
			{
				if(map[temp][i] && dis[temp] + map[temp][i] < dis[i])
				{
					dis[i] = dis[temp] + map[temp][i];
				}
			}
		}
		if(used[e])
		{
			printf("%d\n", dis[e]);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}

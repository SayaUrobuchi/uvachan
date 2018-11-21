#include <stdio.h>

int dis[1005], map[1005][1005], used[1005];

int min(int p, int q)
{
	return p < q ? p : q;
}

int main()
{
	int n, m, i, j, k, s, t, ans, temp, minnum;
	while(scanf("%d%d%d%d", &n, &m, &s, &t) == 4)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				map[i][j] = 100000000;
			}
			dis[i] = 100000000;
			used[i] = 0;
		}
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			map[i][j] = map[j][i] = min(map[i][j], k);
		}
		dis[s] = 0;
		for(k=0; k<n; k++)
		{
			for(i=1, minnum=100000000; i<=n; i++)
			{
				if(used[i] == 0 && dis[i] < minnum)
				{
					minnum = dis[i];
					temp = i;
				}
			}
			if(minnum == 100000000)
			{
				break;
			}
			used[temp] = 1;
			if(temp == t)
			{
				break;
			}
			for(i=1; i<=n; i++)
			{
				if(used[i] == 0 && dis[i] > dis[temp] + map[temp][i])
				{
					dis[i] = dis[temp] + map[temp][i];
				}
			}
		}
		if(used[t] == 0)
		{
			printf("He is very hot\n");
		}
		else
		{
			printf("%d\n", dis[t]);
		}
	}
	return 0;
}

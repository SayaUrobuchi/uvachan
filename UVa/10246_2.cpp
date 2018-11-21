#include <stdio.h>
#include <string.h>

#define INF 1000000000

int cost[100], num[100], dis[100], used[100], mcost[100], final[100][100];

typedef struct data
{
	int target, length;
}data;

data map[100][100];

int main()
{
	int cas, n, m, o, i, j, k, l, t, d, c, min, temp;
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		memset(final, -1, sizeof(final));
		for(i=1; i<=n; i++)
		{
			scanf("%d", &cost[i]);
		}
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &d);
			map[i][num[i]].target = j;
			map[i][num[i]++].length = d;
			map[j][num[j]].target = i;
			map[j][num[j]++].length = d;
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				dis[i] = 1000000000;
				used[i] = 0;
			}
			dis[k] = 0;
			mcost[k] = k;
			for(j=0; j<n; j++)
			{
				for(i=1, min=1000000000; i<=n; i++)
				{
					if(!used[i] && dis[i] + cost[mcost[i]] < min)
					{
						min = dis[i] + cost[mcost[i]];
						temp = i;
					}
				}
				if(min == 1000000000)
				{
					break;
				}
				used[temp] = 1;
				final[k][temp] = dis[temp] + cost[mcost[temp]];
				for(i=0; i<num[temp]; i++)
				{
					t = map[temp][i].target;
					l = map[temp][i].length;
					if(cost[mcost[temp]] > cost[t])
					{
						c = mcost[temp];
					}
					else
					{
						c = t;
					}
					if(!used[t])
					{
						if(dis[t] + cost[mcost[t]] > dis[temp] + l + cost[c])
						{
							dis[t] = dis[temp] + l;
							mcost[t] = c;
						}
						else if(dis[t] + cost[mcost[t]] == dis[temp] + l + cost[c])
						{
							if(cost[mcost[t]] < cost[c])
							{
								dis[t] = dis[temp] + l;
								mcost[t] = c;
							}
						}
					}
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Case #%d\n", ++cas);
		while(o--)
		{
			scanf("%d%d", &i, &j);
			printf("%d\n", final[i][j]);
		}
	}
	return 0;
}

#include <stdio.h>

#define INF 1000000000

int cost[100], map[100][100], maxcost[100][100], tbl[100][100], mcost[100][100];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int cas, n, m, o, i, j, k, d;
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d", &cost[i]);
			for(j=1; j<=n; j++)
			{
				map[i][j] = INF;
				tbl[i][j] = INF;
				maxcost[i][j] = 0;
				mcost[i][j] = 0;
			}
			map[i][i] = 0;
			tbl[i][i] = 0;
			maxcost[i][i] = i;
			mcost[i][i] = i;
		}
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &d);
			if(d < map[i][j])
			{
				map[i][j] = map[j][i] = d;
				tbl[i][j] = tbl[j][i] = d;
			}
			if(cost[i] > cost[j])
			{
				maxcost[i][j] = maxcost[j][i] = i;
				mcost[i][j] = mcost[j][i] = i;
			}
			else
			{
				maxcost[i][j] = maxcost[j][i] = j;
				mcost[i][j] = mcost[j][i] = j;
			}
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					if(tbl[i][j] > tbl[i][k] + tbl[k][j])
					{
						tbl[i][j] = tbl[i][k] + tbl[k][j];
						if(cost[mcost[i][k]] > cost[mcost[k][j]])
						{
							mcost[i][j] = mcost[i][k];
						}
						else
						{
							mcost[i][j] = mcost[k][j];
						}
					}
					if(map[i][j] + cost[maxcost[i][j]] > map[i][k] + tbl[k][j] + max(cost[maxcost[i][k]], cost[mcost[k][j]]))
					{
						map[i][j] = map[i][k] + tbl[k][j];
						if(cost[maxcost[i][k]] > cost[mcost[k][j]])
						{
							maxcost[i][j] = maxcost[i][k];
						}
						else
						{
							maxcost[i][j] = mcost[k][j];
						}
					}
					if(map[i][j] + cost[maxcost[i][j]] > tbl[i][k] + map[k][j] + max(cost[mcost[i][k]], cost[maxcost[k][j]]))
					{
						map[i][j] = tbl[i][k] + map[k][j];
						if(cost[mcost[i][k]] > cost[maxcost[k][j]])
						{
							maxcost[i][j] = mcost[i][k];
						}
						else
						{
							maxcost[i][j] = maxcost[k][j];
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
			if(map[i][j] == INF)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n", map[i][j]+cost[maxcost[i][j]]);
			}
		}
	}
	return 0;
}

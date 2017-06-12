#include <stdio.h>
#include <string.h>

#define INF 1000000000

int cost[100], map[100][100], map2[100][100], final[100][100];

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
	int cas, n, m, o, i, j, k, l, d;
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		memset(final, -1, sizeof(final));
		for(i=1; i<=n; i++)
		{
			scanf("%d", &cost[i]);
			for(j=1; j<=n; j++)
			{
				map2[i][j] = INF;
			}
			map2[i][i] = 0;
		}
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &d);
			if(d < map2[i][j])
			{
				map2[i][j] = map2[j][i] = d;
			}
		}
		for(l=1; l<=n; l++)
		{
			memcpy(map, map2, sizeof(map));
			for(k=1; k<=n; k++)
			{
				if(cost[k] <= cost[l])
				{
					for(i=1; i<=n; i++)
					{
						if(cost[i] <= cost[l])
						{
							for(j=1; j<=n; j++)
							{
								if(cost[j] <= cost[l])
								{
									if(map[i][j] > map[i][k] + map[k][j])
									{
										map[i][j] = map[i][k] + map[k][j];
									}
								}
							}
						}
					}
				}
			}
			for(i=1; i<=n; i++)
			{
				if(cost[i] <= cost[l])
				{
					for(j=1; j<=n; j++)
					{
						if(cost[j] <= cost[l])
						{
							if(map[i][j] != INF && (final[i][j] == -1 || map[i][j] + cost[l] < final[i][j]))
							{
								final[i][j] = map[i][j] + cost[l];
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

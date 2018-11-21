#include <stdio.h>

int map[105][105], map2[105][105];

int main()
{
	int n, m, i, j, k, p, q, r;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				map[i][j] = 1000000001;
				map2[i][j] = 1000000001;
			}
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			map[p][q] = map[q][p] = r;
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(map[i][j] > map[i][k] + map[k][j])
					{
						map2[i][j] = map[i][j];
						map[i][j] = map[i][k] + map[k][j];
					}
					if(map2[i][j] > map[i][k] + map[k][j] && map[i][k] + map[k][j] > map[i][j])
					{
						map2[i][j] = map[i][k] + map[k][j];
					}
					if(map2[i][j] > map[i][k] + map2[k][j] && map[i][k] + map2[k][j] > map[i][j])
					{
						map2[i][j] = map[i][k] + map2[k][j];
					}
					if(map2[i][j] > map2[i][k] + map[k][j] && map2[i][k] + map[k][j] > map[i][j])
					{
						map2[i][j] = map2[i][k] + map[k][j];
					}
					if(map2[i][j] > map2[i][k] + map2[k][j] && map2[i][k] + map2[k][j] > map[i][j])
					{
						map2[i][j] = map2[i][k] + map2[k][j];
					}
				}
			}
		}
		scanf("%d%d", &p, &q);
		printf("%d\n", map2[p][q]==1000000001?-1:map2[p][q]);
	}
	return 0;
}

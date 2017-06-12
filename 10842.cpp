#include <stdio.h>
#include <string.h>

int map[100][100];

int main()
{
	int cas, count, n, m, i, j, k, u, v, c, tmp, tmp2, min;
	scanf("%d", &count);
	for(cas=1, count++; cas<count; cas++)
	{
		memset(map, 0, sizeof(map));
		scanf("%d%d", &n, &m);
		while(m--)
		{
			scanf("%d%d%d", &u, &v, &c);
			if(c > map[u][v])
			{
				map[u][v] = c;
				map[v][u] = c;
			}
		}
		for(k=0; k<n; k++)
		{
			for(i=0; i<n; i++)
			{
				if(map[i][k])
				{
					tmp = map[i][k];
					for(j=0; j<n; j++)
					{
						if(map[k][j])
						{
							tmp2 = tmp;
							if(map[k][j] < tmp2)
							{
								tmp2 = map[k][j];
							}
							if(tmp2 > map[i][j])
							{
								map[i][j] = tmp2;
							}
						}
					}
				}
			}
		}
		min = 0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				if(map[i][j] < min || !min)
				{
					min = map[i][j];
				}
			}
		}
		printf("Case #%d: %d\n", cas, min);
	}
	return 0;
}

#include <stdio.h>

int map[505][505];

int main()
{
	int n, i, j, k;
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				if(map[i][k] == -1 || i == k)
				{
					continue;
				}
				for(j=1; j<=n; j++)
				{
					if(j == k || i == j || map[k][j] == -1)
					{
						continue;
					}
					if(map[i][j] == -1)
					{
						map[i][j] = map[i][k] + map[k][j];
					}
					else if(map[i][j] > map[i][k] + map[k][j])
					{
						map[i][j] = map[i][k] + map[k][j];
					}
				}
			}
		}
		for(i=1; i<=n; i++)
		{
			printf("%d", map[i][1]);
			for(j=2; j<=n; j++)
			{
				printf(" %d", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int map[105][105];

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int n, m, i, j, k, t, temp;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(map, 1, sizeof(map));
		for(i=1; i<=n; i++)
		{
			scanf("%d", &m);
			while(m--)
			{
				scanf("%d%d", &j, &k);
				map[i][j] = k;
			}
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
				{
					map[i][j] = min(map[i][j], map[i][k]+map[k][j]);
				}
			}
		}
		for(i=1, m=2147483647; i<=n; i++)
		{
			for(j=1, t=0; j<=n; j++)
			{
				if(i != j && map[i][j] > t)
				{
					t = map[i][j];
				}
			}
			if(t < m)
			{
				temp = i;
				m = t;
			}
		}
		if(m > 10000)
		{
			printf("disjoint\n");
		}
		else
		{
			printf("%d %d\n", temp, m);
		}
	}
	return 0;
}

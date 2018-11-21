#include <stdio.h>
#include <string.h>

int road[128][128];

int main()
{
	int i, j, k, n, e, t, m, p, q, r, res, count;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d%d", &n, &e, &t, &m);
		memset(road, -1, sizeof(road));
		while (m--)
		{
			scanf("%d%d%d", &p, &q, &r);
			if (road[p][q] < 0 || road[p][q] > r)
			{
				road[p][q] = r;
			}
		}
		for (i=1; i<=n; i++)
		{
			road[i][i] = 0;
		}
		for (k=1; k<=n; k++)
		{
			for (i=1; i<=n; i++)
			{
				if (road[i][k] >= 0)
				{
					for (j=1; j<=n; j++)
					{
						if (road[k][j] >= 0)
						{
							if (road[i][j] < 0 || road[i][j] > road[i][k] + road[k][j])
							{
								road[i][j] = road[i][k] + road[k][j];
							}
						}
					}
				}
			}
		}
		res = 0;
		for (i=1; i<=n; i++)
		{
			if (road[i][e] >= 0 && road[i][e] <= t)
			{
				res++;
			}
		}
		printf("%d\n", res);
		if (count)
		{
			printf("\n");
		}
	}
	return 0;
}

#include <stdio.h>

int map[505][505];

int max(int p, int q)
{
	return p>q ? p : q;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
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
				for(j=1; j<=n; j++)
				{
					map[i][j] = max(map[i][j], min(map[i][k], map[k][j]));
				}
			}
		}
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d%d", &i, &j);
			printf("%d\n", map[i][j]);
		}
	}
	return 0;
}

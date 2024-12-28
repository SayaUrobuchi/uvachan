/*
	ID: sa072682
	LANG: C
	TASK: fence6
*/
#include <stdio.h>

int map[101][101];

int main()
{
	int n, i, j, k, m, o, p, q, r, ans;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d%d%d", &m, &r, &p, &q);
		while(p--)
		{
			scanf("%d", &o);
			map[m][o] = r;
		}
		while(q--)
		{
			scanf("%d", &o);
			map[o][m] = r;
		}
	}
	for(k=1; k<=n; k++)
	{
		for(i=1; i<=n; i++)
		{
			if(map[i][k])
			{
				for(j=1; j<=n; j++)
				{
					if(map[k][j])
					{
						if(!map[i][j] || map[i][k] + map[k][j] < map[i][j])
						{
							map[i][j] = map[i][k] + map[k][j];
						}
					}
				}
			}
		}
	}
	for(i=1, ans=2147483647; i<=n; i++)
	{
		if(map[i][i] < ans)
		{
			ans = map[i][i];
		}
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}

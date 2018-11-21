#include <stdio.h>

int ary[25][25], used[25][25];

int main()
{
	int cnt, n, m, o, i, j, k, ans;
	int x0, y0, x1, y1;
	cnt = 0;
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		cnt++;
		for (i=0; i<m; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		ans = 0;
		for (i=0; i<o; i++)
		{
			scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
			for (j=y0-1; j<y1; j++)
			{
				for (k=x0-1; k<x1; k++)
				{
					if (used[j][k] != cnt)
					{
						used[j][k] = cnt;
						ans += ary[j][k];
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
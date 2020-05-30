#include <stdio.h>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int ucnt, n, m;
int used[1048576], qx[1048576], qy[1048576], qs[1048576], dir[1048576];
char buf[1048576];

int xy(int x, int y)
{
	return x*m + y - 1;
}

int main()
{
	int i, j, k, x, y, s, tx, ty, sx, sy, ex, ey;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=m; j++)
			{
				scanf("%s", buf);
				dir[xy(i, j)] = 0;
				for (k=0; k<4; k++)
				{
					if (buf[k] == '1')
					{
						dir[xy(i, j)] |= (1<<k);
					}
				}
			}
		}
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		qx[0] = sx;
		qy[0] = sy;
		qs[0] = 0;
		ucnt++;
		used[xy(sx, sy)] = ucnt;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			s = qs[i];
			if (x == ex && y == ey)
			{
				break;
			}
			for (k=0; k<4; k++)
			{
				if (!(dir[xy(x, y)] & (1<<k)))
				{
					tx = x + dx[k];
					ty = y + dy[k];
					if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && used[xy(tx, ty)] != ucnt)
					{
						used[xy(tx, ty)] = ucnt;
						qx[j] = tx;
						qy[j] = ty;
						qs[j] = s + 1;
						j++;
					}
				}
			}
		}
		if (i < j)
		{
			printf("%d\n", s);
		}
		else
		{
			puts("-1");
		}
	}
	return 0;
}

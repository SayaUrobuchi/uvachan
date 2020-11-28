#include <iostream>

int ucnt;
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
int qx[1048576], qy[1048576], qs[1048576];
int used[1024][1024];
char board[1024][1024];

int main()
{
	int n, i, j, k, ox, oy, x, y, tx, ty, s, ts, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<n; j++)
			{
				if (board[i][j] == 'K')
				{
					ox = i;
					oy = j;
				}
			}
		}
		++ucnt;
		qx[0] = ox;
		qy[0] = oy;
		qs[0] = 0;
		used[ox][oy] = ucnt;
		for (i=0, j=1, ans=-1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			s = qs[i];
			if (x == 0 && y == 0)
			{
				ans = s;
				break;
			}
			for (k=0; k<8; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				ts = s + 1;
				if (tx >= 0 && tx < n && ty >= 0 && ty < n)
				{
					if (board[tx][ty] != '#' && used[tx][ty] != ucnt)
					{
						used[tx][ty] = ucnt;
						qx[j] = tx;
						qy[j] = ty;
						qs[j] = ts;
						++j;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

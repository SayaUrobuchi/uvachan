#include <stdio.h>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int qx[1048576], qy[1048576], used[1024][1024];
int board[1024][1024];
int ucnt;

int ab(int p)
{
	return p<0 ? -p : p;
}

int main()
{
	int n, m, i, j, k, x, y, ex, ey, tx, ty;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &board[i][j]);
			}
		}
		scanf("%d%d", &qx[0], &qy[0]);
		qx[0]--;
		qy[0]--;
		scanf("%d%d", &ex, &ey);
		ex--;
		ey--;
		++ucnt;
		used[qx[0]][qy[0]] = ucnt;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			if (ab(x-ex) + ab(y-ey) + ab(board[x][y]-board[ex][ey]) <= 3)
			{
				break;
			}
			for (k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (used[tx][ty] != ucnt && board[tx][ty]-board[x][y] <= 1 && board[x][y]-board[tx][ty] <= 2)
					{
						used[tx][ty] = ucnt;
						qx[j] = tx;
						qy[j] = ty;
						j++;
					}
				}
			}
		}
		puts(i < j ? "yes" : "no");
	}
	return 0;
}

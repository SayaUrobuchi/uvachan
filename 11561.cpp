#include <stdio.h>

#define GOLD (1<<0)
#define WALL (1<<1)
#define DANG (1<<2)

int map[64][64], used[64][64], qx[32768], qy[32768];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char board[64][64];

int main()
{
	int cnt, n, m, i, j, k, sx, sy, x, y, tx, ty, ans;
	cnt = 0;
	while (scanf("%d%d", &m, &n) == 2)
	{
		gets(board[0]);
		for (i=0; i<n; i++)
		{
			gets(board[i]);
			for (j=0; j<m; j++)
			{
				map[i][j] = 0;
				if (board[i][j] == 'P')
				{
					sx = i;
					sy = j;
				}
				else if (board[i][j] == 'G')
				{
					map[i][j] |= GOLD;
				}
				else if (board[i][j] == '#')
				{
					map[i][j] |= WALL;
				}
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (board[i][j] == 'T')
				{
					for (k=0; k<4; k++)
					{
						tx = i+dx[k];
						ty = j+dy[k];
						if (tx >= 0 && tx < n && ty >= 0 && ty < m)
						{
							map[tx][ty] |= DANG;
						}
					}
				}
			}
		}
		ans = 0;
		++cnt;
		qx[0] = sx;
		qy[0] = sy;
		used[sx][sy] = cnt;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			if (map[x][y] & GOLD)
			{
				++ans;
			}
			if (!(map[x][y] & DANG))
			{
				for (k=0; k<4; k++)
				{
					tx = x + dx[k];
					ty = y + dy[k];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m && !(map[tx][ty] & WALL))
					{
						if (used[tx][ty] != cnt)
						{
							used[tx][ty] = cnt;
							qx[j] = tx;
							qy[j] = ty;
							++j;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

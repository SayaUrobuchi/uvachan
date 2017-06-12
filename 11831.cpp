#include <stdio.h>

int tbl[128];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char board[128][128];
char s[1048576];

int main()
{
	int n, m, o, i, j, x, y, tx, ty, dir, sx, sy, res;
	tbl['N'] = 0;
	tbl['L'] = 1;
	tbl['S'] = 2;
	tbl['O'] = 3;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if (!n && !m && !o)
		{
			break;
		}
		sx = -1;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m&&sx<0; j++)
			{
				if (board[i][j] >= 'A' && board[i][j] <= 'Z')
				{
					sx = i;
					sy = j;
					break;
				}
			}
		}
		scanf("%s", s);
		dir = tbl[board[sx][sy]];
		board[sx][sy] = '.';
		x = sx;
		y = sy;
		res = 0;
		for (i=0; s[i]; i++)
		{
			if (s[i] == 'D')
			{
				dir = (dir+1) & 3;
			}
			else if (s[i] == 'E')
			{
				dir = (dir+3) & 3;
			}
			else
			{
				tx = x + dx[dir];
				ty = y + dy[dir];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] != '#')
				{
					x = tx;
					y = ty;
					if (board[x][y] == '*')
					{
						board[x][y] = '.';
						res++;
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

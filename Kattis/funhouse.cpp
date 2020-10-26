#include <iostream>

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char board[32][32];

int main()
{
	int cas, n, m, i, j, x, y, sx, sy, d;
	cas = 0;
	while (scanf("%d%d", &m, &n) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		sx = -1;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m&&sx<0; j++)
			{
				if (board[i][j] == '*')
				{
					sx = i;
					sy = j;
				}
			}
		}
		for (i=0; i<4; i++)
		{
			x = sx + dx[i];
			y = sy + dy[i];
			if (x < 0 || x >= n || y < 0 || y >= m)
			{
				d = ((i+2) & 3);
			}
		}
		for (x=sx, y=sy; board[x][y]!='x'; x+=dx[d], y+=dy[d])
		{
			if (board[x][y] == '/')
			{
				d ^= 1;
			}
			else if (board[x][y] == '\\')
			{
				d = 3-d;
			}
		}
		board[x][y] = '&';
		printf("HOUSE %d\n", ++cas);
		for (i=0; i<n; i++)
		{
			puts(board[i]);
		}
	}
	return 0;
}

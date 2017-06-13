#include <stdio.h>

#define M 2048576

char board[1024][1024];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int qx[M], qy[M], qs[M], qt[M], qn;

int main()
{
	int count, n,m, i, j, k, qn, x, y, t, s, tx, ty, jx, jy;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		qn = 0;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m; j++)
			{
				if (board[i][j] == 'J')
				{
					board[i][j] = '.';
					jx = i;
					jy = j;
				}
				else if (board[i][j] == 'F')
				{
					board[i][j] = '#';
					qx[qn] = i;
					qy[qn] = j;
					qt[qn] = 0;
					qs[qn] = 0;
					qn++;
				}
			}
		}
		qx[qn] = jx;
		qy[qn] = jy;
		qt[qn] = 1;
		qs[qn] = 0;
		qn++;
		for (i=0; i<qn; i++)
		{
			x = qx[i];
			y = qy[i];
			t = qt[i];
			s = qs[i];
			for (k=0; k<4; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m && board[tx][ty] == '.')
				{
						board[tx][ty] = '#';
						qx[qn] = tx;
						qy[qn] = ty;
						qt[qn] = t;
						qs[qn] = s+1;
						qn++;
				}
				else if (t && (tx < 0 || tx >= n || ty < 0 || ty >= m))
				{
					break;
				}
			}
			if (k < 4)
			{
				break;
			}
		}
		if (i < qn)
		{
			printf("%d\n", s+1);
		}
		else
		{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}

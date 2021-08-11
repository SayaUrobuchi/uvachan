#include <iostream>

const int MX = 512;
const int MX2 = MX*MX;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int ucnt;
int used[MX][MX];
int qx[MX2], qy[MX2], qs[MX2];
char board[MX][MX];

int main()
{
	int n, m, i, j, k, x, y, ans, tx, ty;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		qx[0] = 0;
		qy[0] = 0;
		qs[0] = 0;
		++ucnt;
		used[0][0] = ucnt;
		ans = -1;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			if (x == n-1 && y == m-1)
			{
				ans = qs[i];
				break;
			}
			for (k=0; k<4; k++)
			{
				tx = x + dx[k] * (board[x][y]-'0');
				ty = y + dy[k] * (board[x][y]-'0');
				if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (used[tx][ty] != ucnt)
					{
						used[tx][ty] = ucnt;
						qx[j] = tx;
						qy[j] = ty;
						qs[j] = qs[i] + 1;
						j++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

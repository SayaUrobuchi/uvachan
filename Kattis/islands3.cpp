#include <iostream>

const char LAND = 'L';
const char CLOUD = 'C';
const char WATER = 'W';

int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int qx[64<<6], qy[64<<6];
char board[64][64];

void bfs(int sx, int sy)
{
	int i, j, k, x, y, nx, ny;
	qx[0] = sx;
	qy[0] = sy;
	board[sx][sy] = 'W';
	for (i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		for (k=0; k<4; k++)
		{
			nx = x + dx[k];
			ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] != WATER)
			{
				board[nx][ny] = WATER;
				qx[j] = nx;
				qy[j] = ny;
				j++;
			}
		}
	}
}

int main()
{
	int i, j, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0, ans=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (board[i][j] == LAND)
				{
					bfs(i, j);
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

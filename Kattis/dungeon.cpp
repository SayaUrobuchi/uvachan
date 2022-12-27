#include <iostream>
using namespace std;

const int N = 32;
const int N3 = N*N*N;

const int dx[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {1, -1, 0, 0, 0, 0};

int qx[N3], qy[N3], qz[N3], qs[N3];
int ucnt, used[N][N][N];
char board[N][N][N];

int main()
{
	int n, m, o, i, j, k, x, y, z, ans;
	int sx, sy, sz, ex, ey, ez, nx, ny, nz;
	while (scanf("%d%d%d", &o, &n, &m) == 3)
	{
		if (n == 0 && m == 0 && o == 0)
		{
			break;
		}
		for (k=0; k<o; k++)
		{
			for (i=0; i<n; i++)
			{
				scanf("%s", &board[k][i]);
				for (j=0; j<m; j++)
				{
					if (board[k][i][j] == 'S')
					{
						sx = i;
						sy = j;
						sz = k;
					}
					else if (board[k][i][j] == 'E')
					{
						ex = i;
						ey = j;
						ez = k;
					}
				}
			}
		}
		qx[0] = sx;
		qy[0] = sy;
		qz[0] = sz;
		qs[0] = 0;
		used[sz][sx][sy] = ++ucnt;
		ans = -1;
		for (i=0, j=1; i<j; i++)
		{
			x = qx[i];
			y = qy[i];
			z = qz[i];
			if (x == ex && y == ey && z == ez)
			{
				ans = qs[i];
				break;
			}
			for (k=0; k<6; k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];
				nz = z + dz[k];
				if (nx >= 0 && nx < n
				 && ny >= 0 && ny < m
				 && nz >= 0 && nz < o)
				{
					if (used[nz][nx][ny] != ucnt
					 && board[nz][nx][ny] != '#')
					{
						used[nz][nx][ny] = ucnt;
						qx[j] = nx;
						qy[j] = ny;
						qz[j] = nz;
						qs[j] = qs[i] + 1;
						j++;
					}
				}
			}
		}
		if (ans < 0)
		{
			puts("Trapped!");
		}
		else
		{
			printf("Escaped in %d minute(s).\n", ans);
		}
	}
	return 0;
}
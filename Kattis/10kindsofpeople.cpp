#include <iostream>
using namespace std;

const int N = 1005;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

int n, m;
int grp[N][N];
char board[N][N];

void dfs(int x, int y, int g)
{
	int i;
	grp[x][y] = g;
	for (i=0; i<4; i++)
	{
		int tx = x + DX[i];
		int ty = y + DY[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
		{
			if (board[tx][ty] == board[x][y] && !grp[tx][ty])
			{
				dfs(tx, ty, g);
			}
		}
	}
}

int main()
{
	int i, o, sx, sy, ex, ey;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%s", board[i]+1);
	}
	int gid = 1;
	scanf("%d", &o);
	for (i=0; i<o; i++)
	{
		scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
		if (!grp[sx][sy])
		{
			dfs(sx, sy, gid);
			++gid;
		}
		if (grp[sx][sy] == grp[ex][ey])
		{
			puts(board[sx][sy] == '0' ? "binary" : "decimal");
		}
		else
		{
			puts("neither");
		}
	}
	return 0;
}

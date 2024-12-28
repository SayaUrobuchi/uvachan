#include <iostream>
using namespace std;

const int N = 16;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

int n, m, ans;
char board[N][N];
bool used[N][N];

void dfs(int x, int y, int step)
{
	int i;
	if (step == 0)
	{
		++ans;
		return;
	}
	used[x][y] = true;
	for (i=0; i<4; i++)
	{
		int tx = x + DX[i];
		int ty = y + DY[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m)
		{
			if (!used[tx][ty] && board[tx][ty] == '.')
			{
				dfs(tx, ty, step-1);
			}
		}
	}
	used[x][y] = false;
}

int main()
{
	int o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	ans = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (board[i][j] == '.')
			{
				dfs(i, j, o);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

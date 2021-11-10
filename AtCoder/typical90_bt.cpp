#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, i, j, ans;
char board[32][32];
bool used[32][32];

void dfs(int x, int y, int depth)
{
	int k, nx, ny;
	if (x == i && y == j && depth)
	{
		if (depth >= 3)
		{
			ans = max(ans, depth);
		}
		return;
	}
	for (k=0; k<4; k++)
	{
		nx = x + dx[k];
		ny = y + dy[k];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m)
		{
			if (!used[nx][ny] && board[nx][ny] != '#')
			{
				used[nx][ny] = true;
				dfs(nx, ny, depth+1);
				used[nx][ny] = false;
			}
		}
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		ans = -1;
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				if (board[i][j] != '#')
				{
					dfs(i, j, 0);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

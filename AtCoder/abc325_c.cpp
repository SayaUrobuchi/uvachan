#include <iostream>
using namespace std;

const int N = 1005;
const int M = 1005;
const int DX[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int DY[] = {1, 0, -1, 0, 1, -1, 1, -1};
const char SENSOR = '#';

int n, m;
bool used[N][M];
char board[N][M];

void dfs(int x, int y)
{
	int i;
	used[x][y] = true;
	for (i=0; i<8; i++)
	{
		int tx = x + DX[i];
		int ty = y + DY[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < m)
		{
			if (board[tx][ty] == SENSOR && !used[tx][ty])
			{
				dfs(tx, ty);
			}
		}
	}
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	int ans = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (!used[i][j] && board[i][j] == SENSOR)
			{
				++ans;
				dfs(i, j);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

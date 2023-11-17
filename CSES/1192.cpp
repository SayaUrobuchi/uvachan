#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const char EMPTY = '.';
const char WALL = '#';
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char board[1024][1024];

bool valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int sx, int sy)
{
	int i, k;
	vector<pp> que;
	que.emplace_back(sx, sy);
	board[sx][sy] = WALL;
	for (i=0; i<que.size(); i++)
	{
		int x, y;
		tie(x, y) = que[i];
		for (k=0; k<4; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (valid(tx, ty) && board[tx][ty] == EMPTY)
			{
				board[tx][ty] = WALL;
				que.emplace_back(tx, ty);
			}
		}
	}
}

int main()
{
	int i, j, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	for (i=0, ans=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (board[i][j] == EMPTY)
			{
				bfs(i, j);
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

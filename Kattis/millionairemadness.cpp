#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 1024;

using pp = pair<int, int>;
using ppp = pair<int, pp>;
using pq = priority_queue<ppp, vector<ppp>, greater<ppp> >;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int board[N][N], dis[N][N];

int main()
{
	int n, m, i, j, k, t, x, y, z, nx, ny;
	pq qq;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &board[i][j]);
				dis[i][j] = 2e9;
			}
		}
		dis[0][0] = 0;
		qq = pq();
		qq.push({0, {0, 0}});
		while (qq.size())
		{
			ppp now = qq.top();
			qq.pop();
			x = now.second.first;
			y = now.second.second;
			if (now.first != dis[x][y])
			{
				continue;
			}
			t = board[x][y];
			for (k=0; k<4; k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					z = max(now.first, max(0, board[nx][ny]-t));
					if (z < dis[nx][ny])
					{
						dis[nx][ny] = z;
						qq.push({z, {nx, ny}});
					}
				}
			}
		}
		printf("%d\n", dis[n-1][m-1]);
	}
	return 0;
}

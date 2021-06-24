#include <iostream>
#include <queue>
using namespace std;

using pp = pair<int, pair<int, int> >;

int board[64][64], dis[64][64];
vector<pair<int, int> > v[4096];

int main()
{
	int n, m, i, j, t, x, y, d, nx, ny, nd, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=m; i++)
		{
			v[i].clear();
		}
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &t);
				board[i][j] = t;
				if (t == 1)
				{
					pq.push({0, {i, j}});
					dis[i][j] = 0;
				}
				else
				{
					dis[i][j] = 1e9;
					v[t].emplace_back(i, j);
				}
			}
		}
		ans = -1;
		while (pq.size())
		{
			pp p = pq.top();
			pq.pop();
			x = p.second.first;
			y = p.second.second;
			d = p.first;
			t = board[x][y];
			if (dis[x][y] != d)
			{
				continue;
			}
			if (t == m)
			{
				ans = d;
				break;
			}
			for (i=0; i<v[t+1].size(); i++)
			{
				nx = v[t+1][i].first;
				ny = v[t+1][i].second;
				nd = d + abs(nx-x) + abs(ny-y);
				if (nd < dis[nx][ny])
				{
					dis[nx][ny] = nd;
					pq.push({nd, {nx, ny}});
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;
using ps = pair<int, int>;
using pst = pair<int, ps >;
using pqpq = priority_queue<pst, vector<pst>, greater<pst> >;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int h[128][128], dis[128][128];

int main()
{
	int n, i, j, x, y, tx, ty, d, nd, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &h[i][j]);
				dis[i][j] = 1e9;
			}
		}
		pqpq pq;
		pq.push({0, {0, 0}});
		dis[0][0] = 0;
		while (pq.size())
		{
			pst pp = pq.top();
			pq.pop();
			x = pp.second.first;
			y = pp.second.second;
			d = pp.first;
			if (x == n-1 && y == n-1)
			{
				ans = d;
				break;
			}
			if (d != dis[x][y])
			{
				continue;
			}
			for (i=0; i<4; i++)
			{
				tx = x + dx[i];
				ty = y + dy[i];
				if (tx >= 0 && tx < n && ty >= 0 && ty < n)
				{
					nd = max(d, h[tx][ty]);
					if (nd < dis[tx][ty])
					{
						dis[tx][ty] = nd;
						pq.push({nd, {tx, ty}});
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <iostream>
#include <queue>
using namespace std;
using ppp = pair<int, pair<int, int> >;

const int N = 512;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dis[N][N];
char board[N][N];

int main()
{
	int n, m, i, j, x, y, z, tx, ty, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m; j++)
			{
				dis[i][j] = n*m+10;
			}
		}
		dis[0][0] = 0;
		priority_queue<ppp, vector<ppp>, greater<ppp>> pq;
		pq.push({0, {0, 0}});
		for (; pq.size(); )
		{
			ppp cur = pq.top();
			pq.pop();
			x = cur.second.first;
			y = cur.second.second;
			z = cur.first;
			if (x == n-1 && y == m-1)
			{
				ans = z;
				break;
			}
			if (dis[x][y] != z)
			{
				continue;
			}
			for (i=0; i<4; i++)
			{
				tx = x + dx[i];
				ty = y + dy[i];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (board[tx][ty] != '#' && dis[tx][ty] > z)
					{
						dis[tx][ty] = z;
						pq.push({z, {tx, ty}});
					}
				}
			}
			for (tx=x-2; tx<=x+2; tx++)
			{
				if (tx >= 0 && tx < n)
				{
					for (ty=y-2; ty<=y+2; ty++)
					{
						if (ty >= 0 && ty < m)
						{
							if (abs(x-tx) != 2 || abs(y-ty) != 2)
							{
								if (dis[tx][ty] > z+1)
								{
									dis[tx][ty] = z+1;
									pq.push({z+1, {tx, ty}});
								}
							}
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


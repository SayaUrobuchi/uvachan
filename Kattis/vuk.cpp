#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 505;
const int NN = N * N;
const int MOV = 4;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m;
char board[N][N];
int tn;
int tx[NN], ty[NN];
int dis[N][N];
int best[N][N];
bool used[N][N];

void bfs()
{
	int i, k;
	vector<ppp> qq(tn);
	for (i=0; i<tn; i++)
	{
		qq[i] = make_pair(0, make_pair(tx[i], ty[i]));
		used[tx[i]][ty[i]] = true;
	}
	for (i=0; i<qq.size(); i++)
	{
		int d, x, y;
		forward_as_tuple(d, tie(x, y)) = qq[i];
		dis[x][y] = d;
		for (k=0; k<MOV; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m)
			{
				if (!used[tx][ty])
				{
					used[tx][ty] = true;
					qq.emplace_back(d+1, make_pair(tx, ty));
				}
			}
		}
	}
}

int dijkstra(int sx, int sy)
{
	int i, j, k;
	priority_queue<ppp> pq;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			best[i][j] = -1;
		}
	}
	best[sx][sy] = dis[sx][sy];
	pq.emplace(best[sx][sy], make_pair(sx, sy));
	while (pq.size())
	{
		int d, x, y;
		forward_as_tuple(d, tie(x, y)) = pq.top();
		pq.pop();
		if (best[x][y] != d)
		{
			continue;
		}
		if (board[x][y] == 'J')
		{
			return d;
		}
		for (k=0; k<MOV; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m)
			{
				int td = min(d, dis[tx][ty]);
				if (td > best[tx][ty])
				{
					best[tx][ty] = td;
					pq.emplace(td, make_pair(tx, ty));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int i, j, sx, sy;
	scanf("%d%d", &n, &m);
	for (i=0, tn=0; i<n; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<m; j++)
		{
			if (board[i][j] == 'V')
			{
				sx = i;
				sy = j;
			}
			else if (board[i][j] == '+')
			{
				tx[tn] = i;
				ty[tn] = j;
				++tn;
			}
		}
	}
	bfs();
	int ans = dijkstra(sx, sy);
	printf("%d\n", ans);
	return 0;
}
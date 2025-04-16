#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char WALL = '#';
const int N = 305;
const int M = 32;
const int ST = (1 << 20);

int n, m, o, ccnt;
int px[M], py[M], dis[M][M];
int id[N][N];
bool used[N][N];
char board[N][N];
int dp[ST][M];
bool vis[ST][M];

void bfs(int sx, int sy, int idx)
{
	vector<ppp> que;
	int i, j, k;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			used[i][j] = false;
		}
	}
	for (i=0; i<ccnt+2; i++)
	{
		dis[idx][i] = o + 1;
	}
	used[sx][sy] = true;
	que.emplace_back(make_pair(sx, sy), 0);
	for (i=0; i<que.size(); i++)
	{
		int x, y, d;
		forward_as_tuple(tie(x, y), d) = que[i];
		if (id[x][y] != -1)
		{
			dis[idx][id[x][y]] = d;
		}
		for (k=0; k<4; k++)
		{
			int tx = x + DX[k];
			int ty = y + DY[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m && !used[tx][ty])
			{
				if (board[tx][ty] != WALL)
				{
					used[tx][ty] = true;
					que.emplace_back(make_pair(tx, ty), d+1);
				}
			}
		}
	}
}

int recurs(int stat, int cur)
{
	int i;
	if (vis[stat][cur])
	{
		return dp[stat][cur];
	}
	vis[stat][cur] = true;
	if (stat == 0)
	{
		return dp[stat][cur] = dis[0][cur];
	}
	dp[stat][cur] = 1e9;
	for (i=0; i<ccnt; i++)
	{
		if (stat & (1 << i))
		{
			dp[stat][cur] = min(dp[stat][cur], recurs(stat & ~(1<<i), i+2) + dis[i+2][cur]);
		}
	}
	return dp[stat][cur];
}

int main()
{
	int i, j;
	scanf("%d%d%d", &n, &m, &o);
	ccnt = 0;
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<m; j++)
		{
			id[i][j] = -1;
			if (board[i][j] == 'S')
			{
				id[i][j] = 0;
			}
			else if (board[i][j] == 'G')
			{
				id[i][j] = 1;
			}
			else if (board[i][j] == 'o')
			{
				id[i][j] = 2 + ccnt;
				++ccnt;
			}
			px[id[i][j]] = i;
			py[id[i][j]] = j;
		}
	}
	for (i=0; i<ccnt+2; i++)
	{
		bfs(px[i], py[i], i);
	}
	int ans = -1;
	for (i=0; i<(1<<ccnt); i++)
	{
		int res = recurs(i, 1);
		if (res <= o)
		{
			int dig = 0;
			int t = i;
			while (t)
			{
				dig += (t & 1);
				t >>= 1;
			}
			ans = max(ans, dig);
		}
	}
	printf("%d\n", ans);
	return 0;
}

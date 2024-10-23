#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 505;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const int START = -2;

int ucc, n, m, o;
int board[N][N], u2[N][N];
bool used[N][N], u3[N][N], chained[N][N];

int chain(int sx, int sy, vector<pp> &chl)
{
	int i, k;
	int ret = 0;
	chained[sx][sy] = true;
	vector<ppp> q2;
	q2.emplace_back(board[sx][sy], make_pair(sx, sy));
	++ucc;
	u2[sx][sy] = ucc;
	for (i=0; i<q2.size(); i++)
	{
		int d, x, y;
		forward_as_tuple(d, tie(x, y)) = q2[i];
		if (!u3[x][y])
		{
			u3[x][y] = true;
			++ret;
		}
		if (!chained[x][y] && board[x][y] > 0)
		{
			chl.emplace_back(x, y);
		}
		if (d > 0)
		{
			for (k=0; k<4; k++)
			{
				int tx = x + DX[k];
				int ty = y + DY[k];
				if (tx >= 0 && tx < n && ty >= 0 && ty < m)
				{
					if (board[tx][ty] >= 0 && u2[tx][ty] != ucc)
					{
						u2[tx][ty] = ucc;
						q2.emplace_back(d-1, make_pair(tx, ty));
					}
				}
			}
		}
	}
	return ret;
}

int bfs(int sx, int sy)
{
	int i, k;
	vector<pp> chl;
	vector<ppp> que;
	que.emplace_back(0, make_pair(sx, sy));
	used[sx][sy] = true;
	int bombed = 0;
	for (i=0; i<que.size(); i++)
	{
		int d, x, y;
		forward_as_tuple(d, tie(x, y)) = que[i];
		if (!chained[x][y])
		{
			bombed += chain(x, y, chl);
			while (chl.size())
			{
				int tx, ty;
				tie(tx, ty) = chl.back();
				chl.pop_back();
				bombed += chain(tx, ty, chl);
			}
		}
		if (bombed >= o)
		{
			return d;
		}
		for (k=0; k<4; k++)
		{
			int tx = x + DX[k];
			int ty = y + DY[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < m)
			{
				if (board[tx][ty] >= 0 && !used[tx][ty])
				{
					used[tx][ty] = true;
					que.emplace_back(d+1, make_pair(tx, ty));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int i, j, sx, sy;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &board[i][j]);
			if (board[i][j] == START)
			{
				sx = i;
				sy = j;
			}
		}
	}
	int ans = bfs(sx, sy);
	printf("%d\n", ans);
	return 0;
}

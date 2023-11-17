#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;
using data_t = pair<pp, ppp>;

const char EMPTY = '.';
const char WALL = '#';
const char START = 'A';
const char END = 'B';
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char *dir_tbl = "RDLU";
const int N = 1024;

int n, m;
char board[N][N];
bool used[N][N];
string path;

void backtrack(int cur, const vector<data_t> &que)
{
	int nxt = que[cur].second.second.second;
	if (nxt > 0)
	{
		backtrack(nxt, que);
	}
	path += dir_tbl[que[cur].second.second.first];
}

bool valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int sx, int sy)
{
	int i, k, t;
	vector<data_t> que;
	que.emplace_back(make_pair(sx, sy), make_pair(0, make_pair(-1, -1)));
	used[sx][sy] = true;
	for (i=0, t=-1; i<que.size(); i++)
	{
		int x, y;
		int d, di, f;
		forward_as_tuple(tie(x, y), forward_as_tuple(d, tie(di, f))) = que[i];
		if (board[x][y] == 'B')
		{
			t = i;
			break;
		}
		for (k=0; k<4; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (valid(tx, ty) && !used[tx][ty] && board[tx][ty] != WALL)
			{
				used[tx][ty] = WALL;
				que.emplace_back(make_pair(tx, ty), make_pair(d+1, make_pair(k, i)));
			}
		}
	}
	if (t >= 0)
	{
		path.clear();
		backtrack(t, que);
		return que[t].second.first;
	}
	return t;
}

int main()
{
	int i, j, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (board[i][j] == START)
			{
				ans = bfs(i, j);
			}
		}
	}
	if (ans < 0)
	{
		puts("NO");
	}
	else
	{
		puts("YES");
		printf("%d\n", ans);
		puts(path.c_str());
	}
	return 0;
}

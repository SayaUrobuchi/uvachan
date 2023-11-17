#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using data_t = pair<pp, pp>;

const int N = 1024;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const char *tbl = "RDLU";
const char WALL = '#';
const char START = 'A';
const char MONSTER = 'M';

int n, m, ans;
char board[N][N];
bool used[N][N];
vector<data_t> que;
int dir[N*N];
string path;

void backtrack(int cur)
{
	int nxt = que[cur].second.second;
	if (nxt >= 0)
	{
		backtrack(nxt);
		path += (char)tbl[dir[cur]];
	}
}

bool valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	int i, j, k, sx, sy;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<m; j++)
		{
			if (board[i][j] == START)
			{
				sx = i;
				sy = j;
			}
			else if (board[i][j] == MONSTER)
			{
				que.emplace_back(make_pair(i, j), make_pair(MONSTER, -1));
				used[i][j] = true;
			}
		}
	}
	que.emplace_back(make_pair(sx, sy), make_pair(START, -1));
	used[sx][sy] = true;
	for (i=0, ans=-1; i<que.size()&&ans<0; i++)
	{
		int x, y, t, f;
		forward_as_tuple(tie(x, y), tie(t, f)) = que[i];
		for (k=0; k<4; k++)
		{
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (!valid(tx, ty))
			{
				if (t == START)
				{
					ans = i;
					break;
				}
			}
			else
			{
				if (!used[tx][ty] && board[tx][ty] != WALL)
				{
					used[tx][ty] = true;
					dir[que.size()] = k;
					que.emplace_back(make_pair(tx, ty), make_pair(t, i));
				}
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
		backtrack(ans);
		printf("%d\n", (int)path.size());
		puts(path.c_str());
	}
	return 0;
}

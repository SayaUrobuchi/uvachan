#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int W = 4;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int req[] = {0, 0, 0, 10, 8};

int ucnt, c;
int used[8][8], tbl[128];
vector<pair<int, int> > pp[8];
char board[8][8];
int typ[128];

bool dfs(int);

bool dfs2(int x, int y, int d)
{
	int i, tx, ty;
	bool res;
	if (x == pp[d][1].first && y == pp[d][1].second)
	{
		return dfs(d+1);
	}
	used[x][y] = d;
	if (board[x][y] == 'W')
	{
		--c;
	}
	res = false;
	for (i=0; i<4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
		{
			if ((board[tx][ty] == 'W' || typ[board[tx][ty]] == d) && used[tx][ty] == -1)
			{
				if (dfs2(tx, ty, d))
				{
					res = true;
					break;
				}
			}
		}
	}
	used[x][y] = -1;
	if (board[x][y] == 'W')
	{
		++c;
	}
	return res;
}

bool dfs(int depth)
{
	if (depth == 4)
	{
		return !c;
	}
	if (pp[depth].size())
	{
		return dfs2(pp[depth][0].first, pp[depth][0].second, depth);
	}
	return dfs(depth+1);
}

int main()
{
	int i, j, cnt;
	typ['R'] = 0;
	typ['G'] = 1;
	typ['B'] = 2;
	typ['Y'] = 3;
	typ['W'] = 4;
	memset(used, -1, sizeof(used));
	while (scanf("%s", board[0]) == 1)
	{
		for (i=1; i<4; i++)
		{
			scanf("%s", board[i]);
		}
		++ucnt;
		for (i=0; i<4; i++)
		{
			pp[i].clear();
		}
		for (i=0, cnt=-1; i<4; i++)
		{
			for (j=0; j<4; j++)
			{
				if (tbl[board[i][j]] != ucnt)
				{
					tbl[board[i][j]] = ucnt;
					++cnt;
				}
				if (typ[board[i][j]] != W)
				{
					pp[typ[board[i][j]]].emplace_back(i, j);
				}
			}
		}
		c = req[cnt];
		if (dfs(0))
		{
			puts("solvable");
		}
		else
		{
			puts("not solvable");
		}
	}
	return 0;
}

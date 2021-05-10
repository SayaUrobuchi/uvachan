#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int CONN = 1;
const int NOT_CONN = 0;
const int UNKNOWN = -1;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
int dir[128][128];
bool decide[128][128];
char board[128][128];
vector<pp> v;
bool dead;

bool valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int check(int x, int y, int d)
{
	if (board[x][y] == 'A')
	{
		return NOT_CONN;
	}
	if (board[x][y] == 'D')
	{
		return CONN;
	}
	if (decide[x][y])
	{
		if (board[x][y] == 'B')
		{
			return d == dir[x][y] || ((d+2)&3) == dir[x][y];
		}
		else
		{
			return d == dir[x][y] || ((d+3)&3) == dir[x][y];
		}
	}
	return UNKNOWN;
}

bool judge(int x, int y)
{
	int yes, no, maybe, cnt, i, res, tx, ty;
	yes = 0;
	no = 0;
	maybe = 0;
	cnt = 0;
	for (i=0; i<4; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (valid(tx, ty))
		{
			res = check(tx, ty, (i+2)&3);
			if (res == CONN)
			{
				yes |= (1 << i);
				++cnt;
			}
			else if (res == NOT_CONN)
			{
				no |= (1 << i);
			}
			else
			{
				maybe |= (1 << i);
				++cnt;
			}
		}
		else
		{
			no |= (1 << i);
		}
	}
	if (board[x][y] == 'A')
	{
		if (yes)
		{
			dead = true;
		}
		decide[x][y] = true;
		return true;
	}
	if (board[x][y] == 'D')
	{
		if (no)
		{
			dead = true;
		}
		decide[x][y] = true;
		return true;
	}
	if (board[x][y] == 'B')
	{
		for (i=0; i<4; i++)
		{
			if (yes & (1<<i))
			{
				if (no & (1<<((i+2)&3)))
				{
					dead = true;
					return false;
				}
				if ((yes & (1<<((i+1)&3))) || (yes & (1<<((i+3)&3))))
				{
					dead = true;
					return false;
				}
				decide[x][y] = true;
				dir[x][y] = i;
				return true;
			}
			else if (no & (1<<i))
			{
				if (yes & (1<<((i+2)&3)))
				{
					dead = true;
					return false;
				}
				if ((no & (1<<((i+1)&3))) || (no & (1<<((i+3)&3))))
				{
					dead = true;
					return false;
				}
				decide[x][y] = true;
				dir[x][y] = ((i+1)&3);
				return true;
			}
		}
		return false;
	}
	for (i=0; i<4; i++)
	{
		if ((yes & (1<<i)) && (yes & (1<<((i+1)&3))))
		{
			if ((yes & (1<<((i+2)&3))) || (yes & (1<<((i+3)&3))))
			{
				dead = true;
				return false;
			}
			decide[x][y] = true;
			dir[x][y] = i;
			return true;
		}
		else if ((no & (1<<i)) && (no & (1<<((i+1)&3))))
		{
			if ((no & (1<<((i+2)&3))) || (no & (1<<((i+3)&3))))
			{
				dead = true;
				return false;
			}
			decide[x][y] = true;
			dir[x][y] = ((i+2)&3);
			return true;
		}
		else if ((yes & (1<<i)) && (no & (1<<((i+1)&3))))
		{
			if ((no & (1<<((i+3)&3))) || (yes & (1<<((i+2)&3))))
			{
				dead = true;
				return false;
			}
			decide[x][y] = true;
			dir[x][y] = ((i+3)&3);
			return true;
		}
		else if ((yes & (1<<i)) && (no & (1<<((i+3)&3))))
		{
			if ((no & (1<<((i+1)&3))) || (yes & (1<<((i+2)&3))))
			{
				dead = true;
				return false;
			}
			decide[x][y] = true;
			dir[x][y] = i;
			return true;
		}
	}
	return false;
}

int main()
{
	int i, j, k;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m; j++)
			{
				decide[i][j] = false;
			}
		}
		dead = false;
		v.clear();
		for (i=0; i<n&&!dead; i++)
		{
			for (j=0; j<m&&!dead; j++)
			{
				if (judge(i, j))
				{
					//printf("%d %d => true.\n", i, j);
					v.emplace_back(i, j);
				}
			}
		}
		for (i=0; i<v.size()&&!dead; i++)
		{
			pp now = v[i];
			for (k=0; k<4; k++)
			{
				pp nxt = now;
				nxt.first += dx[k];
				nxt.second += dy[k];
				if (valid(nxt.first, nxt.second) && !decide[nxt.first][nxt.second] && judge(nxt.first, nxt.second))
				{
					v.emplace_back(nxt);
				}
			}
		}
		if (!dead && v.size() == n*m)
		{
			puts("Possible");
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}

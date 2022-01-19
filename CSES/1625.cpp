#include <iostream>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const char *key = "RDLU";
int tbl[128];
int ucnt, u2[8][8];
int ans;
int qx[64], qy[64];
int ind[8][8];
bool used[8][8];
char str[64];

bool valid(int x, int y)
{
	return x >= 0 && x < 7 && y >= 0 && y < 7;
}

bool can(int x, int y)
{
	return valid(x, y) && !used[x][y];
}

int bfs(int x, int y)
{
	int i, j, k, tx, ty;
	++ucnt;
	qx[0] = x;
	qy[0] = y;
	u2[x][y] = ucnt;
	u2[6][0] = ucnt;
	for (i=0, j=1; i<j; i++)
	{
		x = qx[i];
		y = qy[i];
		for (k=0; k<4; k++)
		{
			tx = x + dx[k];
			ty = y + dy[k];
			if (can(tx, ty) && u2[tx][ty] != ucnt)
			{
				u2[tx][ty] = ucnt;
				qx[j] = tx;
				qy[j] = ty;
				++j;
			}
		}
	}
	return j+(qx[0]!=6||qy[0]!=0);
}

bool check(int depth, int x, int y)
{
	int k, tx, ty;
	for (k=0; k<4; k++)
	{
		if (!can(x+dx[k], y+dy[k]) && !can(x+dx[(k+2)&3], y+dy[(k+2)&3])
			&& can(x+dx[(k+1)&3], y+dy[(k+1)&3]) && can(x+dx[(k+3)&3], y+dy[(k+3)&3]))
		{
			return false;
		}
		if (can(x+dx[k], y+dy[k]) && can(x+dx[(k+1)&3], y+dy[(k+1)&3])
			&& !can(x+dx[k]+dx[(k+1)&3], y+dy[k]+dy[(k+1)&3]))
		{
			return false;
		}
	}
	return true;
	for (k=0; k<4; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (can(tx, ty))
		{
			if (bfs(tx, ty) + depth != 48)
			{
				return false;
			}
		}
	}
	return true;
}

void dfs(int depth, int x, int y)
{
	int k, tx, ty, cnt;
	if (depth == 48)
	{
		++ans;
		return;
	}
	if (!check(depth, x, y))
	{
		return;
	}
	cnt = 0;
	for (k=0; k<4; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (can(tx, ty))
		{
			--ind[tx][ty];
			if (ind[tx][ty] == 1 && (tx != 6 || ty != 0))
			{
				++cnt;
			}
		}
	}
	if (cnt < 2)
	{
		for (k=0; k<4; k++)
		{
			if (str[depth] == '?' || tbl[str[depth]] == k)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				if (can(tx, ty))
				{
					if (depth == 47 || (tx != 6 || ty != 0))
					{
						if (cnt == 0 || ind[tx][ty] == 1)
						{
							used[tx][ty] = true;
							dfs(depth+1, tx, ty);
							used[tx][ty] = false;
						}
					}
				}
			}
		}
	}
	for (k=0; k<4; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (can(tx, ty))
		{
			++ind[tx][ty];
		}
	}
}

int main()
{
	int i, j, k;
	used[0][0] = true;
	for (i=0; i<7; i++)
	{
		for (j=0; j<7; j++)
		{
			for (k=0; k<4; k++)
			{
				if (valid(i+dx[k], j+dy[k]))
				{
					++ind[i][j];
				}
			}
		}
	}
	for (i=0; i<4; i++)
	{
		tbl[key[i]] = i;
	}
	while (scanf("%s", str) == 1)
	{
		ans = 0;
		dfs(0, 0, 0);
		printf("%d\n", ans);
	}
	return 0;
}

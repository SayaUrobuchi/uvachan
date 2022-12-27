#include <iostream>
using namespace std;

int n, m;
int val[128];
int ucnt, used[2048][2048];
int dp[2048][2048];
char board[2048][2048];

int recurs(int x, int y)
{
	int res;
	if (used[x][y] == ucnt)
	{
		return dp[x][y];
	}
	used[x][y] = ucnt;
	if ((x+y) & 1)
	{
		res = 2e9;
		if (x+1 < n)
		{
			res = min(res, recurs(x+1, y)-val[board[x+1][y]]);
		}
		if (y+1 < m)
		{
			res = min(res, recurs(x, y+1)-val[board[x][y+1]]);
		}
		if (res > 1e9)
		{
			res = 0;
		}
	}
	else
	{
		res = -2e9;
		if (x+1 < n)
		{
			res = max(res, recurs(x+1, y)+val[board[x+1][y]]);
		}
		if (y+1 < m)
		{
			res = max(res, recurs(x, y+1)+val[board[x][y+1]]);
		}
		if (res < -1e9)
		{
			res = 0;
		}
	}
	return dp[x][y] = res;
}

int main()
{
	int i, j, t, res;
	val['+'] = 1;
	val['-'] = -1;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++ucnt;
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		res = recurs(0, 0);
		//printf("%d\n", res);
		if (res > 0)
		{
			puts("Takahashi");
		}
		else if (res == 0)
		{
			puts("Draw");
		}
		else
		{
			puts("Aoki");
		}
	}
	return 0;
}


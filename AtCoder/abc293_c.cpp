#include <iostream>
#include <algorithm>
using namespace std;

const int N = 12;
const int M = 12;

int n, m;
int ans = 0;
int ary[N*M];
bool used[N*M];
int board[N][M];

void dfs(int x, int y)
{
	if (x >= n || y >= m)
	{
		return;
	}
	if (used[board[x][y]])
	{
		return;
	}
	used[board[x][y]] = true;
	if (x == n-1 && y == m-1)
	{
		++ans;
	}
	else
	{
		dfs(x, y+1);
		dfs(x+1, y);
	}
	used[board[x][y]] = false;
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &board[i][j]);
			ary[i*m+j] = board[i][j];
		}
	}
	sort(ary, ary+n*m);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			board[i][j] = lower_bound(ary, ary+n*m, board[i][j]) - ary;
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using pp = pair<int, int>;

const int N = 1005;

int n, m;
char board[N][N];
bool used[N][N];
vector<pp> que;

inline void push(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || used[x][y])
	{
		return;
	}
	if (board[x][y] != 'O')
	{
		return;
	}
	used[x][y] = true;
	que.emplace_back(x, y);
}

int main()
{
	int o, i, a;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<o; i++)
	{
		scanf("%d", &a);
		que.emplace_back(0, a);
		used[0][a] = true;
	}
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	for (i=0; i<que.size(); i++)
	{
		int x, y;
		tie(x, y) = que[i];
		board[x][y] = '~';
		if (x+1 < n && !used[x+1][y])
		{
			if (board[x+1][y] == 'O')
			{
				push(x+1, y);
			}
			else
			{
				push(x, y+1);
				push(x, y-1);
			}
		}
	}
	for (i=0; i<n; i++)
	{
		puts(board[i]);
	}
	return 0;
}

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int N = 1008;
const int M = 1008;
const char WATER = '0';
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

bool used[N][M];
char board[N][M];

int main()
{
	int n, m, i, k;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%s", board[i]+1);
		board[i][0] = board[i][m+1] = WATER;
	}
	for (i=0; i<=m+1; i++)
	{
		board[0][i] = board[n+1][i] = WATER;
	}
	vector<pp> que;
	que.emplace_back(0, 0);
	used[0][0] = true;
	int ans = 0;
	for (i=0; i<que.size(); i++)
	{
		int x, y;
		tie(x, y) = que[i];
		for (k=0; k<4; k++)
		{
			int tx = x + DX[k];
			int ty = y + DY[k];
			if (tx >= 0 && tx <= n+1 && ty >= 0 && ty <= m+1)
			{
				if (board[tx][ty] == WATER && !used[tx][ty])
				{
					used[tx][ty] = true;
					que.emplace_back(tx, ty);
				}
				else if (board[tx][ty] != WATER)
				{
					++ans;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

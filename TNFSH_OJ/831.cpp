#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int N = 128;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};

char board[N][N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	int sx, sy;
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
		for (j=0; j<n; j++)
		{
			if (board[i][j] == '*')
			{
				sx = i;
				sy = j;
			}
		}
	}
	vector<pp> que;
	que.emplace_back(sx, sy);
	for (i=0; i<que.size(); i++)
	{
		int x = que[i].first;
		int y = que[i].second;
		for (k=0; k<4; k++)
		{
			int tx = x + DX[k];
			int ty = y + DY[k];
			if (tx >= 0 && tx < n && ty >= 0 && ty < n)
			{
				if (board[tx][ty] == '.')
				{
					board[tx][ty] = '*';
					que.emplace_back(tx, ty);
				}
			}
		}
	}
	for (i=0; i<n; i++)
	{
		puts(board[i]);
	}
	return 0;
}
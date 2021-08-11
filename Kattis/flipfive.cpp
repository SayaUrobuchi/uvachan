#include <iostream>
using namespace std;

const char B = '*';
const char W = '.';

int best;
int dx[] = {0, 1, 0, -1, 0};
int dy[] = {1, 0, -1, 0, 0};

char board[4][4];

void rev(int x, int y)
{
	int i, tx, ty;
	for (i=0; i<5; i++)
	{
		tx = x + dx[i];
		ty = y + dy[i];
		if (tx >= 0 && tx < 3 && ty >= 0 && ty < 3)
		{
			if (board[tx][ty] == B)
			{
				board[tx][ty] = W;
			}
			else
			{
				board[tx][ty] = B;
			}
		}
	}
}

void dfs(int x, int y, int d)
{
	int i;
	if (y >= 3)
	{
		y = 0;
		++x;
		if (x == 3)
		{
			for (i=0; i<3; i++)
			{
				if (board[2][i] != W)
				{
					break;
				}
			}
			if (i >= 3)
			{
				best = min(best, d);
			}
			return;
		}
	}
	// not change
	if (x == 0 || board[x-1][y] == W)
	{
		dfs(x, y+1, d);
	}
	// change
	if (x == 0 || board[x-1][y] == B)
	{
		rev(x, y);
		dfs(x, y+1, d+1);
		rev(x, y);
	}
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while (count--)
	{
		for (i=0; i<3; i++)
		{
			scanf("%s", board[i]);
		}
		best = 16;
		dfs(0, 0, 0);
		printf("%d\n", best);
	}
	return 0;
}

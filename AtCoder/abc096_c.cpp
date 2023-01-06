#include <iostream>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

char board[64][64];

int main()
{
	int n, m, i, j, k, t, x, y;
	bool gg;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	for (i=0, gg=false; i<n&&!gg; i++)
	{
		for (j=0; j<m&&!gg; j++)
		{
			if (board[i][j] == '#')
			{
				for (k=0, t=0; k<4&&!t; k++)
				{
					x = i + dx[k];
					y = j + dy[k];
					t += (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '#');
				}
				if (!t)
				{
					gg = true;
				}
			}
		}
	}
	if (gg)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	return 0;
}

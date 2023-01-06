#include <iostream>
using namespace std;

const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

char board[64][64];

int main()
{
	int n, m, i, j, k, x, y, t;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (board[i][j] == '.')
			{
				for (k=0, t=0; k<8; k++)
				{
					x = i + dx[k];
					y = j + dy[k];
					t += (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == '#');
				}
				board[i][j] = '0' + t;
			}
		}
		puts(board[i]);
	}
	return 0;
}

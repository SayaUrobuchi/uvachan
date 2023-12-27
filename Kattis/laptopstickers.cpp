#include <iostream>
using namespace std;

const int N = 55;

char board[N][N];

int main()
{
	int n, m, o, i, j, k, a, b, x, y;
	scanf("%d%d%d", &m, &n, &o);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			board[i][j] = '_';
		}
	}
	for (k=0; k<o; k++)
	{
		scanf("%d%d%d%d", &b, &a, &y, &x);
		for (i=0; i<a&&x+i<n; i++)
		{
			for (j=0; j<b&&y+j<m; j++)
			{
				board[x+i][y+j] = 'a' + k;
			}
		}
	}
	for (i=0; i<n; i++)
	{
		puts(board[i]);
	}
	return 0;
}
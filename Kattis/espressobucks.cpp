#include <iostream>

char board[128][128];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<m; j++)
			{
				if (board[i][j] == '.')
				{
					if (!((i-1 >= 0 && board[i-1][j] == 'E')
						|| (j-1 >= 0 && board[i][j-1] == 'E')))
					{
						board[i][j] = 'E';
					}
				}
			}
		}
		for (i=0; i<n; i++)
		{
			puts(board[i]);
		}
	}
	return 0;
}
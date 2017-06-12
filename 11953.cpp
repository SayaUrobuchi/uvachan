#include <stdio.h>

char board[128][128];

int main()
{
	int count, cas, n, i, j, k, b, res;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		res = 0;
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				if (board[i][j] != '.')
				{
					b = (board[i][j] == 'x' ? 1 : 0);
					board[i][j] = '.';
					if (j+1 < n && board[i][j+1] != '.')
					{
						for (k=j+1; k<n&&board[i][k]!='.'; k++)
						{
							b += (board[i][k] == 'x' ? 1 : 0);
							board[i][k] = '.';
						}
						j = k;
					}
					else if (i+1 < n && board[i+1][j] != '.')
					{
						for (k=i+1; k<n&&board[k][j]!='.'; k++)
						{
							b += (board[k][j] == 'x' ? 1 : 0);
							board[k][j] = '.';
						}
					}
					if (b)
					{
						res++;
					}
				}
			}
		}
		printf("Case %d: %d\n", ++cas, res);
	}
	return 0;
}

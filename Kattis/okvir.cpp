#include <iostream>

char board[16][16];

int main()
{
	int n, m, i, j, u, l, r, d;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d%d%d", &u, &l, &r, &d);
		for (i=0; i<n; i++)
		{
			scanf("%s", board[i]);
		}
		for (i=0; i<n+u+d; i++)
		{
			for (j=0; j<m+l+r; j++)
			{
				if (i >= u && i-u < n && j >= l && j-l < m)
				{
					putchar(board[i-u][j-l]);
				}
				else
				{
					putchar(((i+j)&1)?'.':'#');
				}
			}
			puts("");
		}
	}
	return 0;
}

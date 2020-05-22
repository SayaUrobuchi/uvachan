#include <stdio.h>

char s[1048576];
char board[1024][1024];

int main()
{
	int n, m, p, q, i, j, k, l;
	while (scanf("%d%d%d%d", &n, &m, &p, &q) == 4)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			for (j=0, k=0; s[j]; j++)
			{
				for (l=0; l<q; l++, k++)
				{
					board[i][k] = s[j];
				}
			}
			board[i][k] = 0;
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<p; j++)
			{
				puts(board[i]);
			}
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int tbl[128];
char s0[32], s1[32], board[32][32];

int main()
{
	int n, i, p, q;
	while (scanf("%s%s", s0, s1) == 2)
	{
		memset(tbl, -1, sizeof(tbl));
		for (i=0; s1[i]; i++)
		{
			if (tbl[s1[i]] == -1)
			{
				tbl[s1[i]] = i;
			}
		}
		for (i=0; s0[i]; i++)
		{
			if (tbl[s0[i]] != -1)
			{
				q = i;
				p = tbl[s0[i]];
				break;
			}
		}
		n = strlen(s0);
		memset(board, '.', sizeof(board));
		strcpy(board[p], s0);
		for (i=0; s1[i]; i++)
		{
			board[i][q] = s1[i];
			board[i][n] = 0;
			puts(board[i]);
		}
	}
	return 0;
}

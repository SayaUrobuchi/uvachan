#include <stdio.h>

#define N 1024

int tbl[N][N], pp[N];
char board[N][N], pat[N][N], bb[N][N], (*bb0)[N], (*bb1)[N], (*bt)[N];

int main()
{
	int n, m, i, j, k, h, p, tt, res;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		gets(board[0]);
		for (i=1, tt=1; i<m; i++, tt*=26);
		for (i=0; i<n; i++)
		{
			gets(board[i]);
			for (j=0, h=0; j<m; j++)
			{
				h = h*26 + (board[i][j]-'A');
			}
			for (j=0, k=j+m; k<=n; j++, k++)
			{
				tbl[i][j] = h;
				h = (h - tt * (board[i][j]-'A')) * 26 + (board[i][k]-'A');
			}
		}
		for (i=0; i<m; i++)
		{
			gets(pat[i]);
		}
		bb0 = pat;
		bb1 = bb;
		for (k=0; k<4; k++)
		{
			res = 0;
			for (i=0; i<m; i++)
			{
				for (j=0, h=0; j<m; j++)
				{
					h = h*26 + (bb0[i][j]-'A');
				}
				pp[i] = h;
			}
			for (i=0; i+m<=n; i++)
			{
				for (j=0; j+m<=n; j++)
				{
					for (p=0; p<m; p++)
					{
						if (tbl[i+p][j] != pp[p])
						{
							break;
						}
					}
					if (p >= m)
					{
						++res;
					}
				}
			}
			for (i=0; i<m; i++)
			{
				for (j=0; j<m; j++)
				{
					bb1[i][j] = bb0[m-j-1][i];
				}
			}
			bt = bb0;
			bb0 = bb1;
			bb1 = bt;
			printf(k?" %d":"%d", res);
		}
		printf("\n");
	}
	return 0;
}


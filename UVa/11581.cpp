#include <stdio.h>
#include <string.h>

int tbl[3][3], res[3][3];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int nxt[512], ord[512];
char board[4][4];

int main()
{
	int count, i, j, k, t, x, y, p, l;
	scanf("%d", &count);
	for (i=0; i<512; i++)
	{
		for (j=0, t=i; j<3; j++)
		{
			for (k=0; k<3; k++, t>>=1)
			{
				tbl[j][k] = (t&1);
			}
		}
		p = 0;
		for (j=0; j<3; j++)
		{
			for (k=0; k<3; k++)
			{
				res[j][k] = 0;
				for (l=0; l<4; l++)
				{
					x = j+dx[l];
					y = k+dy[l];
					if (x >= 0 && x < 3 && y >= 0 && y < 3)
					{
						res[j][k] += tbl[x][y];
					}
				}
				res[j][k] &= 1;
				if (res[j][k])
				{
					p += (1<<(j*3+k));
				}
			}
		}
		nxt[i] = p;
	}
	while (count--)
	{
		p = 0;
		for (i=0; i<3; i++)
		{
			scanf("%s", board[i]);
			for (j=0; j<3; j++)
			{
				if (board[i][j] == '1')
				{
					p += (1<<(i*3+j));
				}
			}
		}
		memset(ord, -1, sizeof(ord));
		i = 0;
		while (ord[p] == -1)
		{
			ord[p] = i++;
			p = nxt[p];
		}
		printf("%d\n", ord[p]-1);
	}
	return 0;
}

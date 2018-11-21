#include <stdio.h>

int ary[64][64];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int main()
{
	int n, i, j, k, l, x, y, dir, nn;
	while (scanf("%d%d", &n, &dir) == 2)
	{
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
			{
				scanf("%d", &ary[i][j]);
			}
		}
		x = (n>>1);
		y = x;
		printf("%d", ary[x][y]);
		for (i=1, k=1, nn=n*n; k<nn; i++)
		{
			for (l=0; l<2&&k<nn; l++)
			{
				for (j=0; j<i&&k<nn; j++, k++)
				{
					x += dx[dir];
					y += dy[dir];
					printf("%d", ary[x][y]);
				}
				dir = (dir+1) & 3;
			}
		}
		puts("");
	}
	return 0;
}

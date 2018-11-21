#include <stdio.h>

int n, m;
int wayx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int wayy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int queuex[300000], queuey[300000];
char map[600][600];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main()
{
	int i, j, k, c, p, q, x, y, tx, ty;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		for(i=0, c=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(map[i][j] == '1')
				{
					c++;
					map[i][j] = '0';
					queuex[0] = i;
					queuey[0] = j;
					for(p=0, q=1; p<q; p++)
					{
						x = queuex[p];
						y = queuey[p];
						for(k=0; k<8; k++)
						{
							tx = x + wayx[k];
							ty = y + wayy[k];
							if(valid(tx, ty) && map[tx][ty] == '1')
							{
								map[tx][ty] = '0';
								queuex[q] = tx;
								queuey[q] = ty;
								q++;
							}
						}
					}
				}
			}
		}
		if(c == 0)
		{
			printf("0\n");
		}
		else if(c == 1)
		{
			printf("1\n");
		}
		else if(c == 2)
		{
			printf("2\n");
		}
		else if(c <= 4)
		{
			printf("3\n");
		}
		else if(c <= 6)
		{
			printf("4\n");
		}
		else if(c <= 10)
		{
			printf("5\n");
		}
		else if(c <= 12)
		{
			printf("6\n");
		}
		else if(c <= 14)
		{
			printf("7\n");
		}
		else if(c <= 16)
		{
			printf("8\n");
		}
		else if(c <= 18)
		{
			printf("9\n");
		}
		else
		{
			printf("10\n");
		}
	}
	return 0;
}

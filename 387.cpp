#include <stdio.h>
#include <string.h>

int n;
int used[5];
int num[5];
int aryx[5][20], aryy[5][20];
char board[5][5];
char buf[1005];

int valid(int x, int y)
{
	return x >= 0 && x < 4 && y >= 0 && y < 4 && !board[x][y];
}

int dfs(int x, int y)
{
	int i, j;
	int *px, *py;
	if(y >= 4)
	{
		x++;
		y = 0;
	}
	if(x >= 4)
	{
		for(i=0; i<n; i++)
		{
			if(!used[i])
			{
				return 0;
			}
		}
		for(i=0; i<4; i++)
		{
			printf("%s\n", board[i]);
		}
		return 1;
	}
	if(board[x][y])
	{
		return dfs(x, y+1);
	}
	/*for(i=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(board[i][j])
			{
				printf("%c", board[i][j]);
			}
			else
			{
				printf("0");
			}
		}
		printf("\n");
	}*/
	for(i=0; i<n; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			for(j=0, px=aryx[i], py=aryy[i]; j<num[i]; j++)
			{
				if(!valid(x+px[j], y+py[j]))
				{
					break;
				}
			}
			if(j == num[i])
			{
				for(j=0; j<num[i]; j++)
				{
					board[x+px[j]][y+py[j]] = '1' + i;
				}
				if(dfs(x, y+1))
				{
					return 1;
				}
				for(j=0; j<num[i]; j++)
				{
					board[x+px[j]][y+py[j]] = 0;
				}
			}
			used[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int cas, i, j, k, l, c, x, y, tx, ty;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0, c=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			for(j=0, l=0; j<x; j++)
			{
				scanf("%s", buf);
				for(k=0; k<y; k++)
				{
					if(buf[k] == '1')
					{
						if(!l)
						{
							tx = j;
							ty = k;
						}
						aryx[i][l] = j - tx;
						aryy[i][l++] = k - ty;
						c++;
					}
				}
			}
			num[i] = l;
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		memset(board, 0, sizeof(board));
		memset(used, 0, sizeof(used));
		if(c != 16 || !dfs(0, 0))
		{
			printf("No solution possible\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int n, d;
int list[81], listx[81], listy[81], temp[81];
int row[10][10], column[10][10], area[4][4][10];
char map[10][10];

int dfs(int depth)
{
	int i, l, x, y;
	if(depth == n)
	{
		return 1;
	}
	x = listx[depth];
	y = listy[depth];
	if(map[x][y] != '.')
	{
		return dfs(depth+1);
	}
	for(i=1, l=0; i<=9; i++)
	{
		if(row[x][i] == 0 && column[y][i] == 0 && area[x/3][y/3][i] == 0)
		{
			row[x][i] = column[y][i] = area[x/3][y/3][i] = 1;
			list[depth] = i;
			if(dfs(depth+1))
			{
				if(++l == 2)
				{
					if(d == -1 || d > depth)
					{
						d = depth;
						memcpy(temp, list, sizeof(list));
					}
					row[x][i] = column[y][i] = area[x/3][y/3][i] = 0;
					return 1;
				}
			}
			row[x][i] = column[y][i] = area[x/3][y/3][i] = 0;
		}
	}
	return l;
}

int main()
{
	int count, i, j, k, x, y;
	scanf("%d", &count);
	while(count--)
	{
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(area, 0, sizeof(area));
		for(i=0, n=0; i<9; i++)
		{
			scanf("%s", map[i]);
			for(j=0; j<9; j++)
			{
				if(map[i][j] == '.')
				{
					listx[n] = i;
					listy[n] = j;
					n++;
				}
				else
				{
					row[i][map[i][j]-'0'] = 1;
					column[j][map[i][j]-'0'] = 1;
					area[i/3][j/3][map[i][j]-'0'] = 1;
				}
			}
		}
		for(i=0; ; )
		{
			d = -1;
			dfs(i);
			if(d == -1)
			{
				break;
			}
			for(j=i; j<=d; j++)
			{
				x = listx[j];
				y = listy[j];
				k = temp[j];
				row[x][k] = column[y][k] = area[x/3][y/3][k] = 1;
			}
			map[x][y] = k + '0';
			i = d + 1;
		}
		for(i=0; i<9; i++)
		{
			printf("%s\n", map[i]);
		}
		/*printf("\n");
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				if(map[i][j] == '.')
				{
					printf("0 ");
				}
				else
				{
					printf("%c ", map[i][j]);
				}
			}
			printf("\n");
		}
		printf("\n");*/
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int k;
int row[10][10];
int column[10][10];
int area[4][4][10];
int listx[100], listy[100];
int tbl[10] = {'*', 'R', 'O', 'Y', 'G', 'B', 'I', 'P', 'L', 'W'};
int hash[128];
int board[15][15];
char map[15][15];

int dfs(int depth)
{
	int i, x, y;
	if(depth == k)
	{
		return 1;
	}
	x = listx[depth];
	y = listy[depth];
	for(i=1; i<10; i++)
	{
		if(!row[x][i] && !column[y][i] && !area[x/3][y/3][i])
		{
			row[x][i] = column[y][i] = area[x/3][y/3][i] = 1;
			board[x][y] = i;
			if(dfs(depth+1))
			{
				return 1;
			}
			row[x][i] = column[y][i] = area[x/3][y/3][i] = 0;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	for(i=1; i<10; i++)
	{
		hash[tbl[i]] = i;
	}
	while(scanf("%s", map[0]) == 1)
	{
		for(i=1; i<9; i++)
		{
			scanf("%s", map[i]);
		}
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(area, 0, sizeof(area));
		for(i=0, k=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				board[i][j] = hash[map[i][j]];
				if(board[i][j])
				{
					row[i][board[i][j]] = 1;
					column[j][board[i][j]] = 1;
					area[i/3][j/3][board[i][j]] = 1;
				}
				else
				{
					listx[k] = i;
					listy[k++] = j;
				}
			}
		}
		dfs(0);
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				/*printf("%d %d: hash %d, %c\n", i, j, hash[map[i][j]], map[i][j]);*/
				if(!(hash[map[i][j]]))
				{
					printf("%c", tbl[board[i][j]]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

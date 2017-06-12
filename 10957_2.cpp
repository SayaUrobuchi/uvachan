#include <stdio.h>
#include <string.h>

int k, count;
int map[9][9];
int row[9][10];
int column[9][10];
int area[3][3][10];
int listx[81], listy[81];

int dfs(int now)
{
	int i, x, y;
	if(now == k)
	{
		count++;
		if(count == 2)
		{
			return 1;
		}
		return 0;
	}
	x = listx[now];
	y = listy[now];
	for(i=1; i<10; i++)
	{
		if(!row[x][i] && !column[y][i] && !area[x/3][y/3][i])
		{
			map[x][y] = i;
			row[x][i] = column[y][i] = area[x/3][y/3][i] = 1;
			if(dfs(now+1))
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
	int cas, i, j, flag, temp;
	cas = 0;
	while(scanf("%d", &map[0][0]) == 1)
	{
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(area, 0, sizeof(area));
		for(i=0, flag=0, k=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				if(i || j)
				{
					scanf("%d", &map[i][j]);
				}
				temp = map[i][j];
				if(temp)
				{
					if(row[i][temp])
					{
						flag = 1;
					}
					else
					{
						row[i][temp] = 1;
					}
					if(column[j][temp])
					{
						flag = 1;
					}
					else
					{
						column[j][temp] = 1;
					}
					if(area[i/3][j/3][temp])
					{
						flag = 1;
					}
					else
					{
						area[i/3][j/3][temp] = 1;
					}
				}
				else
				{
					listx[k] = i;
					listy[k++] = j;
				}
			}
		}
		if(flag)
		{
			printf("Case %d: Illegal.\n", ++cas);
		}
		else
		{
			count = 0;
			dfs(0);
			if(!count)
			{
				printf("Case %d: Impossible.\n", ++cas);
			}
			else if(count == 1)
			{
				printf("Case %d: Unique.\n", ++cas);
			}
			else
			{
				printf("Case %d: Ambiguous.\n", ++cas);
			}
		}
	}
	return 0;
}

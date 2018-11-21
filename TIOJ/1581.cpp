#include <stdio.h>

int k, ans;
int res[4][4], ary[4][4];
int listx[20], listy[20];
int row[4][10], col[4][10], tbl[4][4][10];

void dfs(int depth)
{
	int i, j, x, y;
	if(depth == k)
	{
		if(ans == 0)
		{
			for(i=0; i<4; i++)
			{
				for(j=0; j<4; j++)
				{
					res[i][j] = ary[i][j];
				}
			}
		}
		ans++;
		return;
	}
	x = listx[depth];
	y = listy[depth];
	for(i=1; i<=4; i++)
	{
		if(row[x][i] == 0 && col[y][i] == 0 && tbl[x>>1][y>>1][i] == 0)
		{
			row[x][i] = 1;
			col[y][i] = 1;
			tbl[x>>1][y>>1][i] = 1;
			ary[x][y] = i;
			dfs(depth+1);
			row[x][i] = 0;
			col[y][i] = 0;
			tbl[x>>1][y>>1][i] = 0;
		}
	}
}

int main()
{
	int i, j;
	for(i=0, k=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			scanf("%d", &ary[i][j]);
			if(ary[i][j] < 0 || ary[i][j] > 4)
			{
				break;
			}
			if(ary[i][j] == 0)
			{
				listx[k] = i;
				listy[k] = j;
				k++;
			}
			else if(row[i][ary[i][j]] || col[j][ary[i][j]] || tbl[i/2][j/2][ary[i][j]])
			{
				break;
			}
			else
			{
				row[i][ary[i][j]] = 1;
				col[j][ary[i][j]] = 1;
				tbl[i/2][j/2][ary[i][j]] = 1;
			}
		}
		if(j < 4)
		{
			break;
		}
	}
	if(i < 4)
	{
		printf("I can not solve!!\n");
		return 0;
	}
	dfs(0);
	if(ans)
	{
		for(i=0; i<4; i++)
		{
			for(j=0; j<4; j++)
			{
				printf("%d", res[i][j]);
			}
			printf("\n");
		}
		printf("\nWe have %d way(s) to solve it!!\n", ans);
	}
	else
	{
		printf("I can not solve!!\n");
	}
	scanf(" ");
	return 0;
}

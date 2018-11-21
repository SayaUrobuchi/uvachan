#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans, pn;
int px[85], py[85], pp[85], row[10][10], col[10][10], area[5][5][10], tbl[128];
int price[128], cnt[128];
char board[15][15];

int comp(const void *p, const void *q)
{
	int pp, qq;
	pp = board[px[*(int*)p]][py[*(int*)p]];
	qq = board[px[*(int*)q]][py[*(int*)q]];
	if(price[pp] != price[qq])
	{
		return price[qq]-price[pp];
	}
	if(cnt[pp] != cnt[qq])
	{
		return cnt[qq]-cnt[pp];
	}
	return pp-qq;
}

void dfs(int d)
{
	int x, y, i;
	if(d == pn)
	{
		ans++;
		return;
	}
	x = px[pp[d]];
	y = py[pp[d]];
	if(board[x][y] == '0')
	{
		for(i=1; i<=9; i++)
		{
			if(!row[x][i] && !col[y][i] && !area[x/3][y/3][i])
			{
				row[x][i] = 1;
				col[y][i] = 1;
				area[x/3][y/3][i] = 1;
				dfs(d+1);
				row[x][i] = 0;
				col[y][i] = 0;
				area[x/3][y/3][i] = 0;
			}
		}
	}
	else if(board[x][y] == 'e')
	{
		for(i=2; i<=9; i+=2)
		{
			if(!row[x][i] && !col[y][i] && !area[x/3][y/3][i])
			{
				row[x][i] = 1;
				col[y][i] = 1;
				area[x/3][y/3][i] = 1;
				dfs(d+1);
				row[x][i] = 0;
				col[y][i] = 0;
				area[x/3][y/3][i] = 0;
			}
		}
	}
	else if(board[x][y] == 'o')
	{
		for(i=1; i<=9; i+=2)
		{
			if(!row[x][i] && !col[y][i] && !area[x/3][y/3][i])
			{
				row[x][i] = 1;
				col[y][i] = 1;
				area[x/3][y/3][i] = 1;
				dfs(d+1);
				row[x][i] = 0;
				col[y][i] = 0;
				area[x/3][y/3][i] = 0;
			}
		}
	}
	else
	{
		if(tbl[board[x][y]] == 0)
		{
			for(i=1; i<=9; i++)
			{
				if(!row[x][i] && !col[y][i] && !area[x/3][y/3][i])
				{
					row[x][i] = 1;
					col[y][i] = 1;
					area[x/3][y/3][i] = 1;
					tbl[board[x][y]] = i;
					dfs(d+1);
					row[x][i] = 0;
					col[y][i] = 0;
					area[x/3][y/3][i] = 0;
					tbl[board[x][y]] = 0;
				}
			}
		}
		else
		{
			i = tbl[board[x][y]];
			if(!row[x][i] && !col[y][i] && !area[x/3][y/3][i])
			{
				row[x][i] = 1;
				col[y][i] = 1;
				area[x/3][y/3][i] = 1;
				dfs(d+1);
				row[x][i] = 0;
				col[y][i] = 0;
				area[x/3][y/3][i] = 0;
			}
		}
	}
}

int main()
{
	int count, i, j, num;
	scanf("%d", &count);
	for(i='a'; i<='z'; i++)
	{
		price[i] = 100;
	}
	price['e'] = 50;
	price['o'] = 51;
	while(count--)
	{
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(area, 0, sizeof(area));
		memset(cnt, 0, sizeof(cnt));
		for(i=0, pn=0; i<9; i++)
		{
			scanf("%s", board[i]);
			for(j=0; j<9; j++)
			{
				if(board[i][j] >= '1' && board[i][j] <= '9')
				{
					num = board[i][j]-'0';
					row[i][num] = 1;
					col[j][num] = 1;
					area[i/3][j/3][num] = 1;
				}
				else
				{
					px[pn] = i;
					py[pn] = j;
					pp[pn] = pn;
					cnt[board[i][j]]++;
					pn++;
				}
			}
		}
		cnt['e'] = cnt['o'] = cnt['0'] = 0;
		ans = 0;
		memset(tbl, 0, sizeof(tbl));
		qsort(pp, pn, sizeof(int), comp);
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}

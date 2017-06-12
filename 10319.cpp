#include <stdio.h>
#include <string.h>

int n, m, o;
int row[35], column[35];
int x1[201], x2[201], y1[201], y2[201];
int aryx[201], aryy[201];
int ary2x[201], ary2y[201];

int dfs(int depth)
{
	int rt, ct;
	if(depth == o)
	{
		return 1;
	}
	if(row[x1[depth]] + aryx[depth] != 3 && column[y2[depth]] + aryy[depth] != 3)
	{
		rt = row[x1[depth]];
		row[x1[depth]] = aryx[depth];
		ct = column[y2[depth]];
		column[y2[depth]] = aryy[depth];
		if(dfs(depth+1))
		{
			return 1;
		}
		row[x1[depth]] = rt;
		column[y2[depth]] = ct;
	}
	if(ary2x[depth] != 5)
	{
		if(row[x2[depth]] + ary2x[depth] != 3 && column[y1[depth]] + ary2y[depth] != 3)
		{
			rt = row[x2[depth]];
			row[x2[depth]] = ary2x[depth];
			ct = column[y1[depth]];
			column[y1[depth]] = ary2y[depth];
			if(dfs(depth+1))
			{
				return 1;
			}
			row[x2[depth]] = rt;
			column[y1[depth]] = ct;
		}
	}
	return 0;
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for(i=0; i<o; i++)
		{
			scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
			if(x1[i] < x2[i])
			{
				aryy[i] = 1;
			}
			else if(x1[i] == x2[i])
			{
				aryy[i] = 4;
			}
			else
			{
				aryy[i] = 2;
			}
			if(y1[i] < y2[i])
			{
				aryx[i] = 1;
			}
			else if(y1[i] == y2[i])
			{
				aryx[i] = 4;
			}
			else
			{
				aryx[i] = 2;
			}
			if(x1[i] == x2[i] || y1[i] == y2[i])
			{
				ary2x[i] = 5;
			}
			else
			{
				if(x1[i] < x2[i])
				{
					ary2y[i] = 1;
				}
				else if(x1[i] == x2[i])
				{
					ary2y[i] = 4;
				}
				else
				{
					ary2y[i] = 2;
				}
				if(y1[i] < y2[i])
				{
					ary2x[i] = 1;
				}
				else if(y1[i] == y2[i])
				{
					ary2x[i] = 4;
				}
				else
				{
					ary2x[i] = 2;
				}
			}
		}
		memset(column, 0, sizeof(column));
		memset(row, 0, sizeof(row));
		if(dfs(0))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}

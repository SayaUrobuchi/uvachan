#include <stdio.h>
#include <string.h>

int n, m, o;
int row[35], column[35];
int x1[201], x2[201], y1[201], y2[201];
int aryx[201], aryy[201];
int ary2x[201], ary2y[201];

int dfsc(int depth)
{
	int i;
	if(depth > m)
	{
		for(i=0; i<o; i++)
		{
			if((row[x1[i]] + aryx[i] == 3 || column[y2[i]] + aryy[i] == 3) && (ary2x[i] == 5 || row[x2[i]] + ary2x[i] == 3 || column[y1[i]] + ary2y[i] == 3))
			{
				return 0;
			}
		}
		return 1;
	}
	column[depth] = 1;
	if(dfsc(depth+1))
	{
		return 1;
	}
	column[depth] = 2;
	if(dfsc(depth+1))
	{
		return 1;
	}
	return 0;
}

int dfsr(int depth)
{
	if(depth > n)
	{
		if(dfsc(1))
		{
			return 1;
		}
		return 0;
	}
	row[depth] = 1;
	if(dfsr(depth+1))
	{
		return 1;
	}
	row[depth] = 2;
	if(dfsr(depth+1))
	{
		return 1;
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
		if(dfsr(1))
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

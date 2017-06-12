#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, type;
int hash[540000];
int used[6][6];
int wayx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int wayy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int tbl[128];
char fboard[6][6], sboard[6][6];
char ary[30000][5];
char list[5];
char buf[2008];

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

int getcode(int depth)
{
	int i, times, res;
	for(i=0, times=1, res=0; i<depth; i++, times*=27)
	{
		res += (list[i]-64) * times;
	}
	return res;
}

int check()
{
	int i, res;
	for(i=0, res=0; i<4; i++)
	{
		res += tbl[list[i]];
	}
	return res == 2;
}

void dfs(int x, int y, int depth)
{
	int i, tx, ty;
	if(type)
	{
		if(!hash[getcode(depth)])
		{
			return;
		}
	}
	else
	{
		hash[getcode(depth)] = 1;
	}
	if(depth == 4)
	{
		if(type && check())
		{
			strcpy(ary[n++], list);
			hash[getcode(depth)] = 0;
		}
		return;
	}
	for(i=0; i<8; i++)
	{
		tx = x + wayx[i];
		ty = y + wayy[i];
		if(fboard[tx][ty] && !used[tx][ty])
		{
			if(type)
			{
				list[depth] = sboard[tx][ty];
			}
			else
			{
				list[depth] = fboard[tx][ty];
			}
			used[tx][ty] = 1;
			dfs(tx, ty, depth+1);
			used[tx][ty] = 0;
		}
	}
}

int main()
{
	int cas, i, j;
	cas = 0;
	tbl['A'] = tbl['E'] = tbl['I'] = tbl['O'] = tbl['U'] = tbl['Y'] = 1;
	while(scanf("%s", buf) == 1)
	{
		if(buf[0] == '#')
		{
			break;
		}
		fboard[1][1] = buf[0];
		for(i=1; i<=4; i++)
		{
			for(j=1; j<=4; j++)
			{
				if(i>1 || j>1)
				{
					scanf("%s", buf);
					fboard[i][j] = buf[0];
				}
			}
			for(j=1; j<=4; j++)
			{
				scanf("%s", buf);
				sboard[i][j] = buf[0];
			}
		}
		memset(hash, 0, sizeof(hash));
		type = 0;
		for(i=1; i<=4; i++)
		{
			for(j=1; j<=4; j++)
			{
				memset(used, 0, sizeof(used));
				used[i][j] = 1;
				list[0] = fboard[i][j];
				dfs(i, j, 1);
			}
		}
		type = 1;
		n = 0;
		for(i=1; i<=4; i++)
		{
			for(j=1; j<=4; j++)
			{
				memset(used, 0, sizeof(used));
				used[i][j] = 1;
				list[0] = sboard[i][j];
				dfs(i, j, 1);
			}
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		if(n)
		{
			qsort(ary, n, sizeof(ary[0]), comp);
			for(i=0; i<n; i++)
			{
				puts(ary[i]);
			}
		}
		else
		{
			puts("There are no common words for this pair of boggle boards.");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int m;
int next[10];
int ary[1000000];
int tbl[8];
int list[8];

void init()
{
	int i;
	for(i=0; i<9; i++)
	{
		next[i] = i + 1;
	}
	m = next[i] = 0;
}

int chk(int limit)
{
	int i, loc;
	memset(tbl, 0, sizeof(tbl));
	tbl[0] = 1;
	for(i=1, loc=0; i<limit; i++)
	{
		loc += list[loc];
		loc %= limit;
		if(tbl[loc])
		{
			return 0;
		}
		tbl[loc] = 0;
	}
	loc += list[loc];
	loc %= limit;
	return !loc;
}

void dfs(int depth, int limit)
{
	int i, j;
	if(depth == limit)
	{
		if(chk(limit))
		{
			for(i=0, j=0; i<depth; i++)
			{
				j *= 10;
				j += list[i];
			}
			ary[m++] = j;
		}
		return;
	}
	for(i=0; j=next[i]; i=j)
	{
		list[depth] = j;
		next[i] = next[j];
		dfs(depth+1, limit);
		next[i] = j;
	}
}

int bisearch(int now)
{
	int left, right, center, result;
	left = 0;
	right = m;
	while(left <= right)
	{
		center = left + right;
		center /= 2;
		if(ary[center] == now)
		{
			result = ary[center];
			break;
		}
		else if(ary[center] > now)
		{
			right = center - 1;
			result = ary[center];
		}
		else
		{
			left = center + 1;
		}
	}
	return result;
}

int main()
{
	int cas, n, i;
	cas = 0;
	init();
	for(i=1; i<=7; i++)
	{
		dfs(0, i);
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		printf("Case %d: %d\n", ++cas, bisearch(n));
	}
	return 0;
}

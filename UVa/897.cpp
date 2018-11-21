#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m, l, temp, res[6000], list[10], ary[1000000], dig[4]={1, 3, 7, 9};
char tbl[10000001], used[10];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int recursion(int depth, int value, int lim)
{
	int i;
	if(depth == lim)
	{
		res[l++] = value;
		return tbl[value];
	}
	for(i=0, value*=10; i<lim; i++)
	{
		if(used[i] == 0 && (i == 0 || (list[i] != list[i-1] || used[i-1] == 1)))
		{
			used[i] = 1;
			if(recursion(depth+1, value+list[i], lim))
			{
				return 1;
			}
			used[i] = 0;
		}
	}
	return 0;
}

void check(int d)
{
	int i;
	l = 0;
	memset(used, 0, sizeof(used));
	if(recursion(0, 0, d) == 0)
	{
		for(i=0; i<l; i++)
		{
			ary[m++] = res[i];
		}
	}
}

void dfs(int depth, int last)
{
	int i;
	if(depth > 7)
	{
		return;
	}
	if(depth)
	{
		check(depth);
	}
	for(i=last; i<4; i++)
	{
		list[depth] = dig[i];
		dfs(depth+1, i);
	}
}

void bisearch(int left, int right, int target)
{
	int center;
	if(left > right)
	{
		return;
	}
	center = ((left + right) >> 1);
	if(ary[center] > target)
	{
		temp = ary[center];
		bisearch(left, center-1, target);
	}
	else
	{
		bisearch(center+1, right, target);
	}
}

int main()
{
	int n, i, j, k;
	tbl[1] = 1;
	for(i=3; i<3500; i+=2)
	{
		if(tbl[i] == 0)
		{
			for(j=i*i, k=(i<<1); j<10000000; j+=k)
			{
				tbl[j] = 1;
			}
		}
	}
	m = 0;
	ary[m++] = 2;
	ary[m++] = 5;
	dfs(0, 0);
	qsort(ary, m, sizeof(int), comp);
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		temp = -1;
		bisearch(0, m-1, n);
		if(temp == -1)
		{
			printf("0\n");
		}
		else
		{
			for(j=10; j<=n; j*=10);
			if(temp < j)
			{
				printf("%d\n", temp);
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}

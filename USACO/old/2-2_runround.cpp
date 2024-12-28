/*
	ID: sa072682
	LANG: C
	TASK: runround
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[4000000], c;
char chk[10], digit[11], tbl[10];

void dfs(int depth, int lim)
{
	int i, j;
	if(depth == lim)
	{
		memset(tbl, 0, sizeof(tbl));
		tbl[0] = 1;
		for(i=1, j=0; i<lim; i++)
		{
			j += digit[j] - 48;
			j %= lim;
			if(tbl[j])
			{
				break;
			}
			tbl[j] = 1;
		}
		if(i == lim && !((j+digit[j]-48)%lim))
		{
			ary[c++] = atoi(digit);
		}
		return;
	}
	for(i=1; i<10; i++)
	{
		if(chk[i])
		{
			digit[depth] = i + 48;
			chk[i] = 0;
			dfs(depth+1, lim);
			chk[i] = 1;
		}
	}
}

int bisearch(int target)
{
	int center, left, right;
	left = 0;
	right = c - 1;
	while(1)
	{
		center = left + right;
		center /= 2;
		if(ary[center] == target)
		{
			return center;
		}
		else if(ary[center] > target)
		{
			right = center - 1;
			if(left > right)
			{
				return center;
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				return center + 1;
			}
		}
	}
}

int main()
{
	int n, i, j, k, l;
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	memset(chk, 1, sizeof(chk));
	for(i=1, c=0; i<10; i++)
	{
		digit[i] = 0;
		dfs(0, i);
	}
	scanf("%d", &n);
	i = bisearch(n+1);
	printf("%d\n", ary[i]);
	scanf(" ");
	return 0;
}

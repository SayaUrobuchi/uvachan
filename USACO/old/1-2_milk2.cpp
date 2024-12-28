/*
ID: sa072682
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

int ary[5001][2];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int n, i, lc, li, left, right;
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i][0], &ary[i][1]);
	}
	qsort(ary, n, sizeof(ary[0]), comp);
	for(i=1, li=0, right=ary[0][1], left=ary[0][0], lc=right-left; i<n; i++)
	{
		if(ary[i][0] > right)
		{
			if(ary[i][0] - right > li)
			{
				li = ary[i][0] - right;
			}
			left = ary[i][0];
			right = ary[i][1];
			if(right - left > lc)
			{
				lc = right - left;
			}
		}
		else
		{
			if(ary[i][1] > right)
			{
				right = ary[i][1];
				if(right - left > lc)
				{
					lc = right - left;
				}
			}
		}
	}
	printf("%d %d\n", lc, li);
	scanf(" ");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define N 10005

int ary[N], idx[N], tbl[N];

int comp(const void *p, const void *q)
{
	return ary[*(int*)q] > ary[*(int*)p] ? 1 : -1;
}

int main()
{
	int n, m, i, j, res, blk, now;
	while (scanf("%d%d", &m, &n) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			idx[i] = i;
			tbl[i] = 0;
		}
		qsort(idx, n, sizeof(int), comp);
		res = 0;
		blk = 1;
		for (i=m, j=0; i>=1; i--)
		{
			for (; j<n&&ary[idx[j]]==i; j++)
			{
				++blk;
				now = idx[j];
				tbl[now] = 1;
				if (now == 0 || tbl[now-1])
				{
					--blk;
				}
				if (now+1 == n || tbl[now+1])
				{
					--blk;
				}
			}
			res += blk;
		}
		printf("%d\n", res);
	}
	return 0;
}

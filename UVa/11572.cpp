#include <stdio.h>
#include <stdlib.h>

int ary[1048576], tbl[1048576], idx[1048576], val[1048576];

int comp(const void *p, const void *q)
{
	return ary[*(int*)p] > ary[*(int*)q] ? 1 : -1;
}

int main()
{
	int count, n, m, i, j, t, res, cnt;
	scanf("%d", &count);
	while (count--)
	{
		++cnt;
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			idx[i] = i;
		}
		qsort(idx, n, sizeof(idx[0]), comp);
		res = 0;
		m = -1;
		for (i=0; i<n; i++)
		{
			if (!i || ary[idx[i]] != ary[idx[i-1]])
			{
				++m;
			}
			val[idx[i]] = m;
		}
		for (i=0, j=0; i<n; i++)
		{
			t = val[i];
			if (tbl[t] == cnt)
			{
				while (t != val[j])
				{
					tbl[val[j++]] = 0;
				}
				j++;
			}
			else
			{
				if (i-j+1 > res)
				{
					res = i-j+1;
				}
				tbl[t] = cnt;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}

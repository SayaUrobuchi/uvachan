#include <stdio.h>
#include <stdlib.h>

int ary[1048576], tbl[1048576], *idx[1048576];

int comp(const void *p, const void *q)
{
	return **(int**)p > **(int**)q ? 1 : -1;
}

int main()
{
	int count, n, m, i, j, t, res, cnt, *p;
	scanf("%d", &count);
	while (count--)
	{
		++cnt;
		scanf("%d", &n);
		t = 0;
		p = ary;
		for (i=0; i<n; i++, p++)
		{
			scanf("%d", p);
			idx[i] = p;
			if (*p > t)
			{
				t = *p;
			}
		}
		res = 0;
		if (t >= 1048576)
		{
			qsort(idx, n, sizeof(idx[0]), comp);
			m = 0;
			t = *idx[0];
			for (i=1; i<n; i++)
			{
				*idx[i-1] = m;
				if (*idx[i] != t)
				{
					++m;
					t = *idx[i];
				}
			}
			*idx[n-1] = m;
		}
		for (i=0, j=0; i<n; i++)
		{
			t = ary[i];
			if (tbl[t] == cnt)
			{
				while (t != ary[j])
				{
					tbl[ary[j++]] = 0;
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

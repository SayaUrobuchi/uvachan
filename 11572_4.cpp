#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define N 1048576
#define M 8388608
#define O 1048576

int ary[N], tbl[M+O], *idx[N];

bool comp(int *p, int *q)
{
	return *p < *q;
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
		for (i=0, j=0; i<n; i++, p++)
		{
			scanf("%d", p);
			if (*p > t)
			{
				t = *p;
				idx[j++] = p;
			}
		}
		res = 0;
		if (t >= M)
		{
			std::sort(idx, idx+j, comp);
			m = M+1;
			t = *idx[0];
			for (i=1; i<j; i++)
			{
				*idx[i-1] = m;
				if (*idx[i] != t)
				{
					++m;
					t = *idx[i];
				}
			}
			*idx[j-1] = m;
		}
		// n-j <= res
		for (i=0, j=0; i<n&&n>res+j; i++)
		{
			t = ary[i];
			if (tbl[t] == cnt)
			{
				if (i-j > res)
				{
					res = i-j;
				}
				while (t != ary[j])
				{
					tbl[ary[j++]] = 0;
				}
				j++;
			}
			else
			{
				tbl[t] = cnt;
			}
		}
		if (!res)
		{
			res = n;
		}
		printf("%d\n", res);
	}
	return 0;
}

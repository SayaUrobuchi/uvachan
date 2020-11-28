#include <iostream>

int ary[1048576], cnt[1048576], need[1048576];

int main()
{
	int n, m, o, i, j, t, p, q, best;
	while (scanf("%d%d%d", &n, &m, &o) == 3)
	{
		for (i=0; i<m; i++)
		{
			cnt[i] = 0;
			need[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0; i<o; i++)
		{
			scanf("%d%d", &p, &q);
			need[p] = q;
		}
		for (i=0, j=0, t=0, best=1e9; i<n; i++)
		{
			for (; j<n&&t<o; j++)
			{
				p = ary[j];
				if (cnt[p] < need[p] && cnt[p]+1 >= need[p])
				{
					++t;
				}
				++cnt[p];
			}
			if (t >= o)
			{
				if (j-i < best)
				{
					best = j-i;
				}
			}
			p = ary[i];
			--cnt[p];
			if (cnt[p] < need[p] && cnt[p]+1 >= need[p])
			{
				--t;
			}
		}
		if (best > n)
		{
			puts("impossible");
		}
		else
		{
			printf("%d\n", best);
		}
	}
	return 0;
}

#include <iostream>
#include <algorithm>

int ary[1024];

int main()
{
	int cas, n, m, i, t, p, q, best, ans;
	cas = 0;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		scanf("%d", &m);
		printf("Case %d:\n", ++cas);
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			for (p=0, q=n-1, best=1e9; p<n; p++)
			{
				for (; q>=0&&ary[p]+ary[q]>t; q--)
				{
					if (p != q && best > ary[p]+ary[q]-t)
					{
						best = ary[p]+ary[q]-t;
						ans = ary[p]+ary[q];
					}
				}
				if (q >= 0)
				{
					if (p != q && best > t-ary[p]-ary[q])
					{
						best = t-ary[p]-ary[q];
						ans = ary[p]+ary[q];
					}
				}
			}
			printf("Closest sum to %d is %d.\n", t, ans);
		}
	}
	return 0;
}

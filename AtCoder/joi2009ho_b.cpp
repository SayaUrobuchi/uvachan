#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, m, i, d, p, q, r, mid, t, ans;
	while (scanf("%d%d%d", &d, &n, &m) == 3)
	{
		ary[0] = 0;
		for (i=1; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		ary[n] = d;
		std::sort(ary+1, ary+n);
		for (i=0, ans=0; i<m; i++)
		{
			scanf("%d", &t);
			for (p=0, q=n-1, r=0; p<=q; )
			{
				mid = ((p+q)>>1);
				if (ary[mid] <= t)
				{
					r = mid;
					p = mid+1;
				}
				else
				{
					q = mid-1;
				}
			}
			ans += std::min(t-ary[r], ary[r+1]-t);
		}
		printf("%d\n", ans);
	}
	return 0;
}

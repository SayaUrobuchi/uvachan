#include <iostream>
using namespace std;

int ary[262144];

int main()
{
	int n, m, i, t;
	long long p, q, mid, sum, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, p=1; i<n; i++)
		{
			scanf("%d", &ary[i]);
			p = max(p, (long long)ary[i]);
		}
		for (q=1e18; p<=q; )
		{
			mid = ((p+q) >> 1);
			for (i=0, t=1, sum=0; i<n&&t<=m; i++)
			{
				if (sum+ary[i] > mid)
				{
					sum = 0;
					++t;
				}
				sum += ary[i];
			}
			if (t > m)
			{
				p = mid + 1;
			}
			else
			{
				ans = mid;
				q = mid - 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}


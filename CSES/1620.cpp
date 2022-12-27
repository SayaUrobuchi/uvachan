#include <iostream>
using namespace std;

int ary[262144];

int main()
{
	int n, m, i;
	long long p, q, mid, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (p=1, q=1e18; p<=q; )
		{
			mid = ((p+q) >> 1);
			for (i=0, t=0; i<n&&t<m; i++)
			{
				t += mid / ary[i];
			}
			if (t >= m)
			{
				ans = mid;
				q = mid - 1;
			}
			else
			{
				p = mid + 1;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}


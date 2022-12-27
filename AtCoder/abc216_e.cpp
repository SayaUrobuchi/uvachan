#include <iostream>
#include <algorithm>
using namespace std;

int ary[131072];

int main()
{
	int n, m, i, cnt;
	long long t, u, last, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		ary[0] = 0;
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		sort(ary, ary+n+1, greater<int>());
		for (i=1, last=ary[0], cnt=1, ans=0; i<=n&&m>0; i++)
		{
			if (last != ary[i])
			{
				t = last - ary[i];
				u = t * cnt;
				if (u > m)
				{
					t = m / cnt;
					ans += (last+last-t+1) * t / 2 * cnt;
					ans += (m%cnt) * (last-t);
					m = 0;
				}
				else
				{
					ans += (last+ary[i]+1) * t / 2 * cnt;
					m -= u;
				}
				last = ary[i];
			}
			++cnt;
		}
		printf("%lld\n", ans);
	}
	return 0;
}


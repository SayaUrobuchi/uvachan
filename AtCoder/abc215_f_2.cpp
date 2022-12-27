#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

pp ary[262144];

int main()
{
	int n, i, p, q, l, low, high, mid, ans;
	bool ok;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &ary[i].first, &ary[i].second);
		}
		sort(ary, ary+n);
		for (p=1, q=1e9, ans=0; p<=q; )
		{
			mid = ((p+q) >> 1);
			for (i=0, l=0, low=2e9, high=-2e9, ok=false; i<n&&!ok; i++)
			{
				for (; l<n&&ary[l].first+mid<=ary[i].first; l++)
				{
					low = min(low, ary[l].second);
					high = max(high, ary[l].second);
				}
				if (l)
				{
					if (low <= ary[i].second-mid || high >= ary[i].second+mid)
					{
						ok = true;
					}
				}
			}
			if (ok)
			{
				ans = mid;
				p = mid + 1;
			}
			else
			{
				q = mid - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}


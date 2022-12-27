#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

pp ary[262144];

int main()
{
	int n, i, p, q, l, r, mid, ans;
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
			r = lower_bound(ary, ary+n, make_pair<int, int>(ary[0].first+mid, 0)) - ary;
			set<pp> se;
			for (i=r; i<n; i++)
			{
				se.insert({ary[i].second, ary[i].first});
			}
			for (i=0, l=0, ok=false; i<n&&!ok; i++)
			{
				for (; l<n&&ary[l].first+mid<=ary[i].first; l++)
				{
					se.insert({ary[l].second, ary[i].first});
				}
				for (; r<n&&ary[r].first<ary[i].first+mid; r++)
				{
					se.erase({ary[r].second, ary[r].first});
				}
				if (se.size())
				{
					auto it = se.begin();
					if (abs(it->first - ary[i].second) >= mid)
					{
						ok = true;
					}
					else
					{
						it = se.end();
						--it;
						if (abs(it->first - ary[i].second) >= mid)
						{
							ok = true;
						}
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


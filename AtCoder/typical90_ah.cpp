#include <iostream>
#include <algorithm>
using namespace std;

int bry[131072], tbl[131072];
pair<int, int> ary[131072];

int main()
{
	int n, m, i, j, t, rnk, last, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i].first);
			ary[i].second = i;
			tbl[i] = 0;
		}
		sort(ary, ary+n);
		for (i=0, rnk=-1, last=ary[0].first-1; i<n; i++)
		{
			if (ary[i].first != last)
			{
				last = ary[i].first;
				++rnk;
			}
			bry[ary[i].second] = rnk;
		}
		for (i=0, j=0, t=0, ans=-1; i<n; i++)
		{
			for (; j<n&&t<=m; j++)
			{
				if (!tbl[bry[j]])
				{
					if (t == m)
					{
						break;
					}
					++t;
				}
				++tbl[bry[j]];
			}
			ans = max(ans, j-i);
			--tbl[bry[i]];
			if (!tbl[bry[i]])
			{
				--t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

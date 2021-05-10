#include <iostream>
#include <algorithm>
using pp = std::pair<int, std::pair<int, int> >;

pp ary[1024];

int main()
{
	int n, i, j, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d%d", &ary[i].first, &ary[i].second.first, &ary[i].second.second);
			++ary[i].second.first;
		}
		std::sort(ary, ary+n, std::greater<pp>());
		for (i=0, ans=0; i<n; i++)
		{
			for (j=i+1, t=0; j<n; j++)
			{
				if (ary[j].second.first <= ary[i].second.first && ary[j].second.second >= ary[i].second.first)
				{
					t = ary[j].first;
					break;
				}
			}
			ans += ary[i].first - t;
			for (j=i+1, t=0; j<n; j++)
			{
				if (ary[j].second.first <= ary[i].second.second && ary[j].second.second >= ary[i].second.second)
				{
					t = ary[j].first;
					break;
				}
			}
			ans += ary[i].first - t;
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <iostream>
#include <algorithm>

int ans[1024];
std::pair<int, int> ary[1024];

int main()
{
	int n, m, c, d, i, sum;
	while (scanf("%d%d%d%d", &c, &m, &n, &d) == 4)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i].first);
			sum += ary[i].first;
			ary[i].second = i;
			ans[i] = 0;
		}
		std::sort(ary, ary+n);
		for (i=0; c>0; i++)
		{
			ans[ary[i].second] = std::min(c, d-ary[i].first);
			sum -= ary[i].first;
			c -= d-ary[i].first;
		}
		if (sum < m)
		{
			puts("impossible");
		}
		else
		{
			printf("%d", ans[0]);
			for (i=1; i<n; i++)
			{
				printf(" %d", ans[i]);
			}
			puts("");
		}
	}
	return 0;
}

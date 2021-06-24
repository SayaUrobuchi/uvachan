#include <iostream>
#include <algorithm>

std::pair<int, int> ary[1024];

int main()
{
	int count, cas, n, i, j, t, u;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &cas, &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i].first);
			ary[i].second = i;
		}
		std::sort(ary, ary+n);
		for (i=1, j=n-1; i<n&&ary[i].second>ary[i-1].second; i++, j--);
		if (i < n)
		{
			t = ary[i].first;
			u = ary[i-1].second;
			for (++i; i<n&&ary[i].first==t; i++)
			{
				if (ary[i].second > u)
				{
					--j;
				}
			}
		}
		printf("%d %d\n", cas, j);
	}
	return 0;
}

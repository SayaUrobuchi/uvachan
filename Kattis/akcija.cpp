#include <iostream>
#include <algorithm>

int ary[1048576];

int main()
{
	int n, i;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n, std::greater<int>());
		for (i=0, ans=0; i<n; i++)
		{
			if (i%3 != 2)
			{
				ans += ary[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

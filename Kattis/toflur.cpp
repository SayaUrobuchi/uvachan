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
		std::sort(ary, ary+n);
		for (i=1, ans=0; i<n; i++)
		{
			ans += (long long)(ary[i]-ary[i-1]) * (long long)(ary[i]-ary[i-1]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

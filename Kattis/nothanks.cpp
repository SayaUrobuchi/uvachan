#include <iostream>
#include <algorithm>

int ary[131072];

int main()
{
	int n, i;
	long long ans;
	ary[0] = -4;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary+1, ary+1+n);
		for (i=1, ans=0; i<=n; i++)
		{
			if (ary[i] != ary[i-1]+1)
			{
				ans += ary[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include <stdio.h>
#include <algorithm>

int w[1048576], f[1048576], idx[1048576];

bool comp(int a, int b)
{
	return w[a]*f[b] < w[b]*f[a];
}

int main()
{
	int n, i;
	long long ans, sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &w[i]);
			idx[i] = i;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &f[i]);
		}
		std::sort(idx, idx+n, comp);
		for (i=0, sum=0, ans=0; i<n; i++)
		{
			ans += sum*f[idx[i]];
			sum += w[idx[i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

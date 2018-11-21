#include <stdio.h>
#include <algorithm>

long long ary[1000005];
long long c[1000005];

long long ab(long long t)
{
	return t<0 ? -t : t;
}

int main()
{
	int n, i;
	long long avg, mid;
	long long sum, ans;
	while (scanf("%d", &n) == 1)
	{
		sum = 0;
		for (i=0; i<n; i++)
		{
			scanf("%lld", &ary[i]);
			sum += ary[i];
		}
		avg = sum / n;
		c[0] = 0;
		for (i=1; i<n; i++)
		{
			c[i] = avg-ary[i]+c[i-1];
		}
		std::nth_element(c, c+(n>>1), c+n);
		ans = 0;
		mid = -c[n>>1];
		for (i=0; i<n; i++)
		{
			ans += ab(mid+c[i]);
			//printf("AA %lld\n", mid+c[i]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

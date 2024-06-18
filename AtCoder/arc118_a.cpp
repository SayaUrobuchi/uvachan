#include <iostream>
using namespace std;

int main()
{
	int n, t;
	scanf("%d%d", &t, &n);
	long long l = 1, r = 1e12;
	long long ans = 1;
	while (l <= r)
	{
		long long mid = ((l + r) >> 1);
		long long k = max(0LL, mid * 100 / (100 + t));
		if ((long long)((k+1)*(100+t)/100) <= mid)
		{
			++k;
		}
		//printf(".. %lld %lld\n", mid, k);
		if (mid - k >= n)
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

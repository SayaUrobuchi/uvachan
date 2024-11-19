#include <iostream>
using namespace std;

int main()
{
	long long n, l, r;
	scanf("%lld", &n);
	int ans = 0;
	for (l=1, r=3e9; l<=r; )
	{
		int mid = ((l+r) >> 1);
		long long t = mid * 1LL * (mid+1) / 2;
		if (t <= n+1)
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	printf("%lld\n", n-ans+1);
	return 0;
}

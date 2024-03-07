#include <iostream>
#include <cmath>
using namespace std;

long long powb(int a, int b)
{
	long long ret = 1;
	long long t = a;
	while (b)
	{
		if (t > 3e9)
		{
			return t;
		}
		if (b & 1)
		{
			ret *= t;
		}
		t *= t;
		b >>= 1;
	}
	return ret;
}

int main()
{
	long long n;
	int i;
	while (scanf("%lld", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		bool is_neg = false;
		if (n < 0)
		{
			n = -n;
			is_neg = true;
		}
		int ans = 1;
		for (i=2; ; i++)
		{
			if ((1LL << i) > n)
			{
				break;
			}
			if (is_neg && !(i & 1))
			{
				continue;
			}
			int l = 2;
			int r = 50000;
			while (l <= r)
			{
				int mid = ((l+r) >> 1);
				long long res = powb(mid, i);
				if (res == n)
				{
					ans = i;
					break;
				}
				else if (res > n)
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

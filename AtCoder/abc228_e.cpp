#include <iostream>
using namespace std;

const int MOD = 998244353;

long long ff(long long a, long long b, long long m)
{
	long long t = a % m;
	long long ret = t ? 1 : 0;
	while (b)
	{
		if (b & 1)
		{
			ret = (ret * t) % m;
		}
		t = (t * t) % m;
		b >>= 1;
	}
	return ret;
}

int main()
{
	long long n, k, m;
	scanf("%lld%lld%lld", &n, &k, &m);
	long long kn = ff(k, n, MOD-1);
	long long ans = ff(m, kn, MOD);
	printf("%lld\n", ans);
	return 0;
}

#include <iostream>
using namespace std;

const int M = 998244353;

long long fastp(int a, long long b)
{
	long long ret = 1;
	long long t = a;
	for (; b; t=(t*t)%M, b>>=1)
	{
		if (b & 1)
		{
			ret = (ret*t) % M;
		}
	}
	return ret;
}

long long rec(long long n, long long nn, int d)
{
	long long ret, f;
	if (nn == 0)
	{
		return 0LL;
	}
	if (nn & 1)
	{
		ret = n % M;
		f = fastp(10, (nn-1));
		f = fastp(f, d);
		ret = (ret * f) % M;
		ret = (ret + rec(n, nn-1, d)) % M;
	}
	else
	{
		ret = rec(n, nn>>1, d);
		f = fastp(10, (nn>>1));
		f = fastp(f, d);
		ret = (ret + ret * f) % M;
	}
	return ret;
}

int main()
{
	long long n, nn;
	scanf("%lld", &n);
	int d = 1;
	for (nn=n; nn>9; nn/=10, ++d);
	long long ans = rec(n, n, d);
	printf("%lld\n", ans);
	return 0;
}

#include <iostream>
using namespace std;

const int M = 998244353;

int main()
{
	int n, m, b;
	scanf("%d%d", &n, &m);
	long long ans = n;
	long long t;
	for (b=m-1, t=n-1; b; b>>=1, t=(t*t)%M)
	{
		if (b & 1)
		{
			ans = (ans * t) % M;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
#include <iostream>
using namespace std;

const int MOD = 998244353;

int main()
{
	long long n, i;
	scanf("%lld", &n);
	int ans = 0;
	for (i=1; i<=n; i*=10)
	{
		long long t = n;
		if (n / 10 >= i)
		{
			t = i * 10 - 1;
		}
		t = t - i + 1;
		ans = (ans + (t % MOD) * ((t+1) % MOD) / 2) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}

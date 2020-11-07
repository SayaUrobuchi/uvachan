#include <iostream>

const int M = 998244353;

int main()
{
	long long a, b, c, ans;
	while (scanf("%lld%lld%lld", &a, &b, &c) == 3)
	{
		ans = ((a*(a+1))/2) % M;
		ans = (ans * ((b*(b+1))/2%M)) % M;
		ans = (ans * ((c*(c+1))/2%M)) % M;
		printf("%lld\n", ans);
	}
	return 0;
}

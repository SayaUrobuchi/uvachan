#include <iostream>

int main()
{
	long long n, m, a, b, ans;
	while (scanf("%lld%lld%lld%lld", &n, &m, &a, &b) == 4)
	{
		ans = 0;
		while (n+b < m && (n+b)/a >= n)
		{
			++ans;
			n *= a;
		}
		ans += (m-n-1) / b;
		printf("%lld\n", ans);
	}
	return 0;
}

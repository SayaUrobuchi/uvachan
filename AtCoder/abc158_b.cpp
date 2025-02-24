#include <iostream>
using namespace std;

int main()
{
	long long n, a, b;
	scanf("%lld%lld%lld", &n, &a, &b);
	long long ans = (n / (a + b)) * a;
	ans += min(a, n % (a + b));
	printf("%lld\n", ans);
	return 0;
}

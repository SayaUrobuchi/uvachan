#include <iostream>
using namespace std;

int main()
{
	long long a, b, k;
	scanf("%lld%lld%lld", &a, &b, &k);
	b -= min(b, max(0LL, k-a));
	a -= min(a, k);
	printf("%lld %lld\n", a, b);
	return 0;
}

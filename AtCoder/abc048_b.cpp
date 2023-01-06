#include <iostream>
using namespace std;

int main()
{
	long long a, b, m, ans;
	scanf("%lld%lld%lld", &a, &b, &m);
	ans = b/m - max(0LL, (a-1)/m);
	if (a == 0)
	{
		++ans;
	}
	printf("%lld\n", ans);
	return 0;
}

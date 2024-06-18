#include <iostream>
using namespace std;

int main()
{
	long long cur, n, d;
	scanf("%lld%lld%lld", &cur, &n, &d);
	cur = abs(cur);
	long long step = min(cur / d, n);
	n -= step;
	cur -= d * step;
	if (n && cur > d - cur)
	{
		--n;
		cur = d - cur;
	}
	if (n & 1)
	{
		cur = d - cur;
	}
	printf("%lld\n", cur);
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int t, ua, ub, ra, rb;
	long long ans;
	scanf("%d%d%d%d", &ua, &ub, &ra, &rb);
	ans = (long long)ra * rb;
	if (rb)
	{
		ans += ua;
		ua = 0;
	}
	else
	{
		t = min(ua, ub);
		ans += t;
		ua -= t;
		ub -= t;
	}
	if (ra)
	{
		ans += ub;
		ub = 0;
	}
	printf("%lld\n", ans);
	return 0;
}

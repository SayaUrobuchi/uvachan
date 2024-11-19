#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	long long ans = 9e18;
	int least = 2e9;
	long long fsum = 0;
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		fsum += a + b;
		least = min(least, b);
		ans = min(ans, fsum + least * (m-i-1LL));
	}
	printf("%lld\n", ans);
	return 0;
}
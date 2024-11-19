#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	long long ans = 0;
	int l = 1-m+1;
	int r = 1;
	for (i=1; i<=n; i++, l++, r++)
	{
		int t;
		scanf("%d", &t);
		int cnt = (min(n-m+1, r) - max(1, l) + 1);
		ans += cnt * 1LL * t;
	}
	printf("%lld\n", ans);
	return 0;
}

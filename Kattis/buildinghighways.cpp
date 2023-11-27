#include <iostream>
using namespace std;

int main()
{
	int n, i, best;
	long long ans;
	scanf("%d", &n);
	for (i=0, ans=0, best=1e9; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		ans += t;
		best = min(best, t);
	}
	ans += (long long)best * (n - 2);
	printf("%lld\n", ans);
	return 0;
}

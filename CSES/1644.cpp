#include <iostream>
#include <set>
using namespace std;

long long sum[262144];

int main()
{
	int n, a, b, i, p, q, t;
	long long ans;
	while (scanf("%d%d%d", &n, &a, &b) == 3)
	{
		sum[0] = 0;
		set<pair<long long, int> > se;
		for (i=1, p=i-b, q=i-a, ans=-1e18; i<=n; i++, p++, q++)
		{
			scanf("%d", &t);
			sum[i] = sum[i-1] + t;
			if (q >= 0)
			{
				se.insert({sum[q], q});
			}
			if (se.size())
			{
				ans = max(ans, sum[i]-(se.begin())->first);
			}
			if (p >= 0)
			{
				se.erase({sum[p], p});
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}


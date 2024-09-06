#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int buy[N], sell[N], cnt[N];
long long ary[N];

int main()
{
	int n, m, o, i, t;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		++cnt[t];
	}
	long long ans = 0;
	for (i=1; i<=m; i++)
	{
		scanf("%d%d", &buy[i], &sell[i]);
		ary[i] = buy[i] * (2 - cnt[i]);
		ary[i] += sell[i] * cnt[i];
		ans += sell[i] * cnt[i];
	}
	sort(ary+1, ary+m+1);
	for (i=1; i<=o; i++)
	{
		ans -= ary[i];
	}
	printf("%lld\n", ans);
	return 0;
}
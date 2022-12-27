#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<int, pp>;

const int N = 131072;

int par[N], cnt[N], rnk[N];
ppp ary[N];

int getpar(int cur)
{
	if (par[cur] == -1)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int main()
{
	int n, i, a, b;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i+1<n; i++)
		{
			scanf("%d%d%d", &ary[i].second.first, &ary[i].second.second, &ary[i].first);
			par[i] = -1;
			cnt[i] = 1;
			rnk[i] = 1;
		}
		par[n-1] = -1;
		cnt[n-1] = 1;
		rnk[n-1] = 1;
		sort(ary, ary+n-1);
		for (i=0, ans=0; i+1<n; i++)
		{
			a = getpar(ary[i].second.first);
			b = getpar(ary[i].second.second);
			ans += ary[i].first * (long long)cnt[a] * cnt[b];
			if (rnk[a] > rnk[b])
			{
				swap(a, b);
			}
			par[a] = b;
			cnt[b] += cnt[a];
			if (rnk[a] == rnk[b])
			{
				++rnk[b];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}


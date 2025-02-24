#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500005;

int ary[N], bry[N];
vector<int> v[N];
vector<long long> u[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0; i<n; i++)
	{
		scanf("%d", &bry[i]);
		long long last = 0;
		if (!u[bry[i]].empty())
		{
			last = u[bry[i]].back();
		}
		v[bry[i]].emplace_back(i);
		u[bry[i]].emplace_back(min(i+1, n-1-i+1));
		if (u[bry[i]].size() > 1)
		{
			u[bry[i]].back() += last;
		}
	}
	long long ans = 0;
	for (i=0; i<n; i++)
	{
		if (ary[i] == bry[i])
		{
			ans += i * (i+1LL) / 2;
			int t = n-i-1;
			ans += t * (t+1LL) / 2;
		}
		if (!v[ary[i]].empty())
		{
			int l = i;
			int r = n-i-1;
			if (l > r)
			{
				swap(l, r);
			}
			int d = min(i+1, n-1-i+1);
			int li = lower_bound(v[ary[i]].begin(), v[ary[i]].end(), l) - v[ary[i]].begin();
			int ri = upper_bound(v[ary[i]].begin(), v[ary[i]].end(), r) - v[ary[i]].begin();
			ans += (ri - li) * 1LL * d;
			if (li > 0)
			{
				ans += u[ary[i]][li-1];
			}
			ans += u[ary[i]].back();
			if (ri > 0)
			{
				ans -= u[ary[i]][ri - 1];
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}

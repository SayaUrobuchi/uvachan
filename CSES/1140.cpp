#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<pp, int>;

ppp ary[200005];
long long dp[400005];

int main()
{
	int n, i, t;
	map<int, int> mp;
	while (scanf("%d", &n) == 1)
	{
		mp.clear();
		mp[0] = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d%d%d", &ary[i].first.second, &ary[i].first.first, &ary[i].second);
			mp[ary[i].first.first] = 1;
			mp[ary[i].first.second] = 1;
			dp[(i<<1)] = dp[((i<<1)|1)] = 0;
		}
		sort(ary, ary+n);
		t = 0;
		for (auto it=mp.begin(); it!=mp.end(); ++it)
		{
			it->second = t++;
		}
		for (i=0, t=1; i<n; i++)
		{
			auto it = mp.find(ary[i].first.first);
			for (; t<=it->second; ++t)
			{
				dp[t] = dp[t-1];
			}
			dp[it->second] = max(dp[it->second], dp[mp[ary[i].first.second]-1]+ary[i].second);
		}
		{
			auto it = mp.end();
			--it;
			printf("%lld\n", dp[it->second]);
		}
	}
	return 0;
}


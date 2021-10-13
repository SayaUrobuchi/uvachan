#include <iostream>
#include <set>
using namespace std;
using pp = pair<int, long long>;
using sss = set<pp>;

int h[262144];

int main()
{
	int n, i, t;
	long long ans;
	sss se;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &h[i]);
		}
		se.clear();
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			pp cur = {h[i], t};
			sss::iterator it = se.lower_bound(cur);
			if (se.size() && it != se.begin())
			{
				--it;
				cur.second += it->second;
				++it;
			}
			while (it != se.end() && it->second <= cur.second)
			{
				sss::iterator tmp = it;
				++it;
				se.erase(tmp);
			}
			se.insert(cur);
			ans = max(ans, cur.second);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

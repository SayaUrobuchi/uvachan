#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using pp = pair<long long, long long>;
using ppp = pair<long long, pp>;

long long dis[131072];
vector<ppp> v[131072];

long long f(long long t, long long c, long long d)
{
	return t + c + d/(t+1);
}

long long calc(long long t, long long c, long long d)
{
	long long ans;
	ans = sqrt(d);
	if (ans < t)
	{
		ans = t;
	}
	return f(ans, c, d);
}

int main()
{
	int n, m, i, a, b, cur, nxt;
	long long c, d, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			dis[i] = 1e18;
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%lld%lld", &a, &b, &c, &d);
			v[a].push_back({b, {c, d}});
			v[b].push_back({a, {c, d}});
		}
		priority_queue<pp, vector<pp>, greater<pp> > pq;
		pq.emplace(0, 1);
		dis[1] = 0;
		ans = -1;
		while (pq.size())
		{
			pp p = pq.top();
			pq.pop();
			cur = p.second;
			d = p.first;
			if (cur == n)
			{
				ans = d;
				break;
			}
			if (d != dis[cur])
			{
				continue;
			}
			for (i=0; i<v[cur].size(); i++)
			{
				nxt = v[cur][i].first;
				t = calc(d, v[cur][i].second.first, v[cur][i].second.second);
				if (dis[nxt] > t)
				{
					dis[nxt] = t;
					pq.emplace(t, nxt);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

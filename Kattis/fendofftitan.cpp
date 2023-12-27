#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<int, long long>;
using pqp = pair<long long, int>;

const int N = 105;
const long long SHAMAN = 1e9 * (N + 5);
const long long TITAN = SHAMAN * (N + 5);

long long dis[N];
vector<pp> v[N];

int main()
{
	int n, m, i, a, b, c, st, ed;
	long long w;
	scanf("%d%d%d%d", &n, &m, &st, &ed);
	for (i=1; i<=n; i++)
	{
		dis[i] = 1e18;
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d%lld%d", &a, &b, &w, &c);
		if (c == 1)
		{
			w += SHAMAN;
		}
		else if (c == 2)
		{
			w += TITAN;
		}
		v[a].emplace_back(b, w);
		v[b].emplace_back(a, w);
	}
	priority_queue<pqp, vector<pqp>, greater<pqp> > pq;
	pq.emplace(0LL, st);
	dis[st] = 0;
	long long ans = -1;
	while (!pq.empty())
	{
		long long d;
		int cur;
		tie(d, cur) = pq.top();
		pq.pop();
		if (dis[cur] != d)
		{
			continue;
		}
		if (cur == ed)
		{
			ans = d;
			break;
		}
		for (i=0; i<v[cur].size(); i++)
		{
			long long w;
			int nxt;
			tie(nxt, w) = v[cur][i];
			if (dis[nxt] > d + w)
			{
				dis[nxt] = d + w;
				pq.emplace(dis[nxt], nxt);
			}
		}
	}
	if (ans == -1)
	{
		puts("IMPOSSIBLE");
	}
	else
	{
		int titan = ans / TITAN;
		ans %= TITAN;
		int shaman = ans / SHAMAN;
		ans %= SHAMAN;
		printf("%lld %d %d\n", ans, shaman, titan);
	}
	return 0;
}

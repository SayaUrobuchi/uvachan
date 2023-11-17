#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<long long, int>;

const int N = 100005;

long long dis[N];
vector<pp> edg[N];

int main()
{
	int n, m, i, a, b, c;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		edg[a].emplace_back(b, c);
	}
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	pq.emplace(0, 1);
	fill(dis+1, dis+n+1, 1e18);
	dis[1] = 0;
	while (!pq.empty())
	{
		int cur;
		long long d;
		tie(d, cur) = pq.top();
		pq.pop();
		if (d != dis[cur])
		{
			continue;
		}
		for (i=0; i<edg[cur].size(); i++)
		{
			int nxt, w;
			tie(nxt, w) = edg[cur][i];
			if (dis[nxt] > dis[cur] + w)
			{
				dis[nxt] = dis[cur] + w;
				pq.emplace(dis[nxt], nxt);
			}
		}
	}
	for (i=1; i<=n; i++)
	{
		printf("%lld%c", dis[i], (i==n?'\n':' '));
	}
	return 0;
}

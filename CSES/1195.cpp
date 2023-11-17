#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using ppp = pair<long long, pp>;

const int N = 100005;

long long dis[N][2];
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
	for (i=1; i<=n; i++)
	{
		dis[i][0] = dis[i][1] = 1e18;
	}
	priority_queue<ppp, vector<ppp>, greater<ppp> > pq;
	dis[1][0] = 0;
	pq.emplace(dis[1][0], make_pair(1, 0));
	while (!pq.empty())
	{
		long long d;
		int cur, u;
		forward_as_tuple(d, tie(cur, u)) = pq.top();
		pq.pop();
		if (d != dis[cur][u])
		{
			continue;
		}
		for (i=0; i<edg[cur].size(); i++)
		{
			int t, w;
			tie(t, w) = edg[cur][i];
			if (dis[t][u] > dis[cur][u] + w)
			{
				dis[t][u] = dis[cur][u] + w;
				pq.emplace(dis[t][u], make_pair(t, u));
			}
			if (!u && dis[t][1] > dis[cur][u] + (w >> 1))
			{
				dis[t][1] = dis[cur][u] + (w >> 1);
				pq.emplace(dis[t][1], make_pair(t, 1));
			}
		}
	}
	printf("%lld\n", min(dis[n][0], dis[n][1]));
	return 0;
}

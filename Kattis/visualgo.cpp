#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
using pp = pair<int, int>;

int main()
{
	int n, m, i, a, b, c, d, s, e, cur, nxt, nd;
	scanf("%d%d", &n, &m);
	vector<vector<pp> > v(n+1);
	vector<bool> used(n+1);
	vector<int> dis(n+1), cnt(n+1);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		v[a].emplace_back(b, c);
	}
	scanf("%d%d", &s, &e);
	used[s] = true;
	dis[s] = 0;
	cnt[s] = 1;
	priority_queue<pp, vector<pp>, greater<pp> > pq;
	pq.emplace(0, s);
	while (pq.size())
	{
		tie(d, cur) = pq.top();
		pq.pop();
		if (d > dis[cur])
		{
			continue;
		}
		for (i=0; i<v[cur].size(); i++)
		{
			nxt = v[cur][i].first;
			nd = d + v[cur][i].second;
			if (!used[nxt] || nd < dis[nxt])
			{
				used[nxt] = true;
				dis[nxt] = nd;
				cnt[nxt] = cnt[cur];
				pq.emplace(nd, nxt);
			}
			else if (nd == dis[nxt])
			{
				cnt[nxt] += cnt[cur];
			}
		}
	}
	printf("%d\n", cnt[e]);
	return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<long long, int>;
using pqq = priority_queue<pp, vector<pp>, greater<pp> >;

int n;
long long dis[2][131072];
vector<pair<int, int> > v[131072];

void dijkstra(int st, long long dis[])
{
	int i, t, cur, nxt;
	long long d;
	pqq pq;
	memset(dis, 0x7f, sizeof(dis[0])*(n+5));
	dis[st] = 0;
	pq.emplace(0, st);
	while (pq.size())
	{
		pp now = pq.top();
		pq.pop();
		cur = now.second;
		d = now.first;
		if (dis[cur] != d)
		{
			continue;
		}
		for (i=0; i<v[cur].size(); i++)
		{
			nxt = v[cur][i].first;
			t = v[cur][i].second;
			if (dis[nxt] > d + t)
			{
				dis[nxt] = d + t;
				pq.emplace(d+t, nxt);
			}
		}
	}
}

int main()
{
	int m, i, a, b, c;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			v[a].emplace_back(b, c);
			v[b].emplace_back(a, c);
		}
		dijkstra(1, dis[0]);
		dijkstra(n, dis[1]);
		for (i=1; i<=n; i++)
		{
			printf("%d\n", dis[0][i]+dis[1][i]);
		}
	}
	return 0;
}

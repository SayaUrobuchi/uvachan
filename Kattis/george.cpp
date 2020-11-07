#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1024;

int path[4096];
int w[N][N], px[N][N], py[N][N];
vector<int> v[N];
long long dis[N];

int main()
{
	int n, m, i, t, p, q, st, ed, tmod, o, r, now, nxt;
	long long d;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
			dis[i] = 1e16;
		}
		scanf("%d%d%d%d", &st, &ed, &tmod, &o);
		for (i=0; i<o; i++)
		{
			scanf("%d", &path[i]);
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d%d", &p, &q, &r);
			v[p].emplace_back(q);
			v[q].emplace_back(p);
			w[p][q] = w[q][p] = r;
			px[p][q] = py[p][q] = px[q][p] = py[q][p] = -1;
		}
		for (i=1, t=0; i<o; i++)
		{
			p = path[i-1];
			q = path[i];
			px[p][q] = px[q][p] = t;
			py[p][q] = py[q][p] = t+w[p][q]-1;
			t += w[p][q];
		}
		priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> >> pq;
		dis[st] = tmod;
		pq.push({dis[st], st});
		while (!pq.empty())
		{
			pair<long long, int> cur = pq.top();
			now = cur.second;
			pq.pop();
			if (now == ed)
			{
				break;
			}
			if (dis[now] != cur.first)
			{
				continue;
			}
			for (i=0; i<v[now].size(); i++)
			{
				nxt = v[now][i];
				d = cur.first;
				if (d >= px[now][nxt] && d <= py[now][nxt])
				{
					d = py[now][nxt] + 1;
				}
				if (d + w[now][nxt] < dis[nxt])
				{
					dis[nxt] = d + w[now][nxt];
					pq.push({dis[nxt], nxt});
				}
			}
		}
		printf("%lld\n", dis[ed]-tmod);
	}
	return 0;
}

#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pp = pair<long long, int>;
using pip = pair<int, int>;
using pq_t = priority_queue<pp, vector<pp>, greater<pp> >;

const int N = 1024;

vector<pip> edg[N];
int dp[N];
int tim[N], pos[N], idx[N];

bool comp(int a, int b)
{
	return tim[a] < tim[b];
}

void dijkstra(int st, vector<long long> &dis)
{
	int i;
	dis[st] = 0;
	pq_t pq;
	pq.emplace(0, st);
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
}

int main()
{
	int n, m, o, i, j;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<m; i++)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		edg[a].emplace_back(b, d);
		edg[b].emplace_back(a, d);
	}
	dp[0] = 0;
	pos[0] = 1;
	tim[0] = 0;
	int ans = 0;
	for (i=1; i<=o; i++)
	{
		scanf("%d%d", &pos[i], &tim[i]);
		idx[i] = i;
	}
	sort(idx+1, idx+o+1, comp);
	for (i=1; i<=o; i++)
	{
		int id = idx[i];
		vector<long long> dis(n+1, 1e18);
		dijkstra(pos[id], dis);
		dp[id] = -1;
		for (j=0; j<i; j++)
		{
			int jd = idx[j];
			if (dp[jd] >= 0 && tim[jd] + dis[pos[jd]] <= tim[id])
			{
				dp[id] = max(dp[id], dp[jd] + 1);
			}
		}
		ans = max(ans, dp[id]);
	}
	printf("%d\n", ans);
	return 0;
}
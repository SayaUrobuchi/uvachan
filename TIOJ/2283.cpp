#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<long long, int>;
using pq_t = priority_queue<pp, vector<pp>, greater<pp> >;

const int N = 200005;
const int M = 200005;
const long long INF = 1e18;

bool used[N];
int w[M];
long long dis[M];
vector<int> v[M], rv[N];

inline void update(int cur, long long st, pq_t &pq)
{
	long long res = st + w[cur];
	if (dis[cur] > res)
	{
		dis[cur] = res;
		pq.emplace(res, cur);
	}
}

int main()
{
	int n, m, i, j, siz;
	long long ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &siz, &w[i]);
		v[i].resize(siz);
		for (j=0; j<siz; j++)
		{
			scanf("%d", &v[i][j]);
			rv[ v[i][j] ].emplace_back(i);
		}
	}
	fill(dis, dis+m, INF);
	used[1] = true;
	pq_t pq;
	for (i=0; i<rv[1].size(); i++)
	{
		update(rv[1][i], 0, pq);
	}
	ans = 0;
	while (pq.size())
	{
		int cur;
		long long d;
		tie(d, cur) = pq.top();
		pq.pop();
		if (dis[cur] != d)
		{
			continue;
		}
		for (i=0; i<v[cur].size(); i++)
		{
			int tar = v[cur][i];
			if (!used[tar])
			{
				ans = max(ans, d);
				used[tar] = true;
				for (j=0; j<rv[tar].size(); j++)
				{
					int nxt = rv[tar][j];
					update(nxt, d, pq);
				}
			}
		}
	}
	for (i=1; i<=n; i++)
	{
		if (!used[i])
		{
			ans = -1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using pp = pair<int, int>;
using lpp = pair<long long, int>;

const int N = 100005;
const int M = 11;
const int M2 = (M << 1);

long long dis[N][M];
vector<pp> edg[N];

int main()
{
	int n, m, o, i, j, a, b, c;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		edg[a].emplace_back(b, c);
	}
	for (i=1; i<=n; i++)
	{
		for (j=0; j<o; j++)
		{
			dis[i][j] = 1e18;
		}
	}
	priority_queue<lpp, vector<lpp>, greater<lpp> > pq;
	dis[1][0] = 0;
	pq.emplace(dis[1][0], 1);
	while (!pq.empty())
	{
		long long d;
		int cur;
		tie(d, cur) = pq.top();
		pq.pop();
		if (d > dis[cur][o-1])
		{
			continue;
		}
		for (i=0; i<edg[cur].size(); i++)
		{
			int t, w;
			int cnt;
			tie(t, w) = edg[cur][i];
			long long nd = d + w;
			for (j=o-1; j>=0&&dis[t][j]>nd; j--)
			{
				dis[t][j+1] = dis[t][j];
			}
			if (j+1 < o)
			{
				dis[t][j+1] = nd;
				pq.emplace(nd, t);
			}
		}
	}
	for (i=0; i<o; i++)
	{
		printf("%lld%c", dis[n][i], i==o-1?'\n':' ');
	}
	return 0;
}
